cmake_minimum_required(VERSION 3.22)

# Project definition
project(BuilderPattern CXX)

# MCU & frequency definitions
set(MCU atmega32)
set(F_CPU 1000000UL)

# Compiler flags
set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

# Skip compiler test (required for cross-compiling)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Source directories
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# Executable output
add_executable(${PROJECT_NAME}.elf main.cpp)
target_link_libraries(${PROJECT_NAME}.elf PUBLIC HAL)
target_include_directories(${PROJECT_NAME}.elf PUBLIC ${CMAKE_SOURCE_DIR}/includes)

# Create HEX file from ELF
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -j .text -j .data -O ihex
            ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMENT "Generating HEX file"
)
