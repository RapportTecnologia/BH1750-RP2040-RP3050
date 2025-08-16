#include "bh1750.h"
#include "pico/stdlib.h"

void BH1750::begin() {
    // Power On (0x01) then Continuous High Resolution Mode (0x10)
    _i2c.beginTransmission(ADDRESS);
    _i2c.write(0x01); // Power On
    _i2c.write(0x10); // Continuous High Resolution Mode
    _i2c.endTransmission();
    sleep_ms(180); // tempo típico de conversão para primeira leitura
}

float BH1750::readLux() {
    // Solicita 2 bytes do sensor (valor raw)
    uint8_t received = _i2c.requestFrom(ADDRESS, 2);
    if (received < 2) {
        return -1.0f;
    }
    int msb = _i2c.read();
    int lsb = _i2c.read();
    if (msb < 0 || lsb < 0) {
        return -1.0f;
    }
    uint16_t raw = (static_cast<uint16_t>(msb) << 8) | static_cast<uint16_t>(lsb);
    return raw / 1.2f;
}
