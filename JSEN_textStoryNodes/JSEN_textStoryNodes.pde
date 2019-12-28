import processing.sound.*;
/*
 *
 *
 *
 */

StoryChooser storyChooser = new StoryChooser();
boolean[] TRIGGERS = new boolean[32];
StoryNode[] NODES = new StoryNode[200]; // notes start at 150
boolean START;

String STRING = "";

void setup()
{
  size(800, 600);
  textSize(25);
  fill(0);
  //background(255);
  noStroke();

  START = false;
  STRING = "Press space to start";
  //storyChooser.startStory(initialize());
  

  //noLoop();
}

void draw()
{
  fill(255);
  rect(0, 0, width, height);
  fill(0); // text color
  

  if (storyChooser.busy())
  {
    fill(100); // different text color
    storyChooser.update();
  }

  text(STRING, 50, 50, width - 100, height - 100);
}

void displayText(String s)
{
  STRING = "    " + s;
  //storyChooser.setWait(s.length() * 10); // makes wait time proportional to story length
  //redraw();
}

void displaySound(SoundFile file)
{
  if (file != null)
  {
    file.play();
    storyChooser.setWait((int) (file.duration() * 1000));
  }
  else storyChooser.setWait(0);
}

void keyPressed()
{
  if (!START && key == ' ')
      {
        STRING = "Loading . . . the game may take a few seconds to start";
      }
  if (!storyChooser.busy())
  {
    storyChooser.choose(key);
  }
}

void keyReleased()
{
  if (!START && key == ' ')
  {
        storyChooser.startStory(initialize());
        START = true;
        STRING = "Select an option with A, B, or C. \n \nPress R to repeat the audio.";
  }
}

class StoryChooser
{
  private StoryNode node; // a storyNode
  private boolean queued; // storyNode queued: will be next, no user inpt
  private boolean busy; // if story is currently doing something: actions can't be taken
  private long time; // keeps track of time, to measure time elapsed
  private int waitTime; // how long to wait

  public StoryChooser()
  {
    busy = false;
  }

  /** Determine whether actions can be taken on the story */
  boolean busy()
  {
    return this.busy;
  }

  void query(StoryNode node) // this node is current node. We want user input to decide next
  {
    this.node = node;
  }

  void queue(StoryNode node) // puts a node into queue, to be read when current finishes
  {
    queued = true; // now we have a queued element
    this.node = node;
  }

  void choose(char k)
  {
    if (node == null) return;
    
    time = millis();
    busy = true;
    
    switch (k)
    {
    case '1':
    case 'A':
    case 'a':
      node.chooseOption(0);
      break;
    case '2':
    case 'B':
    case 'b':
      node.chooseOption(1);
      break;
    case '3':
    case 'C':
    case 'c':
      node.chooseOption(2);
      break;
    case 'R': // for "repeat"
    case 'r':
      node.read();
      break;
    default:
      busy = false; // re-allow input
      return;
    }
  }

  public void setWait(int t) //set how long to wait
  {
    waitTime = t;
  }

  public void update() // updates based on the time
  {
    if (millis() - time > waitTime) // enough time has elapsed
    {
      if (queued) // if something is queued
      {
        queued = false;
        time = millis(); // start waiting again
        node.read();
      } 
      else // if nothing queued, then we need user input
      {
        busy = false;
      }
    }
    // Not enough time elapsed: otherwise, do nothing
  }
  
  public void startStory(StoryNode n)
  {
    node = n;
    busy = true;
    time = millis();
    node.read();
  }
}
