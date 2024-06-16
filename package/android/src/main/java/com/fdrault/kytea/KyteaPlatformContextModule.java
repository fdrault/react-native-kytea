package com.fdrault.kytea;

import android.util.Log;
import com.facebook.react.bridge.ReactApplicationContext;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class KyteaPlatformContextModule extends NativeKyteaPlatformContextSpec {
  private final ReactApplicationContext context;
  private static final String TAG = "KyteaPlatformContext";

  public KyteaPlatformContextModule(ReactApplicationContext reactContext) {
    super(reactContext);
    context = reactContext;
  }

  @Override
  public String getModelPath() {
    String modelPath = copyAssetToFile("model.bin");
    if (modelPath != null) {
      Log.i(TAG, "Model path: " + modelPath);
    } else {
      Log.e(TAG, "Failed to get model path");
    }
    return modelPath;
  }

  // Copy asset to make it accessible in the C++ world
  private String copyAssetToFile(String fileName) {
    File outFile = new File(context.getFilesDir(), fileName);

    // Check if the file already exists
    if (outFile.exists()) {
      return outFile.getAbsolutePath();
    }

    // Copy the file from assets to internal storage
    try (InputStream is = context.getAssets().open(fileName);
         FileOutputStream fos = new FileOutputStream(outFile)) {
      byte[] buffer = new byte[1024];
      int length;
      while ((length = is.read(buffer)) > 0) {
        fos.write(buffer, 0, length);
      }
    } catch (IOException e) {
      e.printStackTrace();
      return null;
    }

    return outFile.getAbsolutePath();
  }
}