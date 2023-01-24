add_executable(TCP_Client
        TCP_Client.c
        )
target_compile_definitions(TCP_Client PRIVATE
        WIFI_SSID=\"${WIFI_SSID}\"
        WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
        )
target_include_directories(TCP_Client PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )
# pull in common dependencies
target_link_libraries(TCP_Client 
        pico_cyw43_arch_lwip_threadsafe_background
        pico_stdlib # Needed for core functionality
        )

# First line enables the usb output and second line disables the uart output
pico_enable_stdio_usb(TCP_Client 1)
pico_enable_stdio_uart(TCP_Client 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(TCP_Client)
