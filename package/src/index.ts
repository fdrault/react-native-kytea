import { getKyteaTurboModule } from "./NativeKytea";
import { getNativeKyteaPlatformContextTurboModule } from "./NativeKyteaPlatformContext";
const checkImport = () => {
  console.log("react-native-kytea correctly imported");
};
console.log("react-native-kytea global import");

export {
  checkImport,
  getKyteaTurboModule,
  getNativeKyteaPlatformContextTurboModule,
};
