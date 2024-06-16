require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-kytea"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.homepage     = package["homepage"]
  s.license      = package["license"]
  s.authors      = package["author"]

  s.platforms    = { :ios => min_ios_version_supported }
  s.source       = { :git => "https://github.com/fdrault/react-native-kytea.git", :tag => "#{s.version}" }

  s.source_files = "ios/**/*.{h,m,mm}", "cpp/**/*.{h,cpp}", "kytea/src/**/*.{hpp,cpp,c,h}"
  s.header_mappings_dir = "kytea/src/include"
  s.resource = "data/model.bin"
  s.xcconfig = {
    'GCC_PREPROCESSOR_DEFINITIONS' => 'PKGDATADIR=\\"/data\\"'
  }
  s.pod_target_xcconfig    = {
      "CLANG_CXX_LANGUAGE_STANDARD" => "c++17"
  }
  install_modules_dependencies(s)

end
