cmake_minimum_required(VERSION 3.22)

project(serial_test CXX)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

add_subdirectory(lib/SerialPort)
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/lib/SerialPort/include)
target_link_libraries(main PRIVATE SerialPort)


