#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "StoryNodeEffect.h"

StoryNodeEffect::StoryNodeEffect(char filename[], int a, int b, int c, flag function)
{
  sound = filename;
  options = new int[3] {a, b ,c};
  doEffect = function;
}
void StoryNodeEffect::chooseOption(int i)
{
  doEffect(i, *TRIGGERS);
  StoryNode::chooseOption(i);
}
