/*
 * StoryNode class:
 *   A single node or "room" in the story. Each node has a text portion and a three possible
 *   choices for the next node in the story.
 */
JSEN_textStoryNodes MAIN = this;
 
final int LENGTH = 3; // maximum number of options per node
final String AUDIO_EXT = ".wav"; // audio extension
final String TEXT_EXT = ".txt"; // text file extension
class StoryNode
{
  protected int[] options;
  SoundFile sound;
  String text;
  
  public StoryNode()
  {
    sound = null;
    options = new int[LENGTH];
  }
  public StoryNode(String filename, int[] opts)
  {
    // if not given filename, set sound to null
    if (filename == null || filename == "") this.sound = null;
    else 
    {
      this.sound = new SoundFile(MAIN, filename + AUDIO_EXT);
      this.text = join(loadStrings(filename + TEXT_EXT), "\n");
    }
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
    displayText(text);
    
    // choose next:
    storyChooser.query(this);
    
  }
}
