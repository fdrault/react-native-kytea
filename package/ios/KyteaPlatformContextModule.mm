#import "KyteaPlatformContext.h"
#import <Foundation/Foundation.h>

@implementation KyteaPlatformContext

RCT_EXPORT_MODULE()

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params {
  return std::make_shared<facebook::react::NativeKyteaPlatformContextSpecJSI>(
      params);
}

- (NSString *)getModelPath {
  NSBundle *mainBundle = [NSBundle mainBundle];
  // Get the path for the resource file "model.bin" included by the podspec
  NSString *modelPath = [mainBundle pathForResource:@"model" ofType:@"bin"];
  return modelPath ? modelPath : @"";
}
@end