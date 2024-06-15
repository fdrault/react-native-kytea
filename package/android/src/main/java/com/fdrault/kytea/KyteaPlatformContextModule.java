package com.fdrault.kytea;

import com.facebook.react.bridge.ReactApplicationContext;

public class KyteaPlatformContextModule extends NativeKyteaPlatformContextSpec {
    private final ReactApplicationContext context;

    public KyteaPlatformContextModule(ReactApplicationContext reactContext) {
        super(reactContext);
        context = reactContext;
    }

    @Override
    public String getBaseDirectory() {
        return context.getFilesDir().getAbsolutePath() + "/kytea";
    }
}