#include <stdint.h>

// Define sensor I2C address
#define LIS3MDLTR_I2C_ADDR 0x3A  // Assuming SDO/SA1 is connected to the voltage supply

// Register addresses
#define WHO_AM_I 0x0F
#define CTRL_REG1 0x20
#define CTRL_REG3 0x22
#define CTRL_REG5 0x24
#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D


// Function to retrieve the device's full-scale configuration
uint8_t getFullScaleConfiguration() {
    uint8_t config;
    i2c_read(LIS3MDLTR_I2C_ADDR, CTRL_REG2, &config, 1);
    return (config >> 2) & 0x03;  // Extract the FS bits
}

// Function to retrieve and set the device's output data rate
uint8_t getOutputDataRate() {
    uint8_t config;
    i2c_read(LIS3MDLTR_I2C_ADDR, CTRL_REG1, &config, 1);
    return (config >> 2) & 0x07;  // Extract the ODR bits
}

void setOutputDataRate(uint8_t rate) {
    // Read the current configuration
    uint8_t config;
    i2c_read(LIS3MDLTR_I2C_ADDR, CTRL_REG1, &config, 1);

    // Update the ODR bits (4:2)
    config = (config & 0xE3) | ((rate << 2) & 0x1C);

    // Write the updated configuration back to the sensor
    i2c_write(LIS3MDLTR_I2C_ADDR, CTRL_REG1, &config, 1);
}

// Function to enable or disable the device's interrupt pin
void enableInterruptPin(bool enable) {
    // Read the current configuration
    uint8_t config;
    i2c_read(LIS3MDLTR_I2C_ADDR, INT_CFG, &config, 1);

    if (enable) {
	    config |= 0x07;  // Set XIEN, YIEN, ZIEN to 1
    } else {
	    config &= 0xF8;  // Set XIEN, YIEN, ZIEN to 0
    }

    // Write the updated configuration back to the sensor
    i2c_write(LIS3MDLTR_I2C_ADDR, CTRL_REG3, &config, 1);
}

// Function to read the output data of a specific axis and convert to two's complement
int16_t readAxisData(uint8_t axisRegL, uint8_t axisRegH) {
    uint8_t dataL, dataH;
    i2c_read(LIS3MDLTR_I2C_ADDR, axisRegL, &dataL, 1);
    i2c_read(LIS3MDLTR_I2C_ADDR, axisRegH, &dataH, 1);

    // Combine the data bytes into a two's complement integer
    int16_t result = (int16_t)((dataH << 8) | dataL);

    return result;
}

int main() {
    // Initialize I2C communication with your hardware-specific code

    // Retrieve the device's full-scale configuration
    uint8_t fullScale = getFullScaleConfiguration();

    // Retrieve the device's output data rate
    uint8_t outputRate = getOutputDataRate();

    // Set the device's output data rate (example: Set ODR to 50 Hz)
    setOutputDataRate(5);

    // Enable the device's interrupt pin (example: Enable interrupt)
    enableInterruptPin(true);

    // Read the output data of a specific axis (e.g., X-axis) and convert to two's complement
    int16_t xAxisData = readAxisData(OUT_X_L, OUT_X_H);

    // Close I2C communication

    return 0;
}
