#include "pico/cyw43_arch.h"

#include "wifi_config.h"

int wifi_init() {
    #ifndef WIFI_SSID
        printf("Wi-Fi not configured\n");
    #else
        // Initialise the Wi-Fi chip
        if (cyw43_arch_init()) {
            printf("Wi-Fi init failed\n");
            return -1;
        }
    #endif
    return 0;
}

int wifi_connect() {
    #ifndef WIFI_SSID
        printf("Wi-Fi not configured\n");
    #else
        // Enable wifi station
        cyw43_arch_enable_sta_mode();

        printf("Connecting to Wi-Fi...\n");
        if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, WIFI_AUTH, 30000)) {
            printf("failed to connect.\n");
            return 1;
        } else {
            printf("Connected.\n");
            // Read the ip address in a human readable way
            uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
            printf("IP address %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
        }
    #endif
    return 0;
}