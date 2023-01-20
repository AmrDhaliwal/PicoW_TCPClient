/*
* The main file for the project.
*/

#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    while(true) {
        printf("Hello, USB!\n");
        sleep_ms(1000);
    }
    return 0;
}
