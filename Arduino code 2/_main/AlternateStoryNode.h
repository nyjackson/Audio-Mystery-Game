/*
  AlternateStoryNode class:
     Basically a standard StoryNode, except that it has multiple possible audio files to play.
     They are differentiated, like "filename_a", "filename_b", and so on.
     The strCond function determines what file to play (it should ouptut a file name, given the input
     TRIGGERS boolean array)
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
    AlternateStoryNode(char filename[], int a, int b, int c, strCond function);
    void readNode();
  private:
    strCond chooseSound;
};

#endif
