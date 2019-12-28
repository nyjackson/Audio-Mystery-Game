#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "StoryNodeEffect.h"

StoryNodeEffect::StoryNodeEffect(char filename[], flag function)
{
  sound = filename;
  doEffect = function;
}
void StoryNodeEffect::chooseOption(int i)
{
  doEffect(i, *TRIGGERS);
  StoryNode::chooseOption(i);
}
