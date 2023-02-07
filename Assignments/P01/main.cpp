/*****************************************************************************
 *
 *  Author:           Bryce Koch
 *  Email:            bakoch1223@my.msutexas.edu
 *  Label:            P01
 *  Title:            Vector Class
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        This program implements a class that uses a linked list to represent
 *        vectors and vector functions. It allows the user to create a vector
 *        from scratch, an array, another vector, and an input file. Using
 *        push, pop, find, and print methods, the class allows the linked list
 *        to be changed and implemented in many ways. This class does not,
 *        however, replace the vector library, but is used as a way to
 *        explore the possibilities of classes and allow room for further
 *        learning into classes and methods.
 *
 *  Files:
 *       main.cpp   : Driver Program
 *       input.dat  : Input File
 *       output.dat : Output File
 *****************************************************************************/
#include <fstream>
#include <iostream>

using namespace std;

struct Node {       // Struct creates a node for a linked list.
  int data;         // Data for the node.
  Node *next;       // Next pointer on the node.
  Node *prev;       // Previous pointer on the node.
  Node(int d) {     // Constructor initializes a node by setting data equal
    data = d;       // to the integer passed in, and setting next and
    next = nullptr; // previous to nullptr by default.
    prev = nullptr;
  }
};

/**
 * Vector
 *
 * Description:
 *      Creates a linked-list based vector from multiple different constructor
 *      calls. Allows the user to push onto the front, back, in increasing
 *      or decreasing order, or a location of their choose. An integer can
 *      be pushed anywhere, and another vector can be pushed onto the front
 *      or back of the vector. The user can pop integers off at any location,
 *      and can get the location of an integer if they need to. Can print the
 *      vector out to the console and an output file.
 *
 * Public Methods:
 *                    Vector()
 *                    Vector(int *Arr, int size)
 *                    Vector(const Vector &v)
 *                    Vector(string filename)
 *      void          pushFront(int d)
 *      void          pushRear(int d)
 *      void          pushFront(const Vector &v)
 *      void          pushRear(const Vector &v)
 *      void          inOrderPush(int d)
 *      int           popFront()
 *      int           popRear();
 *      int           popAt(int loc)
 *      int           find(int look)
 *      void          print(ofstream &fout)
 *
 * Private Methods:
 *      No private methods.
 *
 * Usage:
 *
 *      Vector v1();                      //Creates an empty vector instance.
 *
 *      v1.pushFront(10);                 //Pushes a 10 to the front of v1.
 *      v1.popRear();                     //Removes and returns the last
 *                                          integer of the class.
 *      Vector v2(int arr[]);             //Creates a vector and inputs data
 *                                          from an array.
 *      v2.print();                       //Prints the contents of v2.
 *
 *      Vector v3(v1);                    //Creates a vector and inputs data
 *                                          from another vector.
 *      v3.find(72);                      //Locates 72 if found in the list
 *                                          and returns the location.
 *      Vector v4(input file name);       //Creates a vector and inputs data
 *                                          from an input file.
 */
class Vector {
  Node *front; // Beginning of Vector.
  Node *back;  // End of Vector.
  int vSize;   // Size of the Vector. Used for testing.

public:
  /**
   * Public : Vector
   *
   * Description:
   *      Creates an empty vector.
   *
   * Params:
   *      - No parameters.
   *
   * Returns:
   *      - Does not return anything (constructor).
   */
  Vector() {
    front = back = nullptr;
    vSize = 0;
  }

  /**
   * Public : Vector
   *
   * Description:
   *      Creates a vector from a passed in array.
   *
   * Params:
   *      - int*    :  array of integers.
   *      - int     :  size of array.
   *
   * Returns:
   *      - Does not return anything (constructor).
   */
  Vector(int *Arr, int size) {
    vSize = 0;
    for (int i = 0; i < size; i++) {
      if (i == 0) {
        pushFront(*(Arr + i)); // If vector is empty, push to front.
        vSize++;
      } else { // Else, push onto rear.
        pushRear(*(Arr + i));
        vSize++;
      }
    }
  }

  /**
   * Public : Vector
   *
   * Description:
   *      Creates a vector from another vector instance.
   *
   * Params:
   *      - const Vector    :  Vector instance used for passing in values.
   *
   * Returns:
   *      - Does not return anything (constructor).
   */
  Vector(const Vector &v) {
    vSize = 0;
    Node *traverse = v.front; // traverse other vector to get data.
    while (traverse) {
      if (vSize == 0) {
        pushFront(traverse->data); // If empty, push other vector data
        vSize++;                   // to front.
      } else {
        pushRear(traverse->data); // Else, push data in other vector to rear.
        vSize++;
      }
      traverse = traverse->next;
    }
  }

  /**
   * Public : Vector
   *
   * Description:
   *      Creates a vector from an input file.
   *
   * Params:
   *      - string    :  The file name containing the ints.
   *
   * Returns:
   *      - Does not return anything (constructor).
   */
  Vector(string filename) {
    int r; // Placeholder for data from file.
    vSize = 0;
    ifstream infile;
    infile.open(filename);  // Opens input file.
    while (!infile.eof()) { // While not at the end of the input file.
      infile >> r;          // Read data from file and place into r.
      if (vSize == 0) {
        pushFront(r); // If vector is empty, push data to front.
        vSize++;
      } else { // Else, push to rear.
        pushRear(r);
        vSize++;
      }
    }
    infile.close();
  }

  /**
   * Public : pushFront
   *
   * Description:
   *      Pushes an integer onto the front of the Vector.
   *
   * Params:
   *      - int    :  Integer being pushed onto the front of the Vector.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void pushFront(int d) {
    Node *temp = new Node(d); // Calls node constructor for new node temp.
    if (vSize == 0) {
      front = back = temp; // If vector is empty, set front and back
      vSize++;             // equal to temp.
    } else {
      temp->next = front; // Else, set temp pointer next to front
      front->prev = temp; // and front pointer previous to temp.
      front = temp;       // Move front pointer to temp node.
      vSize++;
    }
  }

  /**
   * Public : pushRear
   *
   * Description:
   *      Pushes an integer onto the end of the Vector.
   *
   * Params:
   *      - int    :  Integer being added to end of Vector.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void pushRear(int d) {
    Node *temp = new Node(d); // Calls node constructor for new node temp.
    if (vSize == 0) {
      front = back = temp; // If vector is empty, set front and back
      vSize++;             // equal to temp.
    } else {
      back->next = temp; // Else, set back pointer next to temp and
      temp->prev = back; // temp pointer previous to back.
      back = temp;       // Move back pointer to temp.
      vSize++;
    }
  }

  /**
   * Public : pushFront
   *
   * Description:
   *      Pushes other Vector onto the front of this Vector.
   *
   * Params:
   *      - const Vector    :  Other vector being pushed.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void pushFront(const Vector &v) {
    Node *traverse = v.back; // Traverse other vector from the back.
    while (traverse != nullptr) {
      pushFront(traverse->data); // Calls pushFront with data from traverse.
      traverse = traverse->prev; // Moves traverse to integer behind traverse.
    }
  }

  /**
   * Public : pushRear
   *
   * Description:
   *      Pushes other Vector onto the end of this Vector.
   *
   * Params:
   *      - const Vector  :  Other vector being pushed.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void pushRear(const Vector &v) {
    Node *traverse = v.front; // Traverse other vector from the front.
    while (traverse != nullptr) {
      pushRear(traverse->data);  // Calls pushRear with data from temp.
      traverse = traverse->next; // Moves traverse to next integer.
    }
  }

  /**
   * Public : inOrderPush
   *
   * Description:
   *      Pushes an integer into its respective order.
   *
   * Params:
   *      - int    :  Integer being placed in the Vector.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void inOrderPush(int d) {
    Node *temp = new Node(d);
    Node *traverse = front;

    if (front->data < back->data) {    // If the list is in increasing
      while (d > traverse->next->data) // numerical order.
        traverse = traverse->next;
      temp->next = traverse->next; // Move traverse until next data is greater
      traverse->next = temp;       // than d. Place temp node before node with
      temp->prev = traverse;       // data greater than d.
      vSize++;
    } else if (front->data > back->data) { // If the list is in decreasing
      while (d < traverse->next->data)     // numerical order.
        traverse = traverse->next;
      temp->next = traverse->next; // Move traverse until next data is less
      traverse->next = temp;       // than d. Place temp node before node with
      temp->prev = traverse;       // data less than d.
      vSize++;
    } else { // If the list contains 1 number or all equivalent numbers.
      if (d > front->data) { // If greater than front, push Rear.
        pushRear(d);
        vSize++;
      } else {
        pushFront(d); // Else, push front.
        vSize++;
      }
    }
  }

  /**
   * Public : popFront
   *
   * Description:
   *      Removes the first item of the vector.
   *
   * Params:
   *      - No parameters.
   *
   * Returns:
   *      - keep    :  The integer being removed from the vector.
   */
  int popFront() {
    int keep; // Holds the value of the integer being popped.
    Node *temp = front;
    front = front->next;   // Sets temp equal to front and moves front to the
    front->prev = nullptr; // next node in the list.
    keep = temp->data;     // Gets the data out of temp before deleting.
    delete temp;           // Deletes the node to free up allocated memory.
    vSize--;
    return keep;
  }

  /**
   * Public : popRear
   *
   * Description:
   *      Removes the last integer off of the vector.
   *
   * Params:
   *      - No parameters.
   *
   * Returns:
   *      - keep    :  The integer being removed from the vector.
   */
  int popRear() {
    int keep; // Holds the value of the integer being popped.
    Node *temp = back;
    back = back->prev;    // Sets temp equal to back and moves back to the node
    back->next = nullptr; // behind it in the list.
    keep = temp->data;    // Gets the data out of temp before deleting.
    temp->prev = nullptr;
    delete temp; // Deletes the node to free up allocated memory.
    vSize--;
    return keep;
  }

  /**
   * Public : popAt
   *
   * Description:
   *      Removes the integer at the specified location.
   *
   * Params:
   *      - int    :  location of value being popped off.
   *
   * Returns:
   *      - temp    :  The integer being removed from the vector.
   */
  int popAt(int loc) {
    int temp, travel = 0;   // Temp holds value of integer being popped and
    Node *traverse = front; // travel keeps up with the location in the list.
    while (travel != loc) { // Move until location is reached.
      traverse = traverse->next;
      travel++;
    }
    if (travel == loc) {                     // If the location was valid.
      temp = traverse->data;                 // Gets data from traverse.
      traverse->prev->next = traverse->next; // Sets the node before and after
      traverse->next->prev = traverse->prev; // to point towards each other.
      delete traverse; // Deletes the node to free up allocated memory.
      vSize--;
    } else // If the data is invalid return -1.
      temp = -1;
    return temp;
  }

  /**
   * Public : find
   *
   * Description:
   *      Finds the location of an integer in the vector.
   *
   * Params:
   *      - int    :  integer being looked for
   *
   * Returns:
   *      - locate    :  integer index of where the value was found.
   *      - -1        :  if the value cannot be found in the vector.
   */
  int find(int look) {
    Node *traverse = front;
    int locate = 0; // Holds location of value if found.
    while (traverse->data != look && traverse->next != nullptr) {
      locate++; // Move until the value is found, incrementing the location
      traverse = traverse->next; // value each time.
    }
    if (traverse->data == look) // If the value is in the list.
      return locate;
    else // If the value is not in the list.
      return -1;
  }

  /**
   * Public : print
   *
   * Description:
   *      Prints the contents of the vector.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void print(ofstream &fout) {
    Node *traverse = front; // Traverses the vector list.
    fout << "[";
    cout << "[";
    while (traverse) {
      if (traverse->next == nullptr) { // If end of the vector.
        fout << traverse->data;
        cout << traverse->data;
      } else { // Every other location in the vetor.
        fout << traverse->data << ", ";
        cout << traverse->data << ", ";
      }
      traverse = traverse->next;
    }
    fout << "]" << endl;
    cout << "]" << endl;
  }
};

int main() {
  int x = 0;

  ofstream ofile;         // Creates output file.
  ofile.open("test.out"); // Opens the output file.

  ofile << "Bryce Koch" << endl << "January 6, 2023";
  ofile << endl << "Spring 2143" << endl; // Output file heading.

  Vector v1;        // Creates an empty vector v1.
  v1.pushFront(18); // Pushes 18 to the front of v1.
  v1.pushFront(20); // Pushes 20 to the front of v1.
  v1.pushFront(25); // Pushes 25 to the front of v1.
  v1.pushRear(18);  // Pushes 18 to the end of v1.
  v1.pushRear(20);  // Pushes 20 to the end of v1.
  v1.pushRear(25);  // Pushes 25 to the end of v1.
  v1.print(ofile);  // Prints vector v1.
  // [25, 20, 18, 18, 20, 25]

  int A[] = {11, 25, 33, 47, 51};
  Vector v2(A, 5); // Creates a Vector v2 and adds the contents of array A[].
  v2.print(ofile); // Prints vector v2.
  // [11, 25, 33, 47, 51]

  v2.pushFront(9);
  v2.inOrderPush(27); // Pushes 27 onto v2 in numerical order.
  v2.pushRear(63);
  v2.print(ofile);
  // [9, 11, 25, 33, 47, 51, 63]

  v1.pushRear(v2); // Pushes vector v2 onto the end of v1.
  v1.print(ofile); // Prints out v1 with the new changes.
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print(ofile);

  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  ofile << x << endl;
  cout << x << endl;
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print(ofile);
  // [18, 20, 25, 9, 11, 25, 27, 33]
  ofile << x << endl;
  cout << x << endl;
  // 47

  x = v2.popAt(3); // Pops the integer at location 3 in the vector.
  v2.print(ofile);
  // [9, 11, 25, 33, 47, 51, 63]
  ofile << x << endl;
  cout << x << endl;
  // 27

  x = v2.find(51); // Looks for 51 in vector v2 and stores the location in x.
  ofile << x << endl;
  cout << x << endl;
  // 5

  x = v2.find(99); // Looks for 99 in vector v2 but returns -1 as 99 is not
                   // in the vector.
  ofile << x << endl;
  cout << x << endl;
  // -1

  Vector v3(v1); // Creates a vector v3 from the contents of vector v1.
  v3.print(ofile);
  // [18, 20, 25, 9, 11, 25, 27, 33]

  v3.pushFront(v2);
  v3.print(ofile);
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  Vector v4("input.dat"); // Creates a vector v4 from data passed
                          // in from an input file.
  v4.pushRear(v3);
  v4.print(ofile);
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18,
  // 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47,
  // 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  ofile.close();
}