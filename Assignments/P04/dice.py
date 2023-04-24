import sys
import random

##
 # Die
 #
 # Description:
 #      Creates a die with 6 sides by default or any amount if passed in by
 #      user. 
 #
 # Usage:
 #
 #      d1 = Die()             // Creates an instance of a Die.
 #
 ##
class Die(object):

   ##
   # def __init__
   #
   # Description:
   #      Constructor for Die class.
   #
   # Params:
   #      int   : Number of sides on the die.
   ##
  def __init__(self, sides=None):
    if not sides:
      # Default constructor
      self.sides = 6
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides

##
   # def roll
   #
   # Description:
   #      Rolls the die and returns the value rolled.
   #
   # Returns:
   #      The roll value.
   ##
  def roll(self):
    values = [x for x in range(self.sides)]
    # Rolling the die
    random.shuffle(values)

    return values[0] + 1

  def __str__(self):
    return f"[sides: {self.sides}]"

##
 # Dice
 #
 # Description:
 #      Creates multiple instances of die and stores them together. Allows the
 #      the iser to roll multiple die at a time. Can find the sum, average, 
 #      max, and min of all the rolls.
 #
 # Usage:
 #
 #      d3 = Dice(20,3)           // Creates an set of 3 20-sided die.
 #
 ##
class Dice:

  ##
   # def __init__
   #
   # Description:
   #      Constructor for the Dice class.
   #
   # Params:
   #      sides      : The number of sides on the die.
   #      num_dice   : The amount of die in Dice.
   ##
  def __init__(self, sides=None, num_dice=1):
    if not sides:
      # Fail check
      print("Need to pass in sides!!!")
      sys.exit()
    
    self.sides = sides
    
    # create a container
    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

  ##
   # def sum
   #
   # Description:
   #      Adds the total roll value for all of the die in dice.
   #
   # Returns:
   #      The total value of the rolls.
   ##
  def sum(self):
    total = 0
    for d in self.dice:
      # Adds up the roll of each die and stores it in total.
      total += d.roll()

    return total

  ##
   # def max
   #
   # Description:
   #      Finds the maximum possible roll value of the dice.
   #
   # Returns:
   #      The maximum roll value.
   ##
  def max(self):
    tot = 0
    for d in self.dice:
      tot += d.sides
    return tot

  ##
   # def min
   #
   # Description:
   #      Finds the minimum possible roll value of the dice.
   #
   # Returns:
   #      The minimum roll value.
   ##
  def min(self):
    tot = 0
    for d in self.dice:
      tot += 1
    return tot

  ##
   # def avg
   #
   # Description:
   #      Finds the average of the roll of the dice.
   #
   # Returns:
   #      The average value.
   ##
  def avg(self):
    # Get the sum of the rolls.
    average = self.sum()
    # Get the amount of dice being rolled.
    rolls = len(self.dice)
    # Divide the total of the rolls by number of dice to get average.
    average = average/rolls
    return average

##
   # def roll
   #
   # Description:
   #      Finds the value of the roll of the dice.
   #
   # Params:
   #      string   : The type of roll we are looking for.
   #
   # Returns:
   #      The roll of the dice.
   ##
  def roll(self, rollType=None):

    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()

  ##
   # def roll
   #
   # Description:
   #      Creates a string representation of dice.
   #
   # Returns:
   #      A string of dice.
   ##
  def __str__(self):
    s = "Dice:[\n    "
    for d in self.dice:
      s = s + str(d)
    s = s + "\n]\n"
    return s
