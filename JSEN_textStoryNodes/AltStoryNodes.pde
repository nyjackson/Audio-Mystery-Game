/*
 * AlternateStoryNode class:
 *   Basically a standard StoryNode, except that it has multiple possible audio files to play.
 *   They are differentiated, like "filename_a", "filename_b", and so on.
 *   The strCond function determines what file to play (it should ouptut a file name, given the input
 *   TRIGGERS boolean array)
 *
 * CascadingStoryNode class:
 *   A storyNode that doesn't have any choices about what the next element will be. 
 *   It immediately jumps to the next node
 *
 * ConditionalStoryNode class:
 *   A storyNode that selects the next node not based on user input, but on
 *   some other criterion. The class is abstract, so the method (chooseWhich())
 *   must be defined for each implementation. chooseWhich() determines which storyNode
 *   will be the next one in the story.
 *
 * StoryNodeEffect class:
 *   A regular storyNode that runs its doEffect(int i) method when read (and a choice selected). 
 *   The doEffect method should set or change some variable for a later ConditionalStoryNode
 *   to check. The doEffect method is abstract, so must be defined for each implementation.
 */

abstract class AlternateStoryNode extends StoryNode
{
  abstract String chooseSound();
  
  public AlternateStoryNode(String text, int[] options)
  {
    super(text, options);
  }
  
  public void read()
  {
    String filename = chooseSound();
    sound = new SoundFile(MAIN, filename);
    text = join(loadStrings(filename + TEXT_EXT), "\n");
    displaySound(sound);
    displayText(text);
    storyChooser.query(this);
  }
}

class CascadingStoryNode extends StoryNode
{
  public CascadingStoryNode(String text, int next)
  {
    super(text, new int[] {next, 0, 0});
  }

  public void read()
  {
    displaySound(sound);
    displayText(text);
    storyChooser.queue(NODES[options[0]]);
  }
}

abstract class ConditionalStoryNode extends StoryNode
{
  abstract int chooseWhich();

  public ConditionalStoryNode(String filename, int[] options)
  {
    super(filename, options);
  }

  public void read()
  {
    displaySound(sound);
    displayText(text);
    int i = chooseWhich();
    if (i != 0)
    {
      storyChooser.queue(NODES[i]);
    }
  }
}

abstract class StoryNodeEffect extends StoryNode
{
  public StoryNodeEffect(String filename, int[] options)
  {
    super(filename, options);
  }

  public void chooseOption(int i)
  {
    doEffect(i);
    super.chooseOption(i);
  }

  abstract protected void doEffect(int i); // i is the option that was chosen
}

abstract class ClueNode extends StoryNode
{
  abstract boolean hasNote();
  
  public ClueNode(String filename, int next)
  { 
    super(filename, new int[] {next, 0, 0});
  }
  
  void read()
  {
    if (hasNote())
    {
      displaySound(sound);
      displayText(text);
    }
    else displaySound(null);
    
    storyChooser.queue(NODES[options[0]]);
  }
}

class SimpleClue extends ClueNode
{
  private int bool;
  public SimpleClue(String filename, int next, int bool)
  {
    super(filename, next);
    this.bool = bool;
  }
  boolean hasNote()
  {
    return TRIGGERS[bool];
  }
}

class FlagNode extends StoryNodeEffect
{
  private int bool;
  public FlagNode(String filename, int[] options, int bool)
  {
    super(filename, options);
    this.bool = bool;
  }
  void doEffect(int i)
  {
    TRIGGERS[bool] = true;
  }
}
