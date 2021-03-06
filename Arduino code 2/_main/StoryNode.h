/*
   StoryNode class:
     A single node or "room" in the story. Each node has a text portion and a three possible
     choices for the next node in the story.
*/
#ifndef StoryNode_h
#define StoryNode_h

//#include <SD.h>
//#include <SPI.h>
//#include <Audio.h>
//#include <DAC.h>
#include "Arduino.h"

class StoryNode
{
  protected:
    int *options;
    char *sound;

  public:
    StoryNode();
    StoryNode(char filename[], int opts[]);
    // hardcoded constructor for exactly three choices--for convenience
    StoryNode(char filename[], int a, int b, int c);
    // reads the chosen option
    void chooseOption(int i);
    void readNode();
};

#endif
