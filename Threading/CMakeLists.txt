cmake_minimum_required(VERSION 3.1)

message("Setting C++ Standard")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build with one shared lib" ON)
option(BUILD_STATIC_LIBS "Build with one shared lib" ON)

project(THREADING LANGUAGES CXX)

add_executable(
binary
${CMAKE_SOURCE_DIR}/src/Threading.cpp
)

target_include_directories(binary PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# add_library(static_feature STATIC src/slib/feature_static.cpp)
# target_include_directories(static_feature PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# add_library(dynamic_feature SHARED src/dlib/feature_dynamic.cpp)
# target_include_directories(dynamic_feature PRIVATE ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(binary PUBLIC pthread)
