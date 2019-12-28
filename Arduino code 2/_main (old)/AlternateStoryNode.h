/*
  AlternateStoryNode class:
     Basically a standard StoryNode, except that it has multiple possible audio files to play.
     They are differentiated by "filename_a", "filename_b", and so on.
*/
#ifndef AlternateStoryNode_h
#define AlternateStoryNode_h

#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"

typedef char (*strCond)(boolean val[]);

class AlternateStoryNode : public StoryNode
{
  public:
    AlternateStoryNode(char filename[], strCond function);
    void readNode();
  private:
    strCond chooseSound;
};

#endif
