#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "CascadingStoryNode.h"


CascadingStoryNode::CascadingStoryNode(char text[], StoryNode next)
{
  sound = text;
  options[0] = next;
}

void CascadingStoryNode::readNode()
{
  //displaySound(sound);
  Serial.println(sound);
  tmrpcm.play(sound);
  // set storyChooser wait time!
  
  storyChooser -> queue(&options[0]);
}

void CascadingStoryNode::setNext(StoryNode next)
{
  options[0] = next;
}
