#include <stdio.h>

volatile int sensor_value = 0;

void read_sensor() {
    // Simulating sensor read
    sensor_value++;
}

int main() {
    for (int i = 0; i < 5; i++) {
        read_sensor();
        printf("Sensor value: %d\n", sensor_value);
    }
    return 0;
}
