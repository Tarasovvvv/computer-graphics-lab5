# Computer graphics 5th lab

[![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/tarasovvvv/computer-graphics-lab5/.github/workflows/build_test_workflow.yml)](https://github.com/Tarasovvvv/computer-graphics-lab5/actions)
[![Guthub repo size](https://img.shields.io/github/repo-size/Tarasovvvv/computer-graphics-lab5)](https://github.com/Tarasovvvv/computer-graphics-lab5)
[![GitHub release (with filter)](https://img.shields.io/github/v/release/Tarasovvvv/computer-graphics-lab5)](https://github.com/Tarasovvvv/computer-graphics-lab5/releases)
[![GitHub license](https://img.shields.io/github/license/tarasovvvv/computer-graphics-lab5)](https://github.com/Tarasovvvv/computer-graphics-lab5/blob/main/LICENSE)

## Content

- [Intro](#intro)
- [Requirements](#requirements)
- [Installation](#installation)
- [Running the app](#running-the-app)
- [Used packages](#used-packages)
- [Debug and release with Microsoft Visual Studio 2022](#debug-and-release-with-microsoft-visual-studio-2022)

## Intro

The project was written as part of the Computer Graphics laboratory work.  
It's demonstrates the animation of a cone, the base of which flows smoothly into the top, and vice versa, and the color changes periodically.  
Below is the interface of the application.
<p align="center">
  <img src=preview.gif width = "830px">
</p>

## Requirements

- OS Windows 11 with 64-bit architecture

## Installation

Clone the repository

    git clone https://github.com/tarasovvvv/computer-graphics-lab5.git

## Running the app

To run the application, you need to move into the project directory and run the following scripts in the terminal:

Clone and install the Visual C++ Packaging Tool

    git clone https://github.com/Microsoft/vcpkg.git

Run the bootstrap script to build vcpkg

    .\vcpkg\bootstrap-vcpkg.bat

Install the necessary libraries

    .\vcpkg\vcpkg.exe install cppzmq freeglut

Move to the CMake build directoty 

    cd Build

Copy the freeglut.lib in for compile

    copy ..\vcpkg\packages\freeglut_x64-windows\lib\freeglut.lib .

Generate building files for CMake

    cmake .

Build the application and the test

    cmake --build . --config Release

Now you are able to run new executables:

Application

    .\Release\App.exe

Tests

    .\Release\TestApp.exe

## Used packages

[Vcpkg](https://github.com/microsoft/vcpkg) was used for installing the packages:
- [Cmake](https://github.com/zeromq/cppzmq) was used for compiling and building.  
- [Freeglut](https://github.com/FreeGLUTProject/freeglut) - OpenGL Utility Toolkit was used for drawing.  
- [Google test](https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip) was used for testing.

## Debug and release with Microsoft Visual Studio 2022

Before debug and release you need to copy freeglut libs and dlls to App directory:

freeglut.lib for compile release 

    copy vcpkg\packages\freeglut_x64-windows\lib\freeglut.lib App  

freeglut.dll for build release 
    
    copy vcpkg\packages\freeglut_x64-windows\bin\freeglut.dll App

freeglutd.lib for compile debug 

    copy vcpkg\packages\freeglut_x64-windows\debug\lib\freeglutd.lib App

freeglutd.dll for build debug 
    
    copy vcpkg\packages\freeglut_x64-windows\debug\bin\freeglutd.dll App