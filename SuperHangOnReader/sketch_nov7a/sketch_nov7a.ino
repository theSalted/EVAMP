#include "Arduino_LED_Matrix.h"

int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;

int analogValue0 = 0;
int analogValue1 = 0;
int analogValue2 = 0;

const float referenceVoltage = 5.0; // Adjust if using a different reference voltage
ArduinoLEDMatrix matrix;

const uint32_t animation[][4] = {
  {
		0x2202,
		0x20140140,
		0x8008000,
		200
	},
	{
		0x44c45,
		0x229229e1,
		0x12112000,
		200
	},
	{
		0x31c4a,
		0xa4aa7aa4,
		0xaa4a2000,
		200
	},
	{
		0x39c55,
		0x255255c5,
		0x50450000,
		200
	},
	{
		0x70048,
		0x4807004,
		0x400000,
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
  // Read analog inputs continuously
  analogValue0 = analogRead(analogPin0);
  analogValue1 = analogRead(analogPin1);
  analogValue2 = analogRead(analogPin2);

  // Convert analog readings to voltage
  float voltage0 = (analogValue0 * referenceVoltage) / 1023.0;
  float voltage1 = (analogValue1 * referenceVoltage) / 1023.0;
  float voltage2 = (analogValue2 * referenceVoltage) / 1023.0;

  // Print the analog values as voltage to the serial monitor
  Serial.print("Analog Pin A0 Voltage: ");
  Serial.print(voltage0);
  Serial.print(" V | Analog Pin A1 Voltage: ");
  Serial.print(voltage1);
  Serial.print(" V | Analog Pin A2 Voltage: ");
  Serial.println(voltage2);

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

  // A small delay can be added if necessary, but it should be short to avoid blocking
  delay(1);  // Keeps the loop running smoothly without much interruption
}