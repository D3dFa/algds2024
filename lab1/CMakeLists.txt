cmake_minimum_required(VERSION 3.22)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lab1
    src/main.c
    src/dp.c
)
target_include_directories(lab1 PUBLIC include)

add_dependencies(lab1 GTest)

add_executable(
  GTest
  test/Gtest.cpp
  src/dp.c
)
target_include_directories(GTest PUBLIC include)

target_link_libraries(
  GTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GTest)
