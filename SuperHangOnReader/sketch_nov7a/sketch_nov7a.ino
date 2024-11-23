#include "Arduino_LED_Matrix.h"

int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;
int analogPin3 = A3;
int analogPin4 = A4;

int analogValue0 = 0;
int analogValue1 = 0;
int analogValue2 = 0;
int analogValue3 = 0;
int analogValue4 = 0;

const float referenceVoltage = 5.0; // Adjust if using a different reference voltage
ArduinoLEDMatrix matrix;

const uint32_t animation[][4] = {
  {
		0x10010,
		0x2802804,
		0x40440000,
		200
	},
	{
		0x48848,
		0x87944944,
		0xa2322000,
		200
	},
	{
		0x45255,
		0x255e5525,
		0x5228c000,
		200
	},
	{
		0xa20a,
		0xa3aa4aa4,
		0xaa394000,
		200
	},
	{
		0x200,
		0x200e0120,
		0x1200e000,
		200
	},
	{
		0x0,
		0x0,
		0x0,
		200
	}
};

int animationFrame = 0;
unsigned long lastUpdateTime = 0;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue0 = analogRead(analogPin0);
  analogValue1 = analogRead(analogPin1);
  analogValue2 = analogRead(analogPin2);
  analogValue3 = analogRead(analogPin3);
  analogValue4 = analogRead(analogPin4);

  // Convert analog readings to voltage
  float voltage0 = (analogValue0 * referenceVoltage) / 1023.0;
  float voltage1 = (analogValue1 * referenceVoltage) / 1023.0;
  float voltage2 = (analogValue2 * referenceVoltage) / 1023.0;
  float voltage3 = (analogValue3 * referenceVoltage) / 1023.0;
  float voltage4 = (analogValue4 * referenceVoltage) / 1023.0;

  // Print the analog values as voltage to the serial monitor
  Serial.print(voltage0);
  Serial.print(",");
  Serial.print(voltage1);
  Serial.print(",");
  Serial.print(voltage2);
  Serial.print(",");
  Serial.print(voltage3);
  Serial.print(",");
  Serial.println(voltage4);

  // Handle LED matrix animation without blocking
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime >= animation[animationFrame][3]) {
    // Pass the frame array to loadFrame
    matrix.loadFrame(animation[animationFrame]);

    // Move to the next frame
    animationFrame = (animationFrame + 1) % (sizeof(animation) / sizeof(animation[0]));

    // Reset the timer for the next frame
    lastUpdateTime = currentTime;
  }

  delay(1);  
}