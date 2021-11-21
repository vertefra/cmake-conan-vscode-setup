# C++, Conan CMake Project setup for VSCode

This is very likely subject to change and not something definitive at all, and it could very well not work for a lot of reasons. 

It's more a reminder on how I reached this point.

## What you need

On your system:
- Python 3.6 or greater
- cmake 3.16.3
- GCC 9.3

On VsCode:
- C++ Microsoft extension
- Cmake extension
- Cmake-tools extension

## How does this work?

The idea is that, VSCode, through `Cmake-tools`, will read the configuration from `CMakeLists.txt` and will build the executables.

## Setting up Cmake-tools

- `Cmake: Select a kit` -> `GCC 9.3.x ..`
- `Cmake: Select a variant` -> `Debug`
- `Cmake: Configure`

This will create all the configuration files in a `build/` folder.

## Installing packages with Conan

Setup a Python virtual environment and install `conan`

```
python -m .venv venv
source .venv/bin/activate
pip install conan
```
You can search for packages with conan
```
conan search opengl
Existing package recipes:

opengl/system
```

Add the package in `conanfile.txt` under required

From inside the `build/` folder:

```
conan install ..
```

Files are actually downloaded in your home directory under `~/.conan/data`
and linked through 

```
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
```

Your CMakeLists.txt will reference `conanbuildinfo.cmake` in the vendors folder

## Run with VSCode

You should be able to build your project selecting `build` from the bottom bar, and eventually change variant still using the bottom bar.

## Project structure:

All the headers of custom classes will be found in `/src/include/` folder, while their implementation will be in `lib`

Any suggestion on how to improve this setup will be more that welcome.

