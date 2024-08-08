#include "NativeKyteaModule.h"

#include <iostream>
#include <kytea/kytea-config.h>
#include <kytea/kytea.h>
#include <kytea/string-util.h>
#include <sstream>
#include <string>

using namespace kytea;

namespace facebook::react {

NativeKyteaModule::NativeKyteaModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeKyteaCxxSpec(jsInvoker) {}

NativeKyteaModule::~NativeKyteaModule() {}

jsi::Array NativeKyteaModule::tokenize(jsi::Runtime &runtime,
                                       jsi::String input) {
  std::string input_string = input.utf8(runtime);

  StringUtil *util = kytea.getStringUtil();
  KyteaConfig *config = kytea.getConfig();

  KyteaString surface_string = util->mapString(input_string);
  KyteaSentence sentence(surface_string, util->normalize(surface_string));

  kytea.calculateWS(sentence);
  for (int i = 0; i < config->getNumTags(); i++)
    kytea.calculateTags(sentence, i);

  const KyteaSentence::Words &words = sentence.words;

  jsi::Array result(runtime, words.size());
  for (size_t i = 0; i < words.size(); ++i) {
    const auto &kyteaWord = words[i];
    jsi::Object wordObj(runtime);

    wordObj.setProperty(runtime, "surface",
                        jsi::String::createFromUtf8(
                            runtime, util->showString(kyteaWord.surface)));
    wordObj.setProperty(
        runtime, "norm",
        jsi::String::createFromUtf8(runtime, util->showString(kyteaWord.norm)));

    jsi::Array tagsArray(runtime, kyteaWord.tags[0].size());
    for (size_t j = 0; j < kyteaWord.tags[0].size(); ++j) {
      jsi::Object tagObj(runtime);
      tagObj.setProperty(
          runtime, "value",
          jsi::String::createFromUtf8(
              runtime, util->showString(kyteaWord.tags[0][j].first)));
      tagObj.setProperty(runtime, "score",
                         jsi::Value(kyteaWord.tags[0][j].second));
      tagsArray.setValueAtIndex(runtime, j, tagObj);
    }
    wordObj.setProperty(runtime, "tags", tagsArray);

    jsi::Array soundArray(runtime, kyteaWord.tags[1].size());
    for (size_t k = 0; k < kyteaWord.tags[1].size(); ++k) {
      jsi::Object soundObj(runtime);
      soundObj.setProperty(
          runtime, "value",
          jsi::String::createFromUtf8(
              runtime, util->showString(kyteaWord.tags[1][k].first)));
      soundObj.setProperty(runtime, "score",
                           jsi::Value(kyteaWord.tags[1][k].second));
      soundArray.setValueAtIndex(runtime, k, soundObj);
    }
    wordObj.setProperty(runtime, "sound", soundArray);

    wordObj.setProperty(runtime, "isCertain", jsi::Value(kyteaWord.isCertain));
    wordObj.setProperty(runtime, "unknown", jsi::Value(kyteaWord.unknown));

    result.setValueAtIndex(runtime, i, wordObj);
  }

  return result;
}

bool NativeKyteaModule::initialize(jsi::Runtime &runtime,
                                   std::string filepath) {
  modelPath = filepath;

  // Load a KyTea model from a model file
  //  this can be a binary or text model in any character encoding,
  //  it will be detected automatically
  kytea.readModel(modelPath.c_str());
  return true;
}

} // namespace facebook::react
