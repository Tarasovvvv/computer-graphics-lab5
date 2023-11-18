cmake_minimum_required(VERSION 3.10)

project(ComputeGraphicsLab5)

set(CMAKE_CXX_STANDARD 11)

add_executable(App ../App/app.cpp)

target_link_libraries(App ../vcpkg/packages/freeglut_x64-windows/debug/lib/freeglutd)

add_custom_command(
	TARGET App
	POST_BUILD
	COMMAND xcopy /s ..\\vcpkg\\packages\\freeglut_x64-windows\\debug\\bin Release)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  TestApp
  ../AppTest/test.cpp
)

target_link_libraries(
  TestApp
  GTest::gtest_main
)

