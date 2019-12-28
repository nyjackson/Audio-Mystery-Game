#include "StoryChooser.h"
#include "StoryNode.h"
#include "CascadingStoryNode.h"
#include <SD.h>

#define SD_ChipSelectPin 9 //don't know what should be for the shield?
#include <TMRpcm.h>
#include <SPI.h>

#include <SdFat.h>
#include <FreeStack.h>
#include <SdFatConfig.h>

//#include <vs1053.h>

uint8_t const SOFT_SPI_CS_PIN = 9;

// USB serial port: 32
//Serial myPort;
//const int NUM = 4;
//const int buttonPin = 2; // button analog input

int buttonPin[4] = {4, 5, 6, 7};
int spkrPin = 11;
boolean ACCEPT_INPUT;

const StoryChooser* storyChooser = new StoryChooser();
boolean* TRIGGERS[32];
TMRpcm tmrpcm;

//StoryNode START;

//int buttons[LENGTH];
//int values[LENGTH];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tmrpcm.speakerPin = A0; //11 on Mega, 9 on Uno, Nano, etc
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;   // don't do anything more if not
  } // */
  Serial.print("SD worked?");
  //storyChooser -> startStory(initialize());
  pinMode(buttonPin[0], INPUT);
  pinMode(buttonPin[1], INPUT);
  pinMode(buttonPin[2], INPUT);
  pinMode(buttonPin[3], INPUT);
  pinMode(9, OUTPUT);

  tmrpcm.setVolume(4);
  //val = 0;
  tmrpcm.play("0001.wav");
  ACCEPT_INPUT = true;

}

void loop() {
  //val = analogRead(buttonPin);
  //Serial.println(val); // debugging
  // val determines which buttons are pressed
  storyChooser-> updateMe();
  if (ACCEPT_INPUT)
  {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPin[i]) == LOW) {
        ACCEPT_INPUT = false;
        pushButton(i);
        break;

      }
    }
  }
}

void pushButton(int i)
{
  // do something with i
  Serial.println(i);
  storyChooser -> choose(i);
}
