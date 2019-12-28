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
//boolean ACCEPT_INPUT;

const StoryChooser* storyChooser = new StoryChooser();
boolean* TRIGGERS[32];
const int STORY = 112; // number of nodes
StoryNode* NODES[STORY];
TMRpcm tmrpcm;

//StoryNode START;

//int buttons[LENGTH];
//int values[LENGTH];

/*
 Volume Control - adapted from Analog Input Example

 The circuit:
 * Potentiometer attached to analog input 0 (or any free analog pin)
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 
 Originally created by David Cuartielles, modified 30 Aug 2011 By Tom Igoe
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tmrpcm.speakerPin = A0; //11 on Mega, 9 on Uno, Nano, etc
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;   // don't do anything more if not
  } // */
  Serial.print("SD worked?");
  pinMode(buttonPin[0], INPUT);
  pinMode(buttonPin[1], INPUT);
  pinMode(buttonPin[2], INPUT);
  pinMode(buttonPin[3], INPUT);
  pinMode(9, OUTPUT);

  tmrpcm.setVolume(4);
  //val = 0;
  tmrpcm.play("0001.wav");
  //ACCEPT_INPUT = true;

  //storyChooser -> startStory(initialize());
}

void loop() {
  //val = analogRead(buttonPin);
  //Serial.println(val); // debugging
  // val determines which buttons are pressed
  storyChooser-> updateMe();
  if (/*ACCEPT_INPUT*/ ! storyChooser -> busy())
  {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttonPin[i]) == LOW) {
        //ACCEPT_INPUT = false;
        pushButton(i);
        break;

      }
    }
  }
  // volume controls
    //read sensor value
  sensorValue = analogRead(sensorPin);
  // tmrpcm has volume 0-7, sensorPin reads 0-1023
  tmrpcm.setVolume(map(sensorValue, 0, 1023, 0, 7));
  /*
  // create key_command existing variable that can be both word and double byte of left and right.
  union twobyte mp3_vol;
  // returns a double uint8_t of Left and Right packed into int16_t
  mp3_vol.word = MP3player.getVolume();
  // map slide pot value (0-1023) to volume value (2-254)
  newVolume = map(sensorValue, 0, 1023, 2, 254)
  // set volume value as new volume value
  mp3_vol.byte[1] = newVolume
  // commit new volume
  MP3player.setVolume(mp3_vol.byte[1], mp3_vol.byte[1]);
  // print volume value*/
  Serial.print(F("Volume changed to -"));
  Serial.print(map(sensorValue, 0, 1023, 0, 7));
  Serial.println(F("[dB]")); // */
  //tmrpcm.volume( true ? 0 : 1) // 0 lowers, 1 raises
}

void pushButton(int i)
{
  // do something with i
  Serial.println(i);
  storyChooser -> choose(i);
  // WAIT TIMES: determined in Alternate, Cascading, Conditional, & regular StoryNode ::readNode() method
}
