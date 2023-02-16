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
|   1   | [Banner.cpp](https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/P01/Banner.cpp) | My banner file. |
|   2   | [Main.cpp](https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/P01/main.cpp) | Main driver of my project that runs the program     |

### Instructions

- My program expects an input file filled with some integers.
- Requires iostream and fstream to work.

- Example Command:
    - Vector v(arr[]): Creates a vector from array arr[].
    - v.popFront(): Removes and returns the first item of the vector.
    - v.pushRear(10): Adds a 10 to the end of vector v.
