import { getKyteaTurboModule } from "./NativeKytea";
import { getNativeKyteaPlatformContextTurboModule } from "./NativeKyteaPlatformContext";
const checkImport = () => {
  console.log("react-native-kytea correctly imported");
};

export {
  checkImport,
  getKyteaTurboModule,
  getNativeKyteaPlatformContextTurboModule,
};
