import { TurboModule, TurboModuleRegistry } from "react-native";

export interface Spec extends TurboModule {
  readonly tokenize: (input: string) => string;
}

let module: Spec | null;
export function getKyteaTurboModule(): Spec {
  if (module == null) {
    module = TurboModuleRegistry.getEnforcing<Spec>("Kytea");
  }
  return module;
}
