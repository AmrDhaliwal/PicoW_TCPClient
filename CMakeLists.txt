cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico_w)
# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(TCP_Client C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

if (PICO_CYW43_SUPPORTED)
    if (NOT TARGET pico_cyw43_arch)
        message("WIFI SSID AND PASSWORD NOT SET!")
    else()
        set(WIFI_SSID "${WIFI_SSID}" CACHE INTERNAL "Wifi SSID for project")
        set(WIFI_PASSWORD "${WIFI_PASSWORD}" CACHE INTERNAL "Wifi Password for project")
    endif()
endif()

# Add blink subdirectory
add_subdirectory(TCP_Client)