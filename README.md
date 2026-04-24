# GCSLL — GCS Labs Launcher

A lightweight, elegant C++ framework for managing and running laboratory assignments with an interactive menu system. Built with C++23, featuring automatic lab registration, cross-platform support.

## Features

- **Simple lab registration** — Register labs with a macro calls
- **Interactive CUI** — Built-in launcher with formatted console UI
- **No external dependencies** — Implementation uses just standart library
- **Template- and macro-based architecture** — Type-safe, compile-time optimized

## Quick Start

### Prerequisites

- **CMake** 3.28 or later
- **C++ Compiler** with C++23 support (print support required):
  - GCC 14+ (Linux)
  - Clang 18+ (macOS, Linux)
  - MSVC 19.37+ (Visual Studio 2022 17.7)

### Building

**Linux/macOS:**
```bash
./build.sh
```

**Windows:**
```cmd
build.bat
```

**Manual build:**
```bash
cmake -B build -S . --preset=default
cmake --build build
```

### Usage

The similar sample is available [here](./example/sample0)

#### lab.h

```cpp
#ifndef __LAB_H__
#define __LAB_H__

#include <gcsll/gcsll.h>

DECLARE_LAB(lab,
    void task1(int x) const;   // declaring lab tasks
    void task2(const std::string& str) const;
);

#endif
```

#### lab.cpp

```cpp
#include "lab.h"

#include <print>

void lab::task1(int x) const 
{
    std::println(">>> Task 1: Compute square");
    std::println("Square of {} = {}", x, x * x);
}

void lab::task2(const std::string& str) const
{
    std::println(">>> Task 2: String length");
    std::println("Length of '{}' = {}", str, str.length());
}

void lab::execute() const   // what your lab will perform while being executed (inherited from gcsll::labs::lab_base)
{
    this->task1(42);
    this->task2("This is laboratory assignment #1");
}

REG_LAB(lab, "Laboratory assignment #1");   // reg lab to be detected by launcher
```

#### main.cpp

```cpp
#include <gcsll/gcsll.h>

int main()
{
    gcsll::init("Programming languages");   // the discipline name f.e.
    return 0;
}
```

#### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.28)
project(programming_languages)

find_package(gcsll QUIET)
if (NOT gcsll_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        gcsll
        GIT_REPOSITORY https://github.com/Gaymocoder/gcsll.git
        GIT_TAG v1.0.0
    )
    FetchContent_MakeAvailable(gcsll)
endif()

set(lab_lib lab.cpp)
add_library(lab STATIC ${lab_lib})
target_link_libraries(lab PUBLIC gcsll::gcsll)

set(MAIN_EXE src/main.cpp)
add_executable(programming_languages ${MAIN_EXE})
gcsll_link_labs(programming_languages lab) # linking labs for them to be detected by launcher
```

#### Execution

The console execution preview:
```
~~~~~~~~~~~~~~~~~~~~~~~~~
| Programming languages |
~~~~~~~~~~~~~~~~~~~~~~~~~
Choose lab (enter 0 to exit):
1. Laboratory assignment #1

Selected lab number: 
```
```
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| LAB #1. Laboratory assignment #1 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
>>> Task 1: Compute square
Square of 42 = 1764
>>> Task 2: String length
Length of 'This is laboratory assignment #1' = 32

Press Enter to continue...
```

#### Accessing Lab Metadata

```cpp
// During execution
const std::string& current_name = this->name();    // Lab name
const size_t& current_index = this->index();       // Lab index

// From static API
size_t total_labs = gcsll::labs::count();
const auto& lab = gcsll::labs::get(0);
```

## Tested with

- OS: `Ubuntu 24.04.4 LTS (Linux 6.17.0-22-generic)`
- Compilers: `Clang 18.1.3`, `GNU C++ Compiler 14.2.0`
- Build system: `CMake 3.28.3`
