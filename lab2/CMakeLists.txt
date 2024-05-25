cmake_minimum_required(VERSION 3.22)
project(lab2)

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

file(GLOB SOURCES src/*.c)
list(FILTER SOURCES EXCLUDE REGEX "src/main.c")

file(GLOB MAIN_SOURCE src/main.c)
add_executable(lab2 ${MAIN_SOURCE} ${SOURCES})
target_include_directories(lab2 PUBLIC include)

add_executable(GTest test/Gtest.cpp ${SOURCES})
target_include_directories(GTest PUBLIC include)
target_link_libraries(GTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(GTest)
