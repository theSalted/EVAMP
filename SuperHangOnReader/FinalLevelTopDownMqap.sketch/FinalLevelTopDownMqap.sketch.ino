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

const float referenceVoltage = 5.0;

void setup() {
  // put your setup code here, to run once:

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
  Serial.println(voltage2);
  Serial.print(",");
  Serial.println(voltage3);
  Serial.print(",");
  Serial.println(voltage4);

}
