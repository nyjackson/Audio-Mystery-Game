
#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "AlternateStoryNode.h"

AlternateStoryNode::AlternateStoryNode(char text[], int a, int b, int c, strCond function)
{
  sound = text;
  options = new int[3] {a, b ,c};
  chooseSound = function;
}

void AlternateStoryNode::readNode()
{
  /*int len = *(&sound + 1) - sound;
  char newName[len + 2];
  for (int i = 0; i < len; i++)
  {
    newName[i] = sound[i];
  }
  newName[len] = '_';*/
  
  char newName = chooseSound(*TRIGGERS);
  //displaySound(sound);
  Serial.println(newName);
  tmrpcm.play(newName);
  // set storyChooser wait time!
  
  storyChooser -> queue(NODES[options[0]]);
}
