## P03 - GraphViz Class
### Bryce Koch
### Description:

My program takes a linked-list or binary search tree and produces dot code to be implemented into the GraphViz software.
This program allows a better visual for these data structures. Using several different classes, my program creates the 
nodes and edges seen in GraphViz. These Nodes and Edges use vectors and maps to store the details of each member. Including
color, shape, arrow type, opacity, and the label. Once compiled, my program outputs the translated code for the GraphViz visual
to the console and an output file.


### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Banner.cpp[(https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/P03/Banner.cpp)      | My banner file.                                    |
|   2   | Main.cpp        | Main driver of my project that launches game.      |



### Instructions

- Requires iostream, fstream, vector, and map standard template libraries.

- Example Command:
    - GraphViz G("Linked List", "LL"): Creates an instance of the GraphViz class.
    - G.addNode(): Creates a Node and adds it to the GraphViz instance.
