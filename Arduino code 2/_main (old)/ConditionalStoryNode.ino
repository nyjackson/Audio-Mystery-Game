#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "ConditionalStoryNode.h"


ConditionalStoryNode::ConditionalStoryNode(char filename[], conditional function)
{
  sound = filename;
  c = function;
}
ConditionalStoryNode::ConditionalStoryNode (char filename[], conditional function, StoryNode nOptions[])
{
  sound = filename;
  options = nOptions;
  c = function;
}

void ConditionalStoryNode::readNode()
{
  //displaySound(sound);
  Serial.println(sound);
  tmrpcm.play(sound);
  // set storyChooser wait time!
  
  int i = c(*TRIGGERS);
  storyChooser -> queue(&options[i]);
}
