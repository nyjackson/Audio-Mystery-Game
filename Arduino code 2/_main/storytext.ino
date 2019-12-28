#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "StoryNodeEffect.h"
#include "AlternateStoryNode.h"
#include "CascadingStoryNode.h"
#include "ConditionalStoryNode.h"

//typedef char (*strCond)(boolean val[]);

// create a storyNode:
void sn(int id, char filename[], int a, int b, int c)
{
  int opts[] = {a, b, c};
  NODES[id] = new StoryNode(filename, opts);
}

// create an alternateStoryNode (standard node with two text options
/*void asn(int id, char filename[], int a, int b, int c, strCond function)
  {
  int opts[] = {a, b, c};
  NODES[id] = new AlternateStoryNode(filename, opts, function);
  }*/

// create a cascadingStoryNode (node that always sends you to a following node)
void casn(int id, char filename[], int next)
{
  NODES[id] = new CascadingStoryNode(filename, next);
}

// create a conditionalStoryNode (node that determines next by checking TRIGGERS)
/*void cosn(int id, char filename[], int a, int b, int c, conditional function)
  {
  int opts[] = {a,b,c};
  NODES[id] = new ConditionalStoryNode(filename, opts, function);
  }*/


int counter = 0;
const int JENNY_BODY = counter++;
const int HOUSE_PRINTS = counter++;
const int SPOKE_PARENTS = counter++;
const int PREGNANCY_TEST = counter++;
const int PARK_PHOTO = counter++;

StoryNode* initialize()
{
  int opts[] = {0, 0, 0}; // size-3 array of ints to store stuff
  // initialize
  sn(1, "start.wav", 2, 3, 4);
  sn(4, "smplace.wav", 1, 3, 2);
  NODES[2] = new AlternateStoryNode("0004.wav", 1, 3, 4, [] (boolean triggers[])
  {
    if (triggers[JENNY_BODY]) // JENNY'S BODY
    {
      // enter house
      // set FOOTPRINTS IN HOUSE flag
      triggers[HOUSE_PRINTS] = true;
      return "0004.wav";
    }
    else return "0004.wav";
  });
  NODES[3] =  new StoryNodeEffect("0005.wav", 2, 1, 4, [] (int i, boolean triggers[])
  {
    // speak with parents
    // set SPOKE WITH PARENTS flag
    triggers[SPOKE_PARENTS] = true;
  });
  /*  allNodes[8] =  new StoryNodeEffect("8.wav", [] (int i, boolean triggers[])
    {
      // investigate bathroom
      triggers[PREGNANCY_TEST] = true;
    });
    allNodes[12] =  new StoryNodeEffect("12.wav", [] (int i, boolean triggers[])
    {
      // investigate photo location (from basement)
      triggers[PARK_PHOTO] = true;
    }); */


  /*  asn(1, 2, 3, 4);
    asn(2, 1, 3, 4);
    asn(3, 2, 1, 4);
    asn(4, 1, 3, 2);
    asn(5, 6, 7, 8);
    asn(6, 44, 7, 8);
    asn(7, 6, 8, 23);
    asn(8, 6, 7, 23);
    asn(9, 10, 11, 23);
    asn(10, 11, 10, 23);
    asn(11, 12, 10, 23);
    asn(12, 51, 24, 25);
    asn(13, 27, 35, 14); */
  return NODES[1];
}

typedef boolean (*check) (boolean val[]);

class ClueNode : public StoryNode
{
  private:
    check hasNote;
  public:
    ClueNode::ClueNode(char filename[], int next, check function)
    {
      sound = filename;
      options[0] = next;
      hasNote = function;
    }
    void ClueNode::readNode()
    {
      if (hasNote(*TRIGGERS))
      {
        tmrpcm.play(sound);
        // set storyChooser wait time!
      }
      //displaySound(sound);
      Serial.println(sound);

      storyChooser -> queue(NODES[options[0]]);
    }
};
