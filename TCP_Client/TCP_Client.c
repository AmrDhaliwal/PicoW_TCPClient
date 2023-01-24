/*
* The main file for the project.
*/

#include <string.h>
#include <stdio.h>

#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#include "lwip/pbuf.h"
#include "lwip/tcp.h"

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Failed to initialise cy43 driver.\n");
        return 1;
    }

    while(true) {
        printf("Hello, USB!\n");
        sleep_ms(1000);
    }
    return 0;
}
