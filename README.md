# Developing C/C++ on Windows with VS Code

This document explains how to install the tools required to create, compile,
build and run C or C++ projects in a VS Code workspace.

The project names, folder names, executable names and library names used in the
examples are placeholders. Replace them with names chosen for your own
project. In particular, `MyProject` is only an example; it is not a required
folder name.

The recommended environment is:

- **Visual Studio Code**: editor and development environment;
- **MSYS2 UCRT64**: GCC, G++, Make and Unix tools;
- **CMake**: build-system generator;
- the **C/C++** and **CMake Tools** VS Code extensions.

## 1. Install Visual Studio Code

Download and install VS Code from the official website:
<https://code.visualstudio.com/>

During the installation, enabling the options that add VS Code to the `PATH`
and add an **Open with Code** action to the Windows Explorer context menu is
recommended.

## 2. Install GCC with MSYS2

MSYS2 provides a complete and maintained GCC toolchain for Windows. This
workspace uses the **UCRT64** terminal and toolchain.

### Install MSYS2

1. Download MSYS2 from <https://www.msys2.org/>.
2. Install MSYS2 in the suggested directory, preferably:
   `C:\msys64`
3. Open **MSYS2 UCRT64** from the Start menu.
4. Update MSYS2:

   ```bash
   pacman -Syu
   ```

   If the terminal asks you to close it, close it, open **MSYS2 UCRT64**
   again, and run the command again until no additional update is proposed.

5. Install GCC, G++, Make and the development tools:

   ```bash
   pacman -S --needed \
     mingw-w64-ucrt-x86_64-toolchain \
     mingw-w64-ucrt-x86_64-cmake \
     mingw-w64-ucrt-x86_64-ninja
   ```

   Press `Enter` to keep the default choices, then confirm with `Y`.

### Verify the GCC installation

In the **MSYS2 UCRT64** terminal, the following commands should each print a
version:

```bash
gcc --version
g++ --version
make --version
cmake --version
```

The compiler paths used by this workspace are:

```text
C:\msys64\ucrt64\bin\gcc.exe
C:\msys64\ucrt64\bin\g++.exe
```

## 3. Add GCC to the Windows `PATH`

This step makes `gcc`, `g++`, `make` and `cmake` available from PowerShell and
the VS Code integrated terminal.

1. Open the Start menu and search for **Edit the system environment
   variables**.
2. Click **Environment Variables**.
3. Under **User variables**, select `Path` and click **Edit**.
4. Add the following directories:

   ```text
   C:\msys64\ucrt64\bin
   C:\msys64\usr\bin
   ```

5. Confirm all dialogs and restart VS Code.

In a new PowerShell terminal, verify that the executables can be found:

```powershell
gcc --version
g++ --version
make --version
cmake --version
```

If a command is not recognized, check the MSYS2 installation path and restart
the terminal after changing the `PATH`.

## 4. Install the VS Code extensions

In the VS Code **Extensions** view, install:

- **C/C++** (`ms-vscode.cpptools`);
- **C/C++ Extension Pack** (`ms-vscode.cpptools-extension-pack`), optional;
- **CMake Tools** (`ms-vscode.cmake-tools`);
- **CMake Language Support**, optional, for `CMakeLists.txt` syntax
  highlighting.

Then create or select a workspace folder with **File > Open Folder**. You can
choose any location and any name, for example:

```text
C:\<your-personal-path>\<your-Workspace-Name>
```

The workspace folder is the root containing `.vscode` and one or more project
folders. The project folder name is your choice.

## 5. Create `CMakePresets.json`

Create `CMakePresets.json` next to `CMakeLists.txt` in your project folder. In
the examples below, the project folder is called `MyProject`; replace this
name with the name you chose. The preset name `gcc-windows` is also an example:
you may rename it, but use the same name consistently in commands and VS Code
tasks. A preset stores the compiler, generator, build directory and cache
options in one reusable configuration:

```json
{
    "version": 3,
    "configurePresets": [
        {
            "name": "gcc-windows",
            "displayName": "GCC MinGW on Windows",
            "description": "Build with the MSYS2 UCRT64 GCC toolchain",
            "generator": "MinGW Makefiles",
            "binaryDir": "${sourceDir}/build",
            "cacheVariables": {
                "CMAKE_C_COMPILER": "C:/msys64/ucrt64/bin/gcc.exe",
                "CMAKE_CXX_COMPILER": "C:/msys64/ucrt64/bin/g++.exe",
                "CMAKE_BUILD_TYPE": "Debug"
            }
        }
    ],
    "buildPresets": [
        {
            "name": "gcc-windows-debug",
            "configurePreset": "gcc-windows"
        }
    ]
}
```

Important fields:

- `version`: version of the preset format;
- `name`: identifier used by `cmake --preset`;
- `generator`: the build system to generate;
- `binaryDir`: directory containing generated build files;
- `cacheVariables`: CMake variables passed during configuration;
- `buildPresets`: optional shortcuts that reuse a configure preset.

Configure and build with the presets:

```powershell
cd .\MyProject
cmake --preset gcc-windows
cmake --build --preset gcc-windows-debug
```

If the `buildPresets` section is not present, use:

```powershell
cmake --build build
```

To add another configuration, duplicate a preset and change its `name`,
`displayName` and variables. For example, a release preset can use
`"CMAKE_BUILD_TYPE": "Release"`. Delete `MyProject\build` and reconfigure if
the compiler or generator changes.

## 6. Create `CMakeLists.txt`

Create `CMakeLists.txt` at the root of your project folder. This file describes
what CMake must compile and link. A complete minimal C example is shown below.
In this example, `my_application` is the project and executable name; replace
it with the name you choose. The `src`, `include` and `bin` folder names are
also conventions, not requirements; change the paths if you choose different
names.

```cmake
cmake_minimum_required(VERSION 3.16)

project(my_application VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin
)

add_executable(my_application
    src/main.c
)

target_include_directories(my_application PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_options(my_application PRIVATE
    -Wall
    -Wextra
    -g
)
```

What each command does:

- `cmake_minimum_required`: sets the minimum supported CMake version;
- `project`: sets the project name, version and languages;
- `set(CMAKE_C_STANDARD ...)`: requires C11;
- `add_executable`: lists all `.c` files used to create the executable;
- `target_include_directories`: adds directories searched for project headers;
- `CMAKE_RUNTIME_OUTPUT_DIRECTORY`: places the `.exe` in `bin`;
- `target_compile_options`: enables warnings and debug information.

`CMAKE_RUNTIME_OUTPUT_DIRECTORY` is set before `add_executable` so that CMake
uses it when it initializes the executable target. It can also be set after
the target is created with `set_target_properties`.

Add every source file to `add_executable`. A header file usually does not need
to be listed there, but its directory must be provided with
`target_include_directories`. Include a header in C with (replace `functions.h` with your own header name):

```c
#include "functions.h"
```

For a C++ project, use `project(my_application LANGUAGES CXX)`, list `.cpp`
files, use `CMAKE_CXX_STANDARD`, and use `g++` in the preset.

## 7. Link a DLL library

On Windows, linking a DLL normally requires three things:

1. the header files containing the public declarations;
2. the DLL file used at runtime;
3. an import library (`.lib` for MSVC or `.dll.a` for MinGW) used at link time.

A typical third-party library layout is:

```text
MyProject/
├── CMakeLists.txt
├── CMakePresets.json
├── third_party/
│   └── example/
│       ├── include/
│       │   └── example.h
│       ├── lib/
│       │   └── libexample.dll.a
│       └── bin/
│           └── example.dll
├── bin/                 # my_application.exe and copied runtime DLL
└── src/
    └── main.c
```

Add an imported library target to `CMakeLists.txt`:

```cmake
add_library(example SHARED IMPORTED)

set_target_properties(example PROPERTIES
    IMPORTED_IMPLIB
        "${CMAKE_SOURCE_DIR}/third_party/example/lib/libexample.dll.a"
    IMPORTED_LOCATION
        "${CMAKE_SOURCE_DIR}/third_party/example/bin/example.dll"
    INTERFACE_INCLUDE_DIRECTORIES
        "${CMAKE_SOURCE_DIR}/third_party/example/include"
)

target_link_libraries(my_application PRIVATE example)
```

The important commands are:

- `add_library(... SHARED IMPORTED)`: declares a prebuilt DLL;
- `IMPORTED_IMPLIB`: points to the MinGW import library used by the linker;
- `IMPORTED_LOCATION`: points to the DLL needed when the program runs;
- `INTERFACE_INCLUDE_DIRECTORIES`: makes the library headers available;
- `target_link_libraries`: links the library to the executable.

If the library provides a `.lib` file generated for MinGW-compatible linking,
use that file in `IMPORTED_IMPLIB` instead. Do not put only the `.dll` in
`target_link_libraries`: the linker needs the import library.

The DLL must be next to the executable or in a directory listed in the
Windows `PATH`. To copy it automatically next to the executable after each
build, add:

```cmake
add_custom_command(TARGET my_application POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/third_party/example/bin/example.dll"
        "$<TARGET_FILE_DIR:my_application>/example.dll"
)
```

If a library only provides a DLL and no import library, it cannot be linked
normally with `target_link_libraries`. Use the library's Windows import-library
generation instructions, or load it dynamically with the Windows API
(`LoadLibrary` and `GetProcAddress`) and declare the function pointers in the
application.

After adding a library, configure and rebuild:

```powershell
cmake --preset gcc-windows
cmake --build build
.\bin\my_application.exe
```

### Optional: use the Windows SDK and system DLLs

For a larger Windows project, it is useful to distinguish the files needed to
**build** the program from the DLLs needed to **run** it.

The Windows SDK is a development kit installed on the developer's machine. It
provides, among other things:

- header files such as `windows.h`;
- import libraries such as `user32.lib` for MSVC;
- tools and declarations for Windows APIs.

With MinGW, the equivalent headers and import libraries are normally supplied
by the MinGW-w64 toolchain installed through MSYS2. For example, the following
program uses the Windows API:

```c
#include <windows.h>

int main(void)
{
    MessageBoxA(NULL, "Hello", "Test", MB_OK);
    return 0;
}
```

The corresponding CMake configuration is:

```cmake
add_executable(my_application
    src/main.c
)

target_link_libraries(my_application PRIVATE
    user32
)
```

At link time, MinGW uses an import library such as `libuser32.a` (or
`user32.lib` with MSVC). This file does not contain the complete implementation
of the DLL. It records that the functions are provided by `user32.dll`.
When the program starts, Windows loads the system copy of `user32.dll`, usually
from `C:\Windows\System32`, and connects the imported functions.

The SDK files and import libraries are therefore only development dependencies.
They are not copied to `bin` and are not distributed with the application:

```text
Developer machine:
    Windows SDK or MinGW-w64
    ├── windows.h
    └── import libraries

Distributed application:
    bin\
    └── my_application.exe  --->  user32.dll supplied by Windows
```

Do not copy or redistribute system DLLs such as `user32.dll`, `kernel32.dll` or
`gdi32.dll` with the application. Link against the SDK import library and let
the supported version of Windows provide the DLL. If an API is unavailable on
an older version of Windows, the application must either require a suitable
Windows version or check for that API at runtime.

This differs from a third-party DLL such as SDL, OpenAL or Vulkan. Those DLLs
are not guaranteed to be installed on every machine, so the installer usually
places them next to the executable. The same applies to a DLL created by the
project itself. A typical large-project layout is:

```text
MyProject/
├── bin/
│   ├── my_application.exe
│   └── third_party.dll
├── include/
├── src/
└── third_party/
    ├── include/
    ├── lib/       # import libraries used at link time
    └── bin/       # DLLs used at runtime
```

The Visual C++ runtime is a separate case. If the application is built with
MSVC and uses the dynamic runtime, install the matching official Microsoft
Visual C++ Redistributable rather than copying random runtime DLLs from the
development computer.

## 8. Build the project with CMake

From a PowerShell terminal opened in your project directory, for example
`MyProject`, run:

```powershell
cmake --preset gcc-windows
cmake --build build
```

The same operations are available in VS Code through the **CMake Tools**
extension:

1. select the `gcc-windows` preset;
2. click **Configure**;
3. click **Build**.

With the current configuration, the executable is generated at:

```text
MyProject\bin\my_application.exe
```

Run it from PowerShell with:

```powershell
.\bin\my_application.exe
```

### Build with Make directly

When the `MinGW Makefiles` generator is used, CMake generates a Makefile in
the `build` directory. You can then call Make directly instead of using
`cmake --build`:

```powershell
cmake --preset gcc-windows
make -C build
```

The first command is still required after creating the project or changing
the CMake configuration. It generates or updates the Makefile. The second
command asks Make to use that Makefile.

You can also run Make from inside the build directory:

```powershell
cd .\build
make
cd ..
```

With MSYS2, the executable may also be available under the name
`mingw32-make`. The equivalent command is:

```powershell
mingw32-make -C build
```

Make does not choose the output directory. CMake does that through
`CMAKE_RUNTIME_OUTPUT_DIRECTORY` in `CMakeLists.txt`. Therefore, if that
variable points to `bin`, the executable is still generated in:

```text
MyProject\bin\my_application.exe
```

For a normal build, prefer:

```powershell
cmake --build build
```

It selects the correct underlying build tool automatically. Use `make -C build`
when you specifically want to interact with the generated Makefile.

## 9. Quickly compile a C file

For a project containing multiple files, prefer CMake over an isolated GCC
command. For a single source file, compile manually:

```powershell
gcc -Wall -Wextra -g .\src\main.c -o .\main.exe
.\main.exe
```

## 10. Debug a program

The **C/C++** extension lets you start the debugger with `F5`. If VS Code asks
you to choose a compiler, select:

```text
GCC (MSYS2 UCRT64)
```

Place breakpoints by clicking to the left of the line numbers, then start the
program with **Run and Debug**.

## 11. Troubleshooting

### `gcc` or `cmake` is not recognized

- check that `C:\msys64\ucrt64\bin` is in the `PATH`;
- close and reopen the VS Code integrated terminal;
- check that MSYS2 was installed in `C:\msys64`.

### CMake uses the wrong compiler

Delete the `MyProject\build` directory, select the `gcc-windows` preset, and
configure the project again. The preset uses these compiler paths:

```text
C:/msys64/ucrt64/bin/gcc.exe
C:/msys64/ucrt64/bin/g++.exe
```

### The `MinGW Makefiles` generator is unavailable

Check that `mingw-w64-ucrt-x86_64-cmake` and the UCRT64 toolchain were installed
from the MSYS2 UCRT64 terminal. Close and reopen VS Code after changing the
`PATH`.

## 12. Final verification

The installation is complete when the following commands work in a new
PowerShell terminal:

```powershell
gcc --version
g++ --version
make --version
cmake --version
```

The project should also build and run with:

```powershell
cd .\MyProject
cmake --preset gcc-windows
cmake --build build
.\bin\my_application.exe
```

## 13. Optional: VS Code files for a single C file

The `.vscode\settings.json` and `.vscode\tasks.json` files are optional. They
are not required for a CMake project: CMake already knows which source files,
headers, compiler options and libraries must be built. For a normal project,
use `CMakeLists.txt`, `CMakePresets.json` and the CMake Tools **Configure** and
**Build** commands.

These VS Code files can be useful for a very simple exercise containing only
one standalone C file, with no project headers, no additional source files,
and no external libraries.

Create the files from the workspace root:

```powershell
New-Item -ItemType Directory -Force .vscode
New-Item -ItemType File -Force .vscode\settings.json
New-Item -ItemType File -Force .vscode\tasks.json
```

An example `settings.json` is:

```json
{
    "C_Cpp.default.compilerPath": "C:/msys64/ucrt64/bin/gcc.exe",
    "C_Cpp.default.cStandard": "c11"
}
```

An example `tasks.json` that compiles the currently open file is:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C: build active file",
            "command": "C:\\msys64\\ucrt64\\bin\\gcc.exe",
            "args": [
                "-Wall",
                "-Wextra",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Open the C file and run **Terminal > Run Build Task** or press
`Ctrl+Shift+B`. The executable is created next to the source file.

> **Warning:** this shortcut only compiles the active C file. It does not
> automatically compile other source files, add project header directories,
> link libraries or copy DLL files. Do not use it as the build system for a
> real multi-file project. As soon as the project has headers, several `.c` or
> `.cpp` files, external libraries or DLL dependencies, use CMake instead.
