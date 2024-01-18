#include "Mouse.h"

int firstRead[3] = { 0, 0, 0 };
int sensorValue[3] = { 0, 0, 0 };
float sensorVolt[3] = { 0, 0, 0 };
float sensorMatrix[3][3] = { { 0.02787849, 0.7439311 , -1.4808451 }, { -1.0677772 ,  0.48485976,  0.8420289 }, { 0.64206654,  1.0900601 ,  1.6909394 } };
float force[3] = { 0, 0, 0 };
int mousePressed = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Mouse.begin();
  firstRead[0] = analogRead(A0);
  firstRead[1] = analogRead(A1);
  firstRead[2] = analogRead(A2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.print(analogRead(A1));
  Serial.print(",");
  Serial.println(analogRead(A2));

  sensorValue[0] = analogRead(A0) - firstRead[0];
  sensorValue[1] = analogRead(A1) - firstRead[1];
  sensorValue[2] = analogRead(A2) - firstRead[2];

  sensorVolt[0] = sensorValue[0] * 5.0 / 1023;
  sensorVolt[1] = sensorValue[1] * 5.0 / 1023;
  sensorVolt[2] = sensorValue[2] * 5.0 / 1023;

  force[0] = sensorVolt[0] * sensorMatrix[0][0] + sensorVolt[1] * sensorMatrix[0][1] + sensorVolt[2] * sensorMatrix[0][2];
  force[1] = sensorVolt[0] * sensorMatrix[1][0] + sensorVolt[1] * sensorMatrix[1][1] + sensorVolt[2] * sensorMatrix[1][2];
  force[2] = sensorVolt[0] * sensorMatrix[2][0] + sensorVolt[1] * sensorMatrix[2][1] + sensorVolt[2] * sensorMatrix[2][2];

  Serial.print(force[0]);
  Serial.print(",");
  Serial.print(force[1]);
  Serial.print(",");
  Serial.println(force[2]);

  if (abs(force[0]) > 0.2 | abs(force[1]) > 0.2) {
    Mouse.move(force[1] * 10, force[0] * -10, 0);
  } else if (force[2] > 1.0 && mousePressed == 0) {
    Mouse.press();
    mousePressed = Mouse.isPressed();
  } else if (force[2] < 1.0 && mousePressed == 1) {
    Mouse.release();
    mousePressed = Mouse.isPressed();
  }
  delay(1);
}