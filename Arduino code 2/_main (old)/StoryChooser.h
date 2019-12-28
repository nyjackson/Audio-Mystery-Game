#ifndef StoryChooser_h
#define StoryChooser_h

#include "Arduino.h"
#include "StoryNode.h"

class StoryChooser
{
  private:
    StoryNode* _node; // a storyNode
    boolean _queued; // storyNode queued: will be next, no user inpt
    boolean _busy; // if story is currently doing something: actions can't be taken
    long _time; // keeps track of time, to measure time elapsed
    int _waitTime; // how long to wait
  public:
    StoryChooser();
    // Determine whether actions can be taken on the story
    boolean busy();
    // this node is current node. We want user input to decide next
    void query(StoryNode* node);
    // puts a node into queue, to be read when current finishes
    void queue(StoryNode* node);
    void choose(int i);
    void setWait(int t); //set how long to wait
    void updateMe();
    void startStory(StoryNode* n);
};

#endif
