#include <cstdio>
#include "pico/stdlib.h"

#include "I2C.h"
#include "BH1750/bh1750.h"

#define I2C_PORT i2c0
#define SDA_PIN 0
#define SCL_PIN 1

int main() {
    stdio_init_all();

    I2C i2c(I2C_PORT, SDA_PIN, SCL_PIN);
    i2c.begin();
    i2c.setClock(100000); // 100kHz

    sleep_ms(100);

    BH1750 sensor(i2c);
    sensor.begin();

    while (true) {
        float lux = sensor.readLux();
        printf("Luminosidade: %.2f lux\n", lux);
        sleep_ms(1000);
    }
}
