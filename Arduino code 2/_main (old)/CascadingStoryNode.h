/*
   CascadingStoryNode class:
     A storyNode that doesn't have any choices about what the next element will be.
     It immediately jumps to the next node
*/

#ifndef CascadingStoryNode_h
#define CascadingStoryNode_h

#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"

class CascadingStoryNode : public StoryNode
{
  public:
    CascadingStoryNode(char text[], StoryNode next);
    void readNode();
    void setNext(StoryNode next);
};

#endif
