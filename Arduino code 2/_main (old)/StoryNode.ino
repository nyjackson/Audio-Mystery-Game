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
  (options) = new StoryNode[LENGTH];
}

StoryNode::StoryNode(char fileId[])
{
  sound = fileId;
  (options) = new StoryNode[LENGTH];
}

/* Assign other nodes as options of this node.
   This isn't done in the constructor so that we can have nodes point to
   themselves or to previous story nodes
*/
void StoryNode::setNode(int i, StoryNode opt)
{
  if (i < LENGTH)
  {
    options[i] = opt;
  }
}

void StoryNode::setNodes(StoryNode nodes[])
{
  //if (options.length <= LENGTH) // allow for fewer than LENGTH choices
  //{ //we're just not going to make this check
  for (int i = 0; i < LENGTH; i++)
  {
     options[i] = nodes[i];
  }
  //}
}

// hardcoded constructor for exactly three choices--for convenience
void StoryNode::setNodes(StoryNode a, StoryNode b, StoryNode c)
{
  options[0] = a;
  options[1] = b;
  options[2] = c;
}

// reads the chosen option
void StoryNode::chooseOption(int i)
{
  //if (i < LENGTH /*&& options[i]*/) // canot do null check?
  options[i].readNode();
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
