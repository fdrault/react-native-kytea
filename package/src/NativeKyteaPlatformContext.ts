import type { TurboModule } from "react-native";
import { TurboModuleRegistry } from "react-native";

export interface Spec extends TurboModule {
  /**
   * Gets the path of Kytea model binary
   */
  getModelPath(): string;
}

let module: Spec | null;

export function getNativeKyteaPlatformContextTurboModule(): Spec {
  try {
    if (module == null) {
      // 1. Get the TurboModule
      module = TurboModuleRegistry.getEnforcing<Spec>("KyteaPlatformContext");
    }
    return module;
  } catch (e) {
    // TurboModule could not be found!
    console.warn(e);
    throw new Error("KyteaPlatformContextTurboModule could not be found!");
  }
}
