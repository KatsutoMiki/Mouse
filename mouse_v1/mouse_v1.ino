#include "Mouse.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Mouse.begin();
}

int mousePressed = 0;
signed char cursor_speed = 1;

void loop() {
  // put your main code here, to run repeatedly:
  int A0_value, A1_value, A2_value;
  float A0_volt, A1_volt, A2_volt;
  
  A0_value = analogRead(A0);
  A1_value = analogRead(A1);
  A2_value = analogRead(A2);
  
  A0_volt = A0_value*5.0/1023;
  A1_volt = A1_value*5.0/1023;
  A2_volt = A2_value*5.0/1023;

  Serial.print(A0_value);
  Serial.print(",");
  Serial.print(A1_value);
  Serial.print(",");
  Serial.println(A2_value);
  
  //UP
  if (A0_value > 130 && A1_value > 170 && A2_value < 150){
    Mouse.move(0,-cursor_speed,0);
  }
  //DOWN
  else if (A1_value < 150 && A2_value > 160){
    Mouse.move(0,cursor_speed,0);
  }
  //RIGHT
  else if (A0_value < 155 && A1_value > 175 && A2_value > 175){
    Mouse.move(cursor_speed,0,0);
  }
  //LEFT
  else if (A1_value < 120 && A2_value < 120){
    Mouse.move(-cursor_speed,0,0);
  }
  //Tap
  else if (A0_value > 150 && A1_value > 150 && A2_value > 150 && mousePressed == 0){
    Mouse.press();
    mousePressed = Mouse.isPressed();
  }
  else if (A0_value < 150 && A1_value < 150 && A2_value < 150 && mousePressed == 1){
    Mouse.release();
    mousePressed = Mouse.isPressed();
  }



  delay(1);
//  Serial.print("A0_Value:");
//  Serial.print(A0_value);
//  Serial.print("A0_Volt:");
//  Serial.println(A0_volt);
//  
//  Serial.print("A1_Value:");
//  Serial.print(A1_value);
//  Serial.print("A1_Volt:");
//  Serial.println(A1_volt);
//  
//  Serial.print("A2_Value:");
//  Serial.print(A2_value);
//  Serial.print("A2_Volt:");
//  Serial.println(A2_volt);
//  delay(500);
}
