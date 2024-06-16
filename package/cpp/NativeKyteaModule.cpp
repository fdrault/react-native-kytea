#include "NativeKyteaModule.h"

#include <kytea/kytea-config.h>
#include <kytea/kytea.h>
#include <kytea/string-util.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace kytea;

namespace facebook::react {

NativeKyteaModule::NativeKyteaModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeKyteaCxxSpec(jsInvoker) {}

NativeKyteaModule::~NativeKyteaModule() {}

jsi::String NativeKyteaModule::tokenize(jsi::Runtime &runtime,
                                        jsi::String input) {
  std::string input_string = input.utf8(runtime);
  Kytea kytea;
     

  // Load a KyTea model from a model file
  //  this can be a binary or text model in any character encoding,
  //  it will be detected automatically
  kytea.readModel(modelPath.c_str());

  // Get the string utility class. This allows you to convert from
  //  the appropriate string encoding to Kytea's internal format
  StringUtil *util = kytea.getStringUtil();

  // Get the configuration class, this allows you to read or set the
  //  configuration for the analysis
  KyteaConfig *config = kytea.getConfig();

  // Map a plain text string to a KyteaString, and create a sentence object
  KyteaString surface_string = util->mapString(input_string);
  KyteaSentence sentence(surface_string, util->normalize(surface_string));

  // Find the word boundaries
  kytea.calculateWS(sentence);
  // Find the pronunciations for each tag level
  for (int i = 0; i < config->getNumTags(); i++)
    kytea.calculateTags(sentence, i);

  // For each word in the sentence
  const KyteaSentence::Words &words = sentence.words;

  std::stringstream output; // Create a stringstream object

  for (int i = 0; i < (int)words.size(); i++) {
    // Append the word to the stringstream
    output << util->showString(words[i].surface);
    // For each tag level
    for (int j = 0; j < (int)words[i].tags.size(); j++) {
      output << "\t";
      // Append each of its tags to the stringstream
      for (int k = 0; k < (int)words[i].tags[j].size(); k++) {
        output << " " << util->showString(words[i].tags[j][k].first) << "/"
               << words[i].tags[j][k].second;
      }
    }
    output << "\n";
  }
  output << "\n";

  std::string result = output.str(); // Convert the stringstream to a string

  return jsi::String::createFromUtf8(runtime, result);
}

bool NativeKyteaModule::initialize(jsi::Runtime &runtime,
                                   std::string filepath) {
  modelPath = filepath;
  return true;
}

} // namespace facebook::react
