# Computer graphics 5th lab

[![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/tarasovvvv/computer-graphics-lab5/.github/workflows/build_test_workflow.yml)](https://github.com/Tarasovvvv/computer-graphics-lab5/actions)
[![Guthub repo size](https://img.shields.io/github/repo-size/Tarasovvvv/computer-graphics-lab5)](https://github.com/Tarasovvvv/computer-graphics-lab5)
[![GitHub release (with filter)](https://img.shields.io/github/v/release/Tarasovvvv/computer-graphics-lab5)](https://github.com/Tarasovvvv/computer-graphics-lab5/releases/tag/v0.0.1)

## Content

- [Intro](#intro)
- [Requirements](#requirements)
- [Installation](#installation)
- [Running the app](#running-the-app)
- [Used packages](#used-packages)

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

To run the application, you need to move into the project directory and run the following script in the terminal:

    .\x64\Release\computer-graphics-lab5.exe

And for the tests:

    .\x64\Release\Sample-Test1.exe

## Used packages

[Vcpkg](https://github.com/microsoft/vcpkg) was used for installing the packages.  
[Freeglut](https://github.com/FreeGLUTProject/freeglut) - OpenGL Utility Toolkit for drawing.  
[Google test](https://github.com/google/googletest) used for testing.
