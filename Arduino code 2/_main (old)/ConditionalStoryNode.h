/*
  ConditionalStoryNode class:
     A storyNode that selects the next node not based on user input, but on
     some other criterion. The class is abstract, so the method (chooseWhich())
     must be defined for each implementation. chooseWhich() determines which storyNode
     will be the next one in the story.
*/
#ifndef ConditionalStoryNode_h
#define ConditionalStoryNode_h

#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
typedef int (*conditional)(boolean val[]);
//#include "STD.h"

class ConditionalStoryNode : public StoryNode
{
  public:
    int chooseWhich();
    ConditionalStoryNode(char filename[], conditional function);
    ConditionalStoryNode(char filename[], conditional function, StoryNode options[]);
    void readNode();
  private:
    conditional c;
};

#endif
