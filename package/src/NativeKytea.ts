import { TurboModule, TurboModuleRegistry } from "react-native";
import { getNativeKyteaPlatformContextTurboModule } from "./NativeKyteaPlatformContext";

export interface Spec extends TurboModule {
  initialize: (modelFilePath: string) => boolean;
  readonly tokenize: (input: string) => string;
}

let module: Spec | null;
export function getKyteaTurboModule(): Spec {
  const modelPath = getNativeKyteaPlatformContextTurboModule().getModelPath();
  if (module == null) {
    module = TurboModuleRegistry.getEnforcing<Spec>("Kytea");
    const initialized = module.initialize(modelPath);
    console.log("Kytea initialized ", initialized);
  }
  return module;
}
