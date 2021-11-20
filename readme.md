# C++, Conan CMake Project setup for VSCode

This is very likely subject to change and not something definitive at all, and could very well not work for a lot of reasons. 

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

## How does this works?

The idea is that, VSCode will read the configuration from `CMakeLists.txt` and will build through GCC the executables. I still need to figure it out how to set the build targets to better paths rather than all together in `build/` folder.

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

Add a `vendors/`folder and `cd` into it.

From here run

```
conan install ..
```

Files are actually downloaded in your home directory under `~/.conan/data`

Your CMakeLists.txt will reference `conanbuildinfo.cmake` in the vendors folder

## Run with VSCode


**Select a Kit**

From command palette (`shift + ctrl + P`) 
select `CMake: Select a kit`
select `GCC 9.3`

**Select a variant**

From command palette (`shift + ctrl + P`) 
select `CMake: Select a variant`
select `Debug`

You should now be able to build your project selecting `build` from the bottom bar, and eventually change variant still using the bottom bar.

## Project structure:

All the headers of custom classes will be found in `include/` folder, while their implementation will be in `lib`

Any suggestion on how to improve this setup will be more that welcome.

