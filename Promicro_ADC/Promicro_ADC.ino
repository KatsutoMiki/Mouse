
float sensorVolt[3] = { 0, 0, 0 };

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.print(analogRead(A0));
  // Serial.print(",");
  // Serial.print(analogRead(A1));
  // Serial.print(",");
  // Serial.println(analogRead(A2));

  sensorVolt[0] = analogRead(A0) * 5.0 / 1023;
  sensorVolt[1] = analogRead(A1) * 5.0 / 1023;
  sensorVolt[2] = analogRead(A2) * 5.0 / 1023;

  Serial.print(sensorVolt[0]);
  Serial.print(",");
  Serial.print(sensorVolt[1]);
  Serial.print(",");
  Serial.println(sensorVolt[2]);
}
