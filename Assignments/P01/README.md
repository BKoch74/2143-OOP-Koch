## P01 - Vector Class
### Bryce Koch
### Description:

My program implements a class to create a linked list based vector. The class accepts integers, integer-filled arrays,
other vectors defined by my class, and input files containing integers. Methods in my class allow integers to be pushed 
anywhere in the vector, and other vectors pushed to the front or back of this vector. Integers can also be pushed in a
vector of increasing or decreasing order. Integers can be popped off of the front and rear of the vector. Using the popAt
method, an integer can be located at any point in the vector, if it exists in the vector, and be popped off and returned.
An integer's location in the array can be found using the find method. Finally, the class allows the vector to be
printed to the console and an output file. 

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | Main.cpp         | Main driver of my project that launches game.      |
|   2   | input.dat  | Input file containing integers.         |

### Instructions

- My program expects an input file filled with some integers.

+------------+
| name1 age1 |
| name2 age2 |
| etc...     |
+------------+

- Example Command:
    - `python <code> <input file> <num players>`
    - `python main.py input.txt 3`
