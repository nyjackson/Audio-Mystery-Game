#include "Arduino.h"
#include "StoryNode.h"
#include "StoryChooser.h"

StoryChooser::StoryChooser()
{
  _busy = false;
  _node = 0;
  _time = 0;
}

// Determine whether actions can be taken on the story
boolean StoryChooser::busy()
{
  return _busy;
}

void StoryChooser::query(StoryNode* node) // this node is current node. We want user input to decide next
{
  _node = node;
}

void StoryChooser::queue(StoryNode* node) // puts a node into queue, to be read when current finishes
{
  _queued = true; // now we have a queued element
  _node = node;
}

void StoryChooser::choose(int i)
{

  _time = millis();
  _busy = true;
  _waitTime = 3000; // safe value for waiting (3 secs)
 if (_node == 0) return; // no null checks
 if (i < 3){
    _node-> chooseOption(i);
  }
  else { // i is 3 (repeat)
    _node-> readNode();
  }
}

void StoryChooser::setWait(int t) //set how long to wait
{
  _waitTime = t;
}

void StoryChooser::updateMe() // updates based on the time
{
  if (millis() - _time > _waitTime) // enough time has elapsed
  {
    if (_queued) // if something is queued
    {
      _queued = false;
      _time = millis(); // start waiting again
      _node -> readNode();
    }
    else // if nothing queued, then we need user input
    {
      _busy = false;
      ACCEPT_INPUT = true;
    }
  }
  // Not enough time elapsed: otherwise, do nothing
}

void StoryChooser::startStory(StoryNode* n)
{
  _node = n;
  _busy = true;
  _time = millis();
  _node -> readNode();
}
/*
  void setup()
  {
  size(800, 600);
  textSize(25);
  fill(0);
  //background(255);
  noStroke();

  StoryNode START = makeStory2();

  storyChooser.startStory(START);
  //start.readNode();

  //noLoop();
  }

  void displayText(String s)
  {
  STRING = "    " + s;
  //storyChooser.setWait(s.length() * 10); // makes wait time proportional to story length
  //redraw();
  }

  /*void displaySound(SoundFile file)
  {
  file.play();
  storyChooser.setWait((int) (file.duration() * 1000));
  }*/
/*
  void keyPressed()
  {
  if (START != null && key == ' ')
  {
    storyChooser.startStory(START);
  }
  if (!storyChooser.busy())
  {
    storyChooser.choose(key);
  }
  }/**/
