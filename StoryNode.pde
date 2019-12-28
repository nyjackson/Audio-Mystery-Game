/*
 * StoryNode class:
 *   A single node or "room" in the story. Each node has a text portion and a three possible
 *   choices for the next node in the story.
 */
JSEN_StoryNodes_v2 MAIN = this;
 
final int LENGTH = 3; // maximum number of options per node
class StoryNode
{
  protected int[] options;
  SoundFile sound;
  
  public StoryNode()
  {
    sound = null;
    options = new int[LENGTH];
  }
  public StoryNode(String filename, int[] opts)
  {
    // if not given filename, set sound to null
    if (filename == null || filename == "") this.sound = null;
    else this.sound = new SoundFile(MAIN, filename);
    this.options = opts;
  }
  
  // reads the chosen option
  public void chooseOption(int i)
  {
    if (i < options.length && options[i] != 0)
      NODES[options[i]].read();
  }
  
  public void read()
  {
    // read text
    displaySound(sound);
    
    // choose next:
    storyChooser.query(this);
    
  }
}
