#include <LiquidCrystal.h>

#define  S0 6
#define  S1 7
#define  S2 8
#define  S3 9
#define sensorOut 13

int frequency = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4 , d6 = 3, d7 = 2;
LiquidCrystal lcd(rs , en , d4 , d5 ,d6 , d7);


void setup() {
  // put your setup code here, to run once:
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(sensorOut,INPUT);

Serial.begin (9600);

 //set up the LCD;s number of columns and rows:
  lcd.begin(16,2);
  //Print a message to the LCD.
  lcd.print("hello,World!");

// setting frequency scalling to 20%
digitalWrite (S0, HIGH);
digitalWrite (S1, LOW);

}

void loop() {


  //set the cursor to column 0, line 1
    //note: line 1 is the second row, since counting begind with 0:
    lcd.setCursor(0,1);
    //Print the number of seconds since reset:
    lcd.print(millis()/1000);
  //setting red filtered photodiodes to be read
  digitalWrite (S2, LOW);
  digitalWrite (S3, LOW); 

  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);

  // Printing the value on the serial monitor 
  Serial.print("R= "); //printing name
  Serial.print(frequency);// printing frequency of red color 
  Serial.print("  ");
  delay(100);
  

//setting green filtered photodiodes to be read
  digitalWrite (S2, HIGH);
  digitalWrite (S3, HIGH);

  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);

  // Printing the value on the serial monitor 
  Serial.print("G= "); //printing name
  Serial.print(frequency);// printing frequency of Green color 
  Serial.println("  ");
  delay(100);


  //setting BLUE filtered photodiodes to be read
  digitalWrite (S2, LOW);
  digitalWrite (S3, HIGH);

  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);

  // Printing the value on the serial monitor 
  Serial.print("B= "); //printing name
  Serial.print(frequency);// printing frequency of BLUE color 
  Serial.print("  ");
  delay(100);











}
