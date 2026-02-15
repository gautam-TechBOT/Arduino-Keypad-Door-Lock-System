#include <Keypad.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {10, 9,8,7}; //Rows 0 to 3
byte colPins[numCols]= {6,5,4,3}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

String password;  


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);



   int i, j ;


  Serial.println("Set your 4-digit password") ;

  int num_entered = 0;

  while(num_entered < 4){

      char keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY)
      {tone(13, 1500);
      delay(200);
      noTone(13);
      Serial.println(keypressed);
    
    
      password += keypressed; 
        num_entered++;
      }
  }
  Serial.println("Password has been set succesfully");
  Serial.println(password);

  Serial.println("Enter your password") ;


}


void loop()
{  


  int pass_tried = 0;

  while(pass_tried < 3) {

     String temp_pass = "" ;

     int num_entered = 0;

     while(num_entered < 4){

      char keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY)
      {  Serial.println(keypressed);
      tone(13, 4000);
      delay(200);
      noTone(13);
      temp_pass += keypressed;
        num_entered++;
      }

  }
    if(temp_pass == password) {
    Serial.println("Correct Password") ;
    digitalWrite(11, HIGH) ; delay(5000) ; digitalWrite(11, LOW) ;
    break;
    }

   pass_tried++ ;
   tone(13, 9000);
      delay(200);
      noTone(13); digitalWrite(13,LOW);
   Serial.println(" Incorrect Password. Enter Password again.");
 }
  if(pass_tried >= 3) {
  tone(13, 800);
      delay(10000);
      noTone(13);
 } ;


}

