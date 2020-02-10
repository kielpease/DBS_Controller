#include "Joystick.h"
//Mapped Hatswitch Dpad movement and standard 4 button options with a "Start" and "Select" button - Very Simple

//Joystick_ Joystick;
Joystick_ Joystick(0x03, //hid report id
JOYSTICK_TYPE_GAMEPAD, //joystick type
18, //button count
1, //Hsw 0-2
true, //x
true, //y
false, //z 
false, //rx
false, //ry
false, //rz 
false, //rudder
false, //throttle
false, //accelerator
false, //brake
false); //steering

  const int A_Btn = 10;
  const int B_Btn = 16;
  const int X_Btn = 14;
  const int Y_Btn = 15;
  const int PAUSE = 2;
  const int SELECT = 3;

void setup() {
  Joystick.begin();

  pinMode(A_Btn, INPUT);
  digitalWrite(A_Btn, HIGH);
  pinMode(B_Btn, INPUT);
  digitalWrite(B_Btn, HIGH);
  pinMode(X_Btn, INPUT);
  digitalWrite(X_Btn, HIGH);
  pinMode(Y_Btn, INPUT);
  digitalWrite(Y_Btn, HIGH);
  pinMode(SELECT, INPUT);
  digitalWrite(SELECT, HIGH);
  pinMode(PAUSE, INPUT);
  digitalWrite(PAUSE, HIGH);

  pinMode(PAUSE, INPUT);
  digitalWrite(PAUSE, HIGH);

  Serial.begin(9600);
}

void loop() {

//------------------------------------------------Buttons - DPad/POV Hat--------------------------------------//
  int Axis8 = analogRead(A8);
  int Axis9 = analogRead(A9);
  if (Axis8 > 712) {  
     Joystick.setHatSwitch(0,0);    //Hat Right
  }
  else if (Axis8 < 312) { 
    Joystick.setHatSwitch(0,180);   //Hat Left
  }
  else if (Axis9 > 712) {  
    Joystick.setHatSwitch(0,270);    //Hat Up
  }
  else if (Axis9 < 312) {
    Joystick.setHatSwitch(0,90);   //Hat Down
  }
  else {
    Joystick.setHatSwitch(0,-1);
  }

  //------------------------------------------------Buttons - ABXY/Pause/Select--------------------------------------//
  if(digitalRead(A_Btn) == LOW) {
    Joystick.setButton(0,1);  // Button 1 -------------------------------------------------ButtA 0
  }
  else {
    Joystick.setButton(0,0);
  }
  if(digitalRead(B_Btn) == LOW) {
    Joystick.setButton(1,1);  // Button 2 -------------------------------------------------ButtB 1
  }
  else {
    Joystick.setButton(1,0);
  }
  if(digitalRead(X_Btn) == LOW) {
    Joystick.setButton(3,1);  // Button 11 -----------------------------------------------ButtX 2
  }
  else {
    Joystick.setButton(3,0);
  }
  if(digitalRead(Y_Btn) == LOW) {
    Joystick.setButton(4,1); // Button 12-------------------------------------------------ButtY 3
  }
  else {
    Joystick.setButton(4,0);
  }
  if(digitalRead(SELECT) == LOW) {
    Joystick.setButton(6,1); // Button 9---------------------------------------------------ButtSel 4
  }
  else {
    Joystick.setButton(6,0);
  }
  if(digitalRead(PAUSE) == LOW) {
    Joystick.setButton(7,1);  // Button 10-------------------------------------------------ButtSrt 5
  }
  else {
    Joystick.setButton(7,0);
  } 
 
}
