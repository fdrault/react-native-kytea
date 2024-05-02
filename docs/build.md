# Building Instructions

The KyTea project originally used Automake as its build system. However, for react-native-kytea, we've adopted CMake as the default build system for increased flexibility and compatibility.

To build kytea using CMake, follow these steps:

```bash
cd package/build
cmake ../cmake
make
```

That's it! You should now have a built version of kytea ready to use.
