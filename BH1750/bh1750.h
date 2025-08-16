#ifndef BH1750_HPP
#define BH1750_HPP

#include <cstdint>
#include "I2C.h"

class BH1750 {
public:
    explicit BH1750(I2C &i2c) : _i2c(i2c) {}

    // Inicializa o sensor no modo contínuo de alta resolução
    void begin();

    // Lê a iluminância (lux). Retorna -1.0f em caso de falha
    float readLux();

private:
    I2C &_i2c;
    static constexpr uint8_t ADDRESS = 0x23; // ADDR em GND
};

#endif // BH1750_HPP
