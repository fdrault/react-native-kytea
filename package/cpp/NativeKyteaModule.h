
#pragma once

// Cross-Platform Turbo Native Modules with C++
// https://github.com/reactwg/react-native-new-architecture/blob/main/docs/turbo-modules-xplat.md

#if __has_include(<React-Codegen/KyteaSpecJSI.h>)
// CocoaPods include (iOS)
#include <React-Codegen/KyteaSpecJSI.h>
#elif __has_include(<KyteaSpecJSI.h>)
// CMake include on Android
#include <KyteaSpecJSI.h>
#else
#error Cannot find react-native-kytea spec! Try cleaning your cache and re-running CodeGen!
#endif

#include <iostream>
#include <kytea/kytea.h>
#include <string>

namespace facebook::react {

// The TurboModule itself
class NativeKyteaModule : public NativeKyteaCxxSpec<NativeKyteaModule> {
public:
  NativeKyteaModule(std::shared_ptr<CallInvoker> jsInvoker);
  ~NativeKyteaModule();

  jsi::Array tokenize(jsi::Runtime &runtime, jsi::String input);

  bool initialize(jsi::Runtime &runtime, std::string filepath);

private:
  std::string modelPath;
  kytea::Kytea kytea;
};

} // namespace facebook::react
