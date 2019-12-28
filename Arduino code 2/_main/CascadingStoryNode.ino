#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "CascadingStoryNode.h"


CascadingStoryNode::CascadingStoryNode(char text[], int next)
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
  
  storyChooser -> queue(NODES[options[0]]);
}
