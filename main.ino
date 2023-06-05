#include <Arduino.h>
#include <MPU6050_6Axis_Microduino.h>
// includes end
// definition start
int16_t readAcc(uint8_t _mode);
// definition end

MPU6050 accelgyro;
int16_t accX;
int16_t accY;
int16_t accZ;
int16_t gyroX;
int16_t gyroY;
int16_t gyroZ;
int16_t readAcc(uint8_t _mode) {
	accelgyro.getMotion6(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);
	if (_mode == 0) return accX;
	if (_mode == 1) return accY;
	if (_mode == 2) return accZ;
	if (_mode == 3) return gyroX;
	if (_mode == 4) return gyroY;
	if (_mode == 5) return gyroZ;
}

void setup() {
	// setup define start
	Wire.begin();
	accelgyro.initialize();
	accelgyro.testConnection();
	// setup define end
	Serial.begin(57600);
}

void loop() {
	Serial.print(readAcc(3));
}