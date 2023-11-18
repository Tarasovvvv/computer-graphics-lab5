# Changelog

All notable changes to this project will be documented in this file.  
The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres
to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.0.1] - 2023-11-06

### Added

- LICENSE
- CHANGELOG

## [0.0.1] - 2023-11-07

### Added

- [Vcpkg](https://vcpkg.io/en/index.html) for downloading and installing packages
- [Freeglut](https://freeglut.sourceforge.net) package using vcpkg

## [0.0.1] - 2023-11-07

### Added

- Function for diplaying the cone 

### Fixed 

- CHANGELOG.md

## [0.0.1] - 2023-11-07

### Added

- Function for drawing an animation of a cone, the base of which turns into a vertex, and the color changes smoothly

### Fixed 

- CHANGELOG.md

## [0.0.1] - 2023-11-07

### Added

- Tests
- Build artifacts of computer-graphics-lab5.sln and Sample-Test1.sln
- README.md

## [1.0.0] - 2023-11-18

### Added

- ./.gitignore
- ./.github/workflows/build-and-test-workflow.yml - workflow for build and test
- ./Build/CMakeLists.txt for determine how to compile and build the project
- _USE_MATH_DEFINES in ./App/app.cpp for define the pi
- Costants in ./App/app.cpp and descriptions for them

### Fixed

- Build and testing method: now you need to run a cmake script to build application and test executables
- Descriptions for functions and constants in ./App/app.cpp

### Changed

- README.md: added info about how to build with CMake and debug and release the project in Visual Studio 2022
- Names of inner projects ./computer-graphics-lab5 to ./App and ./Sample-Test1 to ./TestApp(all files in those projects reformated accordingly) according to the CamelCase
- Name of ./computer-graphics-lab5.sln to ./ComputerGraphicsLab5.sln according to the CamelCase
- Including in ./App/app.cpp from ".\GL\freeglut.h" "..\vcpkg\packages\freeglut_x64-windows\include\GL\freeglut.h"

### Removed

- Directions and files listed in new ./.gitignore
