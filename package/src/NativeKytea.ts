import { TurboModule, TurboModuleRegistry } from "react-native";
import { getNativeKyteaPlatformContextTurboModule } from "./NativeKyteaPlatformContext";

export interface Spec extends TurboModule {
  initialize: (modelFilePath: string) => boolean;
  readonly tokenize: (input: string) => Word[];
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

export interface Word {
  surface: string;
  norm: string;
  tags: Tag[];
  sound: Tag[];
  isCertain: boolean;
  unknown: boolean;
}

export interface Tag {
  value: string;
  score: number;
}
