/*
Voice Box Demo Sketch
Written by Ryan Owens
SparkFun Electronics

Uses the Voice Box Shield from SparkFun to send the message "All your base are belong to us" and a series
of robot sounds to the SpeakJet chip on the shield. 

A speaker can be plugged directly into the SPK+ and - pins on the shield.

*/

//Soft serial library used to send serial commands on pin 2 instead of regular serial pin.
#include <SoftwareSerial.h>

//Define the Pin Numbers for the sketch.
#define E0  5
#define E1  6
#define E2  7
#define E3  8
#define E4  9
#define E5  10
#define E6  11
#define E7  12

#define RDY  13
#define RES  3
#define SPK  4

#define txPin  2

//Create a SoftSerial Objet
SoftwareSerial speakjet = SoftwareSerial(0, txPin);

/*

                  //hello                      human                          how     are             you        today?               
char message[] = {3, 3, 183, 7, 159, 146, 164, 5, 183, 7, 160, 140, 131, 141, 5, 184, 5, 8, 163, 152, 5, 8, 160, 5, 8, 191, 139, 174, 154,

                //this                    is              a            test                      of              the                speakjet.
                  3, 8, 169, 8, 129, 187, 5, 8, 129, 167, 5, 154, 128, 5, 191, 131, 8, 187, 191, 5, 8, 134, 166, 5, 8, 169, 8, 128, 5, 187, 198, 8, 128, 196, 165, 131, 191,
                  
                //this                    test                      is              for          C                      O            S                 C
                  3, 8, 169, 8, 129, 187, 5, 191, 131, 8, 187, 191, 5, 8, 129, 167, 5, 186, 153, 5, 187, 187, 128, 128, 5, 137, 164, 5, 131, 187, 187, 5, 187, 187, 128, 128,
                  
                //2               3                       2               5
                  5, 8, 191, 162, 5, 8, 190, 148, 8, 128, 5, 8, 191, 162, 5, 186, 157, 166};

                //this                    was               created                                  by           Arman                  and
                  3, 8, 169, 8, 129, 187, 5, 147, 134, 167, 5, 195, 7, 148, 128, 154, 191, 129, 176, 5, 171, 157, 5, 152, 140, 154, 141, 5
*/

char message[] = {3, 3, 183, 7, 159, 146, 164, 5, 183, 7, 160, 140, 131, 141, 5, 184, 5, 8, 163, 152, 5, 8, 160, 5, 8, 191, 139, 174, 154};

char message2[] = {3, 8, 169, 8, 129, 187, 5, 8, 129, 167, 5, 154, 128, 5, 191, 131, 8, 187, 191, 5, 8, 134, 166, 5, 8, 169, 8, 128, 5, 187, 198, 8, 128, 196, 165, 131, 191};

char message3[] = {3, 8, 169, 8, 129, 187, 5, 191, 131, 8, 187, 191, 5, 8, 129, 167, 5, 186, 153, 5, 187, 187, 128, 128, 5, 137, 164, 5, 131, 187, 187, 5, 187, 187, 128, 128};

char message4[] = {5, 8, 191, 162, 5, 8, 190, 148, 8, 128, 5, 8, 191, 162, 5, 186, 157, 166};

char message5[] = {3, 8, 169, 8, 129, 187, 5, 147, 134, 167, 5, 195, 7, 148, 128, 154, 191, 129, 176, 5, 171, 157, 5, 152, 140, 154, 141, 5};

char long_message[] = {3, 3, 183, 7, 159, 146, 164, 5, 183, 7, 160, 140, 131, 141, 5, 184, 5, 8, 163, 152, 5, 8, 160, 5, 8, 191, 139, 174, 154,
3, 8, 169, 8, 129, 187, 5, 8, 129, 167, 5, 154, 128, 5, 191, 131, 8, 187, 191, 5, 8, 134, 166, 5, 8, 169, 8, 128, 5, 187, 198, 8, 128, 196, 165,
131, 191, 3, 8, 169, 8, 129, 187, 5, 191, 131, 8, 187, 191, 5, 8, 129, 167, 5, 186, 153, 5, 187, 187, 128, 128, 5, 137, 164, 5, 131, 187, 187, 5,
187, 187, 128, 128, 5, 8, 191, 162, 5, 8, 190, 148, 8, 128, 5, 8, 191, 162, 5, 186, 157, 166, 3, 8, 169, 8, 129, 187, 5, 147, 134, 167, 5, 195, 7,
148, 128, 154, 191, 129, 176, 5, 171, 157, 5, 152, 140, 154, 141, 5};

void setup()  
{
  //Configure the pins for the SpeakJet module
  pinMode(txPin, OUTPUT);
  pinMode(SPK, INPUT);
  
  //Set up a serial port to talk from Arduino to the SpeakJet module on pin 3.
  speakjet.begin(9600);    
  
  //Configure the Ready pin as an input
  pinMode(RDY, INPUT);
  
  //Configure Reset line as an output
  pinMode(RES, OUTPUT);
       
  //Configure all of the Event pins as outputs from Arduino, and set them Low.
  for(int i=E0; i<=E7; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  //All I/O pins are configured. Reset the SpeakJet module
  digitalWrite(RES, LOW);
  delay(100);
  digitalWrite(RES, HIGH);
  
}

void loop()
{  
  
  speakjet.print(message);
  delay(4000);
  speakjet.print(message2);
  delay(4000);
  speakjet.print(message3);
  delay(4000);
  //speakjet.print(message4);
  //delay(4000);
  //speakjet.print(message5);
  while(1);
  
  /*
  speakjet.print(long_message);
  delay(16000);
  while(1);
  */
}
