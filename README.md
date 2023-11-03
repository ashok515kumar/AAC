# AAC
AAC-Clydespace Software Engineer Test

# LIS3MDLTR 3-Axis Magnetometer Sensor Driver

This repository contains a C code example for interfacing with the LIS3MDLTR 3-Axis Magnetometer sensor using the I2C communication protocol. The code demonstrates how to retrieve the device's full-scale configuration, retrieve and set the output data rate, enable or disable the interrupt pin, and read the output data of a specific axis.

## Prerequisites

Before using this driver code, ensure you have the following:

- A microcontroller or platform with I2C support.
- The LIS3MDLTR sensor is connected to your hardware.

## Hardware Connections

Ensure that the LIS3MDLTR sensor is correctly connected to your microcontroller. You may need to connect the sensor's power supply, ground, and I2C lines. Refer to the sensor datasheet and your specific hardware documentation for pin details.

## Usage

1. **Retrieve the Device's Full-Scale Configuration:**

    To retrieve the sensor's full-scale configuration, you can use the `getFullScaleConfiguration` function. It reads the current configuration and extracts the full-scale bits.

    ```c
    uint8_t fullScale = getFullScaleConfiguration();
    ```

2. **Retrieve and Set the Device's Output Data Rate:**

    To retrieve the current output data rate (ODR) and set a new ODR, you can use the following functions:

    - Retrieve the current ODR:
    
        ```c
        uint8_t outputRate = getOutputDataRate();
        ```

    - Set a new ODR (e.g., set ODR to 50 Hz):

        ```c
        setOutputDataRate(5);
        ```

3. **Enable or Disable the Device's Interrupt Pin:**

    To enable or disable the sensor's interrupt pin, use the `enableInterruptPin` function. It reads the current configuration and sets or clears the interrupt enable bits accordingly.

    - To enable the interrupt pin:

        ```c
        enableInterruptPin(true);
        ```

    - To disable the interrupt pin:

        ```c
        enableInterruptPin(false);
        ```

4. **Read the Output Data of a Specific Axis:**

    To read the output data of a specific axis (e.g., X-axis) and convert it to a two's complement integer, you can use the `readAxisData` function. Provide the appropriate register addresses for the axis.

    ```c
    int16_t xAxisData = readAxisData(OUT_X_L, OUT_X_H);
    ```

5. **Initialize I2C Communication and Close I2C Communication:**

    Before and after using the sensor, you should initialize and close the I2C communication with your hardware-specific code, which is not provided in this example.

## Contributing

If you find any issues with the code or would like to enhance it, please feel free to open an issue or submit a pull request.

## License

This code is not licenced.

## Note

This code is not compiled and tested
