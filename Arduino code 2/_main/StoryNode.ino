/*
   StoryNode class:
     A single node or "room" in the story. Each node has a text portion and a three possible
     choices for the next node in the story.
*/
#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include <TMRpcm.h>

const int LENGTH = 3; // maximum number of options per node

StoryNode::StoryNode()
{
  (options) = new int[LENGTH];
}

StoryNode::StoryNode(char fileId[], int opts[])
{
  sound = fileId;
  (options) = opts;
}

StoryNode::StoryNode(char fileId[], int a, int b, int c)
{
  sound = fileId;
  options = new int[3] {a, b ,c};
}

// reads the chosen option
void StoryNode::chooseOption(int i)
{
  //if (i < LENGTH /*&& options[i]*/) // canot do null check?
  NODES[options[i]] -> readNode();
}

void StoryNode::readNode()
{
  // read text
  Serial.println(sound);
  tmrpcm.play(sound);
  // set storyChooser wait time!
  // choose next:
  storyChooser -> query(this);

}
