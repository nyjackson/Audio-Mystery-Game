#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "ConditionalStoryNode.h"

ConditionalStoryNode::ConditionalStoryNode (char filename[], int a, int b, int c, conditional function)
{
  sound = filename;
  options = new int[3] {a, b ,c};
  c = function;
}

void ConditionalStoryNode::readNode()
{
  //displaySound(sound);
  Serial.println(sound);
  tmrpcm.play(sound);
  // set storyChooser wait time!
  
  int i = c(*TRIGGERS);
  storyChooser -> queue(NODES[options[i]]);
}
