/*
AUTHOR: L. Bell
DATE: 23/08/2016
DESCR:
  Based off 'CustomKeypad' example in Arduino Keypad library.
  4x3 Keypad Traffic Light Control
  Traffic Light: Red 13, Orange 12, Green 11.
  Keypad - Row Pins: 6-9, Columns: 3-5.
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
int red = 13;
int orange = 12;
int green = 11;
bool rp = false;
bool op = false;
bool gp = false;
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(green , OUTPUT);
}  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    if (customKey == '1'){
      digitalWrite(red, HIGH);
      digitalWrite(orange, LOW);
      digitalWrite(green, LOW);
      rp = true;
      gp = false;
      op = false;
    }
    if (customKey == '2'){
      digitalWrite(red, LOW);
      digitalWrite(orange, HIGH);
      digitalWrite(green, LOW);
      gp = true;
      rp = false;
      op = false;
    }
    if (customKey == '3'){
      digitalWrite(red, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(green, HIGH);
      op = true;
      rp = false;
      gp = false;
    } 
    if (customKey == '*'){
      digitalWrite(red, LOW);
      digitalWrite(orange, LOW);
      digitalWrite(green, LOW);
    }
    if (customKey == '#'){
      digitalWrite(red, HIGH);
      digitalWrite(orange, HIGH);
      digitalWrite(green, HIGH);
    }
    if (customKey == '4'){
       if (rp == false){
         digitalWrite(red, HIGH);
         rp = true;
        }
        else{
          digitalWrite(red, LOW);
          rp = false;
        }
      }
      if (customKey == '5'){
        if (op == false){
          digitalWrite(orange, HIGH);
          op = true;
      }
      else{
        digitalWrite(orange, LOW);
        op = false;
      }
    }
    if (customKey == '6'){
      if (gp == false){
        digitalWrite(green, HIGH);
        gp = true;
      }
      else{
        digitalWrite(green, LOW);
        gp = false;
      }
    }
  }
}
