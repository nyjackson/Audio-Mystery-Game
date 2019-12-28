/*
 * Text of all story nodes
 *
 */

void sn(int id, String filename, int a, int b, int c)
{
  NODES[id] = new StoryNode(filename, new int[] {a, b, c});
}

void casn(int id, String filename, int next)
{
  NODES[id] = new CascadingStoryNode(filename, next);
}

int counter = 0;
final int JENNY_BODY = counter++;
final int HOUSE_PRINTS = counter++;
final int SPOKE_PARENTS = counter++;
final int PREGNANCY_TEST = counter++;
final int PARK_PHOTO = counter++;
final int PARK_SPOT = counter++;
final int CAR_SHOVEL = counter++;
final int AFFAIR = counter++;
final int ABUSE = counter++;
final int BLOODY_ROCK = counter++;
final int BOB_BODY = counter++;
final int BOB_PLAN = counter++;
final int TICKET_DATE = counter++;
final int OVERPROTECTIVE = counter++;
final int GARDEN_PRINTS = counter++;
final int ELLIOT_PRINTS = counter++;
final int SPLINTERS = counter++;
final int CONFESSION = counter++;
final int PICKED_FLOWER = counter++;
final int CHARLOTTE = counter++;

StoryNode initialize()
{
  sn(0, "Introduction", 1, 1, 1);
  sn(1, "1", 2, 3, 4); // start
  NODES[2] = new AlternateStoryNode("2", new int[] {5, 9, 13}) {
      public String chooseSound()
      {
        if (TRIGGERS[JENNY_BODY])
  {
    TRIGGERS[HOUSE_PRINTS] = true;
    return "2";
  } else return "2";
}
};
NODES[3] = new FlagNode("3", new int[] {24, 25, 4}, SPOKE_PARENTS);
sn(4, "4", 38, 44, 42);
sn(5, "5", 6, 7, 8);
sn(6, "6", 44, 7, 8);
sn(7, "7", 6, 8, 23);
NODES[8] = new FlagNode("8", new int[] {6, 7, 23}, PREGNANCY_TEST);
sn(9, "9", 10, 11, 23);
sn(10, "10", 11, 10, 23);
sn(11, "11", 12, 10, 23);
sn(12, "12", 51, 24, 25);
sn(13, "13", 27, 35, 14);
sn(14, "14", 15, 19, 22);
//NODES[15] = new Story
NODES[15] = new ConditionalStoryNode("15", new int[] {16, 17, 0}) {
    public int chooseWhich()
    {
      return (TRIGGERS[PREGNANCY_TEST]) ? 16 : 17;
}
};
sn(16, "15a", 18, 20, 22);
sn(17, "15b", 19, 20, 22);
NODES[18] = new FlagNode("18", new int[] {19, 21, 22}, AFFAIR);
NODES[19] = new FlagNode("19", new int[] {20, 21, 22}, ABUSE);
NODES[20] = new FlagNode("20", new int[] {19, 21, 22}, OVERPROTECTIVE);
sn(21, "21", 20, 19, 22);
sn(22, "22", 27, 35, 5);
sn(23, "23", 5, 9, 13);
sn(24, "24", 27, 25, 26);
sn(25, "25", 35, 24, 26);

sn(26, "26", 74, 2, 4);
NODES[27] = new ConditionalStoryNode("27", new int[] {28, 29, 0}) {
    public int chooseWhich()
    {
      TRIGGERS[CHARLOTTE] = true;
return (TRIGGERS[PREGNANCY_TEST]) ? 28 : 29;
}
};
sn(28, "27a", 30, 31, 34);
sn(29, "27b", 33, 31, 34);
NODES[30] = new StoryNodeEffect("30", new int[] {31, 32, 34}) {
    public void doEffect(int i)
    {
      TRIGGERS[ABUSE] = true;
TRIGGERS[AFFAIR] = true;
}
};
NODES[31] = new FlagNode("31", new int[] {32, 33, 34}, AFFAIR);
NODES[32] = new FlagNode("32", new int[] {33, 31, 34}, ABUSE); 
NODES[33] = new FlagNode("33", new int[] {31, 32, 34}, PREGNANCY_TEST);
sn(34, "34", 27, 35, 5);
casn(35, "35", 36);
NODES[36] = new AlternateStoryNode("35a", new int[] {63, 27, 5}) {
    public String chooseSound()
    {
      return (TRIGGERS[CHARLOTTE]) ? "35a" : "35b";
}
};
sn(38, "38", 41, 39, 40);
sn(39, "39", 41, 39, 40);
sn(40, "40", 44, 42, 73);
NODES[41] = new FlagNode("41", new int[] {42, 39, 40}, SPLINTERS);
NODES[42] = new FlagNode("42", new int[] {51, 63, 43}, CAR_SHOVEL);
sn(43, "43", 44, 38, 73);
NODES[44] = new AlternateStoryNode("44", new int[] {48, 46, 50}) {
    public String chooseSound()
    {
      if (TRIGGERS[JENNY_BODY] && TRIGGERS[GARDEN_PRINTS])
      {
        return "44";
      }
      TRIGGERS[GARDEN_PRINTS] = true;
      return "45";
    } 
  };
NODES[46] = new AlternateStoryNode("46", new int[] {48, 46, 50}) {
    private int vegetables = 0;
public String chooseSound()
{
  if (vegetables < 3)
  {
    vegetables++;
    return "47";
  } else return "46";
}
};
NODES[48] = new ConditionalStoryNode("48", new int[] {111, 112, 0}) {
    public int chooseWhich()
    { //111 if found body, 112 if not
    // ideally, we would also have separate audio for after Bob's body is found (and the garden is torn up?)
      return (TRIGGERS[JENNY_BODY] && !TRIGGERS[BOB_BODY]) ? 111 : 112;
}
};
NODES[49] = new CascadingStoryNode("49", 74) {
  public void read()
  {
    TRIGGERS[BOB_BODY] = true;
    super.read();
  }
};
sn(50, "50", 38, 42, 73);
NODES[51] = new AlternateStoryNode("51", new int[] {54, 55, 60}) {
    public String chooseSound()
    {
      if (TRIGGERS[PARK_SPOT]) return "53";
      else if (TRIGGERS[PARK_PHOTO]) return "52";
      else return "51"; // else
}
};
sn(54, "54", 55, 60, 73);
NODES[55] = new FlagNode("55", new int[] {59, 56, 73}, BLOODY_ROCK);
NODES[56] = new FlagNode("56", new int[] {59, 57, 73}, PICKED_FLOWER);
sn(57, "57", 59, 58, 73);
sn(58, "58", 59, 58, 73);
sn(59, "59", 62, 60, 73);
sn(60, "60", 62, 61, 55);
sn(61, "61", 62, 55, 54);
NODES[62] = new FlagNode("62", new int[] {54, 55, 73}, JENNY_BODY);
sn(63, "63", 64, 67, 73);
NODES[64] = new FlagNode("64", new int[] {67, 65, 73}, BOB_PLAN);
NODES[65] = new FlagNode("65", new int[] {67, 66, 73}, TICKET_DATE);
sn(66, "66", 67, 51, 73);
sn(67, "67", 68, 71, 72);
sn(68, "68", 69, 70, 72);
NODES[69] = new FlagNode("69", new int[] {70, 71, 72}, PARK_SPOT);
sn(70, "70", 69, 71, 72);
sn(71, "71", 69, 70, 72);
sn(72, "72", 64, 51, 73);
// RETURN TO THE HOUSE
NODES[73] = new ConditionalStoryNode("73", new int[] {102, 101, 0}) {
    public int chooseWhich()
    {
      return TRIGGERS[JENNY_BODY] ? 102 : 101;
}
};
sn(74, "74", 103, 97, 73);
sn(75, "75", 76, 110, 109);
sn(76, "76", 77, 110, 109);
sn(77, "77", 78, 110, 109);
sn(78, "78", 80, 81, 79);
sn(79, "79", 110, 109, 87);
/* Technically, the following two (80 & 81) should be AlternateStoryNodes with two audio files:
 one if Bob's body has already been found, and one in which you exhume Bob. Either way, they both
 also set CONFESSION and BOB_BODY to true */
NODES[80] = new AlternateStoryNode("80", new int[] {84, 85, 87}) {
  public String chooseSound()
  {
    TRIGGERS[CONFESSION] = true;
    if (TRIGGERS[BOB_BODY])
    {
      return "80"; // audio file for Bob's body already found
    }
    else
    {
      TRIGGERS[BOB_BODY] = true;
      return "80"; // audio for Bob's body found when Elliot confesses
    }
  }
};
NODES[81] = new AlternateStoryNode("81", new int[] {84, 85, 87}) {
  public String chooseSound()
  {
    TRIGGERS[CONFESSION] = true;
    if (TRIGGERS[BOB_BODY])
    {
      return "81"; // audio file for Bob's body already found
    }
    else
    {
      TRIGGERS[BOB_BODY] = true;
      return "81"; // audio for Bob's body found when Elliot confesses
    }
  }
};
sn(82, "82", 76, 109, 87); // hands, none
sn(83, "83", 86, 110, 87); // shoes, none
sn(84, "84", 86, 85, 87); // hands, confess (from 110)
sn(85, "85", 86, 84, 87); // shoes, confess (from 109)
sn(86, "86", 76, 110, 109);
sn(87, "87", 75, 88, 102);
NODES[88] = new AlternateStoryNode("89", new int[] {90, 93, 102}) {
    public String chooseSound()
    { // 88 has flowers, 89 does not
      return TRIGGERS[PICKED_FLOWER] ? "88" : "89";
}
};
sn(90, "90", 91, 93, 96);
sn(91, "91", 92, 93, 96);
NODES[92] = new CascadingStoryNode("92", 102) {
  public void read()
  {
    TRIGGERS[ABUSE] = true;
    super.read();
  }
};
NODES[93] = new ConditionalStoryNode("93", new int[] {107, 108, 0}) 
  {
    public int chooseWhich()
    {
      return TRIGGERS[ABUSE] ? 107 : 108;
}
};
sn(94, "94", 90, 95, 96);
sn(95, "95", 90, 93, 96);
sn(96, "96", 75, 102, 88);
// 97 is go over notes:
NODES[97] = new CascadingStoryNode("97", 150);
// End of notes
sn(98, "97a", 103, 99, 97 /* or 150?*/);

sn(99, "99", 74, 100, 73);
sn(100, "100", 75, 88, 73);
sn(101, "101", 2, 3, 4);
sn(102, "102", 99, 2, 4); // KEEP SEARCHING FOR CLUES
NODES[103] = new ConditionalStoryNode(null, new int[] {104, 105, 106}) {
    public int chooseWhich()
    {
      if (TRIGGERS[JENNY_BODY] && TRIGGERS[CONFESSION])
  return 104; // win
if (TRIGGERS[JENNY_BODY] && TRIGGERS[PREGNANCY_TEST] && TRIGGERS[AFFAIR] &&
  (TRIGGERS[PARK_PHOTO] || TRIGGERS[PARK_SPOT]) &&
  TRIGGERS[BOB_PLAN] && TRIGGERS[CAR_SHOVEL] && !TRIGGERS[BOB_BODY])
  return 105; // end game
return 106; // else, don't actually know
}
};
sn(104, "103a", 199, 199, 199);
sn(105, "103b", 199, 199, 199);
NODES[106] = new CascadingStoryNode("103c", 74);
sn(107, "93a", 94, 95, 96); // options from 93
sn(108, "93b", 90, 95, 96);
// ask shoes
NODES[109] = new ConditionalStoryNode(null, new int[] {83, 85, 0}) {
    public int chooseWhich()
    {
      return TRIGGERS[CONFESSION] ? 85 : 83;
}
};
// ask hands
NODES[110] = new ConditionalStoryNode(null, new int[] {82, 84}) {
    public int chooseWhich()
    {
      return TRIGGERS[CONFESSION] ? 84 : 82;
}
};
// inspect garden footprints: found body
sn(111, "48a", 49, 46, 50);
// inspect garden footprints: not found body
sn(112, "48b", 48, 46, 50);


// NODES[199] is the end node
NODES[199] = new StoryNode(null, new int[] {199, 199, 199});

// all the clue notes
int i = 150;
NODES[i] = new SimpleClue("Clue_PregTest", ++i, PREGNANCY_TEST);
NODES[i] = new ClueNode("Clue_ParkPhoto", ++i) {
  public boolean hasNote() {
    return (TRIGGERS[PARK_PHOTO] || TRIGGERS[PARK_SPOT]);
  }
};
NODES[i] = new SimpleClue("Clue_BobPark", ++i, PARK_SPOT);
NODES[i] = new SimpleClue("Clue_ShovelCar", ++i, CAR_SHOVEL);
NODES[i] = new SimpleClue("Clue_Affair", ++i, AFFAIR);
NODES[i] = new SimpleClue("Clue_Abusive", ++i, ABUSE);
NODES[i] = new SimpleClue("Clue_BloodyRock", ++i, BLOODY_ROCK);
NODES[i] = new SimpleClue("Clue_JennyBody", ++i, JENNY_BODY);
NODES[i] = new ClueNode("Clue_Footprints", ++i) {
  public boolean hasNote() {
    return (TRIGGERS[HOUSE_PRINTS] && ! TRIGGERS[BOB_BODY]);
  }
};
NODES[i] = new SimpleClue("Clue_BobBody", ++i, BOB_BODY);
NODES[i] = new SimpleClue("Clue_EscapePlan", ++i, BOB_PLAN);
NODES[i] = new ClueNode("Clue_TicketDate", ++i) {
  public boolean hasNote() {
    return (TRIGGERS[TICKET_DATE] && ! TRIGGERS[BOB_BODY]);
  }
};
NODES[i] = new SimpleClue("Clue_ElliotOverprotective", ++i, OVERPROTECTIVE);
NODES[i] = new SimpleClue("Clue_FootprintsGarden", ++i, GARDEN_PRINTS);
NODES[i] = new SimpleClue("Clue_ElliotMatchingFootprints", ++i, ELLIOT_PRINTS);
NODES[i] = new SimpleClue("Clue_BobsBodyGarden", ++i, BOB_BODY);
NODES[i] = new SimpleClue("Clue_Splinters", ++i, SPLINTERS);
NODES[i] = new SimpleClue("Clue_Confession", 98, CONFESSION);



return NODES[0];
}
