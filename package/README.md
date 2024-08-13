# react-native-kytea

Word Segmentation and tagging for japanese using Kytea.

This package provides binding for react-native of the [Kyoto Text Analysis Toolkit (kytea)](https://www.phontron.com/kytea/)

### Installation

`npm install react-native-kytea`

For iOS: `cd ios && RCT_NEW_ARCH_ENABLED=1 pod install`

### Compatibility

**New architecture only**. Compatible Android and iOS.

On Android, your application required to have `newArchEnabled=true`in `gradle.properties`

On iOS, you have to install pods using `RCT_NEW_ARCH_ENABLED=1 pod install` or `RCT_NEW_ARCH_ENABLED=1 bundle exec pod install`

️🚧️️️ Because it contains a trained model, this package is quite heavy on mobile.

### Usage

```ts
import { getKyteaTurboModule } from "react-native-kytea";
const Kytea = getKyteaTurboModule();
Kytea.tokenize("これはテストです。");
```

### License

The model is licensed under the [Creative Commons Attribution-Share Alike 3.0 License](http://creativecommons.org/licenses/by-sa/3.0/).

The Kytea is licensed under the [Apache License Version 2](http://www.apache.org/licenses/LICENSE-2.0)

This package, react-native-kytea is licensed under [Apache License Version 2](http://www.apache.org/licenses/LICENSE-2.0)

I have no affliation with developpers and contributors of [kytea](https://www.phontron.com/kytea/). If there is any issue with license, please contact me or post an issue.
