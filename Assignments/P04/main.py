 ##############################################################################
 #  Author:           Bryce Koch
 #  Email:            brycekoch179@gmail.com
 #  Label:            P04
 #  Title:            Program 4
 #  Course:           CMPS 2143
 #  Semester:         Spring 2023
 #
 #  Description:      This program creates dice and implements methods
 #                    for rolling the dice. Allows the user to roll a set of
 #                    dice of any size and be able to know the sum, average,
 #                    max, and min of those dice rolls.
 #        
 #
 #  Files:            main.py
 #                    dice.py
 #                    
 ##############################################################################
import sys
import random
from dice import Die
from dice import Dice

##
 # dieTester
 #
 # Description:
 #      Allows the user to test their dice rolling skills by passing in the
 #      dice they have created and the number of tests they want to run to 
 #      see the results.
 #
 # Usage:
 #
 #      dieTester(d3, 10, "max")  // Rolls the d3 set of dice 10 times and
 #                                   returns the max value of each roll.
 #
 ##
def dieTester(die, runs=10, testType="sum"):
  # Single die
  if isinstance(die, Die):
    print(f"Testing {die.sides} sided die for {runs} rolls:")
    print("    [ ", end="")
    for i in range(runs):
      print(die.roll(), end=" ")
    print("]")
    # Multiple dice
  else:
    print(
      f"Rolling {len(die.dice)} {die.sides} sided die {runs} times to get the {testType} value:"
    )
    print("    [ ", end="")
    for i in range(runs):
      # Looking for the average.
      if testType == "avg":
        print(die.avg(), end=" ")
        # Looking for the min.
      elif testType == "min":
        print(die.min(), end=" ")
        # Looking for the max.
      elif testType == "max":
        print(die.max(), end=" ")
      else:
        print(die.sum(), end=" ")
    print("]")


if __name__ == '__main__':
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
