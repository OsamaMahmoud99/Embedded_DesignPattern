# toolchain-avr.cmake
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Adjust to your actual installation path
set(AVR_PREFIX "C:/msys64/mingw64/bin")

set(CMAKE_C_COMPILER ${AVR_PREFIX}/avr-gcc.exe)
set(CMAKE_CXX_COMPILER ${AVR_PREFIX}/avr-g++.exe)
set(CMAKE_OBJCOPY ${AVR_PREFIX}/avr-objcopy.exe)

# Avoid try-run problems
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
