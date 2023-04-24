## P04 - Program 4
### Bryce Koch
### Description:

Program implements a dice rolling system that allows the user to roll a single die or multiple die at once. The
result of the roll is given back to the user or the user can request the maximum, minimum, average, and sum of
the  rolls if the user has multiple dice being rolled. This program is setting up the dice rolling feature for
our DND program.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Main.py](https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/P04/main.py)         | Main driver of my project that launches the dice rolling.      |
|   2   | [Dice.py](https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/P04/dice.py) | Holds all of the Dice and Die classes and methods.         |

### Instructions

- Make sure you install library sys and random.
- My program expects two parameters to be placed in the object creation of Dice.
- Also requires the input for number of sides on the die to be an int.

- Example Command:
    - d3 = Dice(10, 5)
    - dieTester(d3, 10, "max")
