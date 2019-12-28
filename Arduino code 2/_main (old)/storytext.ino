#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"
#include "StoryNodeEffect.h"
#include "AlternateStoryNode.h"
#include "CascadingStoryNode.h"
#include "ConditionalStoryNode.h"


const int len = 4;
StoryNode* allNodes[len];
void asn(int a, int b, int c, int d)
{
  allNodes[a]->setNodes(*allNodes[a], *allNodes[b], *allNodes[c]);
}

int counter = 0;
const int JENNY_BODY = counter++;
const int HOUSE_PRINTS = counter++;
const int SPOKE_PARENTS = counter++;
const int PREGNANCY_TEST = counter++;
const int PARK_PHOTO = counter++;

StoryNode* initialize()
{
  // initialize
  /*for (int i = 1; i <= len; i++)
  {
    allNodes[i] =  new StoryNode("000" + (i+2) + ".wav");
  } */
  allNodes[1] = new StoryNode("0003.wav");
  allNodes[4] = new StoryNode("0006.wav");
  
  // special set-up for special nodes
  allNodes[2] =  new AlternateStoryNode("0004.wav", [] (boolean triggers[])
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
  allNodes[3] =  new StoryNodeEffect("0005.wav", [] (int i, boolean triggers[])
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


  asn(1, 2, 3, 4);
  asn(2, 1, 3, 4);
  asn(3, 2, 1, 4);
  asn(4, 1, 3, 2);
 /* asn(5, 6, 7, 8);
  asn(6, 44, 7, 8);
  asn(7, 6, 8, 23);
  asn(8, 6, 7, 23);
  asn(9, 10, 11, 23);
  asn(10, 11, 10, 23);
  asn(11, 12, 10, 23);
  asn(12, 51, 24, 25);
  asn(13, 27, 35, 14); */
  return allNodes[1];
} 
