add_executable(TCP_Client
        TCP_Client.c
        )

# pull in common dependencies
target_link_libraries(TCP_Client 
        pico_stdlib # Needed for core functionality
        )

# First line enables the usb output and second line disables the uart output
pico_enable_stdio_usb(TCP_Client 1)
pico_enable_stdio_uart(TCP_Client 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(TCP_Client)