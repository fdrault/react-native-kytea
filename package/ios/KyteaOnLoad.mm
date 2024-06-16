// On android, we use react-native.config.json to be auto-link
// On iOS, it seems mandatory to load cpp TurboModules like this
// It is quite undocumented, I've been inspired by MMKV from mrousavy
// https://github.com/mrousavy/react-native-mmkv/blob/main/package/ios/MmkvOnLoad.mm

#import "NativeKyteaModule.h"
#import <Foundation/Foundation.h>
#import <ReactCommon/CxxTurboModuleUtils.h>

@interface KyteaOnLoad : NSObject
@end

@implementation KyteaOnLoad

+ (void)load {
  facebook::react::registerCxxModuleToGlobalModuleMap(
      std::string(facebook::react::NativeKyteaModule::kModuleName),
      [&](std::shared_ptr<facebook::react::CallInvoker> jsInvoker) {
        return std::make_shared<facebook::react::NativeKyteaModule>(jsInvoker);
      });
}

@end
