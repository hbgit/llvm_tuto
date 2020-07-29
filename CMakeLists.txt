# export LLVM_HOME=/usr/lib/llvm-8/
# mkdir build
# cp build
# cmake .. -DCMAKE_INSTALL_PREFIX=../release/
# make
# make install
# --------------------
# To Clangd vscode plugin
# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1  ..
# cp compile_commands.json ..


cmake_minimum_required(VERSION 3.5)

project(AddAlloca)

set (CMAKE_CXX_STANDARD 11)

# BUG: If we do not set this flag opt will not work with our pass
# even if it was the same build from llvm
set(CXX_FLAGS "${CXX_FLAGS}  -fno-rtti ")

# we need LLVM_HOME in order to automatically set LLVM_DIR
if(NOT DEFINED ENV{LLVM_HOME})
    message(FATAL_ERROR "$LLVM_HOME is not defined")
else ()
    set(ENV{LLVM_DIR} $ENV{LLVM_HOME}/lib/cmake/llvm)
endif()

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})


# Set the output folder where your program will be created
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/llvm_tuto_bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(AddAlloca_pass)  # Use your pass name here.
install(
    FILES ${PROJECT_BINARY_DIR}/AddAlloca_pass/libAddAlloca_pass.so
    DESTINATION lib
)  

add_subdirectory(AddStore_pass)  # Use your pass name here.
install(
    FILES ${PROJECT_BINARY_DIR}/AddStore_pass/libAddStore_pass.so
    DESTINATION lib
)

add_subdirectory(AddFunction_pass)  # Use your pass name here.
install(
    FILES ${PROJECT_BINARY_DIR}/AddFunction_pass/libAddCallInst_pass.so
    DESTINATION lib
)

add_subdirectory(AddInitFunction_pass)  # Use your pass name here.
install(
    FILES ${PROJECT_BINARY_DIR}/AddInitFunction_pass/libAddInitFunction_pass.so
    DESTINATION lib
)


add_subdirectory(test)