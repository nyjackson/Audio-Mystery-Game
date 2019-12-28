/*
   StoryNodeEffect class:
     A regular storyNode that runs its doEffect(int i) method when read (and a choice selected).
     The doEffect method should set or change some variable for a later ConditionalStoryNode
     to check. The doEffect method is abstract, so must be defined for each implementation.
*/
#ifndef StoryNodeEffect_h
#define StoryNodeEffect_h

#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"

typedef void (*flag)(int i, boolean val[]);

class StoryNodeEffect : public StoryNode
{
  public:
    void chooseOption(int i);
    StoryNodeEffect(char filename[], int a, int b, int c, flag function);
  protected:
    flag doEffect; // i is the option that was chosen
};

#endif
