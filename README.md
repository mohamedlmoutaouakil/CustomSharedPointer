# CustomSharedPointer

This project is a simple version non threadsafe of the smart pointer shared_ptr of C++ STL library.

## Getting Started

Here are the following instructions to get a copy of the project up and running on your local machine for development and testing.

### Build Process

CMake was used in the development of the prject, it is used to control the software compilation process using simple platform and compiler independent configuration files, and generate native makefiles and workspaces (Unix Makefiles, Visual Studio Projects...) that can be used in the compiler environment of your choice.

### Prerequisites

You should install CMake https://cmake.org/.

### Unix environment

Clone the repository on your local machine.

Generate Makefiles:

1. Create a build folder inside the repository, this folder will contain the envirenment specific build files (Unix Makefiles in this case).
2. Inside the build folder run the following command to generate  the Makefiles (Debug):
    ```
    cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
    ```
3. To build the project just run (inside the build folder):
    ```
    make
    ```

### Windows

Clone the repository on your local machine.

Generate Visual Studio Project:

1. Create a build folder inside the repository, this folder will contain the envirenment specific build files (Visual Studio Project files in this case).
2. Inside the build folder created run (Depending on Visual Studio version):
    ```
    cmake -G "Visual Studio 15 2017" ..
    ```
3. To build the project just open the generated solution and build it on Visual Studio.

### Running the tests

Googletest framework was used for unit testing.

Either using ctest inside the build folder, run:

```
ctest
```

Or directly using unit_tests:
1. Windows:

    ```
    .\test\Debug\unit_tests.exe
    ```
2. Unix:

    ```
    ./bin/unit_tests
    ```