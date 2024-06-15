#include "NativeKyteaModule.h"
#include <string>

namespace facebook::react {

NativeKyteaModule::NativeKyteaModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeKyteaCxxSpec(jsInvoker) {}


NativeKyteaModule::~NativeKyteaModule() {}

jsi::String NativeKyteaModule::tokenize(jsi::Runtime &runtime, jsi::String input)
{
    std::string value = input.utf8(runtime);
    std::string repeated = value + value;
    return jsi::String::createFromUtf8(runtime, repeated);
}

} // namespace facebook::react
