import {TurboModule, TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  readonly tokenize: (input: string) => string;
}

export default TurboModuleRegistry.getEnforcing<Spec>('Kytea');
