/*****************************************************************************
 *
 *  Author:           Bryce Koch
 *  Email:            bakoch1223@my.msutexas.edu
 *  Label:            P02
 *  Title:            Vector Class 2
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        This program adds onto the previous Vector class program that
 *        I created. This program overloads ostream, ofstream, square
 *        brackets [], addition, subtraction, multiplication,
 *        equality, and the assignment operators. This allows the user to
 *        use these operators as they are written rather than call a
 *        function or method.
 *
 *  Files:
 *       main.cpp   : Driver Program
 *       output.txt : Output File
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
 *      calls. Allows the user to push onto the head, back, in increasing
 *      or decreasing order, or a location of their choose. An integer can
 *      be pushed anywhere, and another vector can be pushed onto the head
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
 *      int           pophead()
 *      int           popRear();
 *      int           popAt(int loc)
 *      int           find(int look)
 *      void          print(ofstream &fout)
 *      ostream       &operator<<(ostream &os, const Vector &v)
 *      fstream       &operator<<(fstream &fout, const Vector &v)
 *      int           &operator[](int loc)
 *      Vector        &operator+(const Vector &rhs)
 *      Vector        &operator*(const Vector &rhs)
 *      Vector        &operator-(const Vector &rhs)
 *      Vector        &operator=(const Vector &v)
 *      bool          operator==(const Vector &v)
 *
 * Private Methods:
 *      No private methods.
 *
 * Usage:
 *
 *      Vector v1();                      //Creates an empty vector instance.
 *
 *      v1.pushFront(10);                 //Pushes a 10 to the head of v1.
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
 *      cout << v4 << endl;               //Prints out v4 without the need of
 *                                          a function call
 *      v5 = v4;
 */
class Vector {
  Node *head; // Beginning of Vector.
  Node *back; // End of Vector.
  int vSize;  // Size of the Vector. 

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
    head = back = nullptr;
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
      pushRear(*(Arr + i));
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
    Node *traverse = v.head; // traverse other vector to get data.
    while (traverse) {
      if (vSize == 0) {
        pushFront(traverse->data); // If empty, push other vector data
        vSize++;                  // to head.
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
        pushFront(r); // If vector is empty, push data to head.
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
   *      Pushes an integer onto the head of the Vector.
   *
   * Params:
   *      - int    :  Integer being pushed onto the head of the Vector.
   *
   * Returns:
   *      - Does not return anything (void return type).
   */
  void pushFront(int d) {
    Node *temp = new Node(d); // Calls node constructor for new node temp.
    if (vSize == 0) {
      head = back = temp; // If vector is empty, set head and back
      vSize++;            // equal to temp.
    } else {
      temp->next = head; // Else, set temp pointer next to head
      head->prev = temp; // and head pointer previous to temp.
      head = temp;       // Move head pointer to temp node.
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
      head = back = temp; // If vector is empty, set head and back
      vSize++;            // equal to temp.
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
   *      Pushes other Vector onto the head of this Vector.
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
      pushFront(traverse->data);  // Calls pushFront with data from traverse.
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
    Node *traverse = v.head; // Traverse other vector from the head.
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
    Node *traverse = head;

    if (head->data < back->data) {     // If the list is in increasing
      while (d > traverse->next->data) // numerical order.
        traverse = traverse->next;
      temp->next = traverse->next; // Move traverse until next data is greater
      traverse->next = temp;       // than d. Place temp node before node with
      temp->prev = traverse;       // data greater than d.
      vSize++;
    } else if (head->data > back->data) { // If the list is in decreasing
      while (d < traverse->next->data)    // numerical order.
        traverse = traverse->next;
      temp->next = traverse->next; // Move traverse until next data is less
      traverse->next = temp;       // than d. Place temp node before node with
      temp->prev = traverse;       // data less than d.
      vSize++;
    } else { // If the list contains 1 number or all equivalent numbers.
      if (d > head->data) { // If greater than head, push Rear.
        pushRear(d);
        vSize++;
      } else {
        pushFront(d); // Else, push head.
        vSize++;
      }
    }
  }

  /**
   * Public : pophead
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
  int pophead() {
    int keep; // Holds the value of the integer being popped.
    Node *temp = head;
    head = head->next;    // Sets temp equal to head and moves head to the
    head->prev = nullptr; // next node in the list.
    keep = temp->data;    // Gets the data out of temp before deleting.
    delete temp;          // Deletes the node to free up allocated memory.
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
    Node *traverse = head;  // travel keeps up with the location in the list.
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
    Node *traverse = head;
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
    Node *traverse = head; // Traverses the vector list.
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

  /**
   * Public : getSize
   *
   * Description:
   *      Gets the size of the vector from private.
   *
   * Params:
   *      - None
   *
   * Returns:
   *      - int    :  size of the vector.
   */
  int getSize() { return vSize; }

  /**
   * Public : ostream &operator<<
   *
   * Description:
   *      Overloads the ostream operator to allow vectors to be directly output
   *      to the console.
   *
   * Params:
   *      - ostream    :  holds the output of the method
   *      - Vector     :  vector being output
   *
   * Returns:
   *      - ostream    :  the output from the method being held in os
   */
  friend ostream &operator<<(ostream &os, const Vector &v) {
    Node *temp = v.head;

    os << "[";
    while (temp) {
      os << temp->data;  // Reads in data from the vector
      if (temp->next) {
        os << ",";
      }
      temp = temp->next;
    }
    os << "]" << endl;
    return os;  // Returns the data from the vector
  }

  /**
   * Public : fstream &operator<<
   *
   * Description:
   *      Overloads the ostream operator to allow vectors to be directly output
   *      to a file.
   *
   * Params:
   *      - fstream    :  holds the file output of the method
   *      - Vector     :  vector being output
   *
   * Returns:
   *      - fstream    :  the output from the method being held in fout
   */
  friend fstream &operator<<(fstream &fout, const Vector &v) {
    Node *temp = v.head;

    while (temp) {
      fout << "[";
      while (temp) {
        fout << temp->data;  // Reads data into file from vector
        if (temp->next) {
          fout << ",";
        }
        temp = temp->next;
      }
      fout << "]" << endl;
    }
    return fout;  // Returns the output file
  }

  /**
   * Public : &operator[]
   *
   * Description:
   *      Overloads the square brackets so the user can access a vector
   *      like an array.
   *
   * Params:
   *      - int    :  The location in the vector where the user wants to access
   *
   * Returns:
   *      - int    :  The data at that location
   */
  int &operator[](int loc) {
    Node *temp = this->head;  // Node used to traverse the vector
    int count = 0;            // Keeps count of the location in the vector
    while (temp && count != loc) {  // Loops until the location is reached
      count++;
      temp = temp->next;
    }
    return temp->data;  // Returns the data found at the location
  }

  /**
   * Public : &operator+
   *
   * Description:
   *      Overloads the addition operator to allow direct vector addition.
   *
   * Params:
   *      - const Vector  :  The vector being added with this vector
   *
   * Returns:
   *      - Vector    :  The vector holding the sum of the two vectors
   */
  Vector &operator+(const Vector &rhs) {
    Vector V;    // Holds the value for the return
    Node *small; // Keeps track of the smaller sized vector
    Node *big;   // Keeps track of the larger sized vector

    if (this->vSize < rhs.vSize) {
      small = this->head; // Moves the small pointer to this vector if it
      big = rhs.head;     // is smaller
    } else {
      small = rhs.head;   // Moves the small pointer to the right side vector
      big = this->head;   // for all other instances
    }

    while (small != NULL) {
      V.pushRear(big->data + small->data);  // Pushes big + small onto V for
      big = big->next;                      // each iteration until small has
      cout << small->data << endl;          // runs out of data.
      small = small->next;
    }
    while (big) {
      V.pushRear(big->data);  // Places the rest of big onto the end of V
      big = big->next;
    }
    return V;  // Returns V after the operations
  }

  /**
   * Public : &operator*
   *
   * Description:
   *      Overloads the multiplication operator to allow direct vector
   *      multiplication.
   *
   * Params:
   *      - const Vector  :  The vector being multiplied with this vector
   *
   * Returns:
   *      - Vector    :  The vector holding the product of the two vectors
   */
  Vector &operator*(const Vector &rhs) {
    Vector V;    // Holds the value for the return
    Node *small; // Keeps track of the smaller sized vector
    Node *big;   // Keeps track of the larger sized vector

    if (this->vSize < rhs.vSize) {
      small = this->head;
      big = rhs.head;    // Sets the big and small pointers
    } else {             // accordingly
      small = rhs.head;
      big = this->head;
    }

    while (small != NULL) {
      V.pushRear(big->data * small->data);
      big = big->next;              // Push big times small onto V while
      cout << small->data << endl;  // small is pointing towards data
      small = small->next;
    }
    while (big) {
      V.pushRear(big->data);  // Pushes the rest of big onto the end of V
      big = big->next;
    }
    return V;  // Returns V after the operations
  }

  /**
   * Public : &operator-
   *
   * Description:
   *      Overloads the subtraction operator to allow direct vector 
   *      subtraction.
   *
   * Params:
   *      - const Vector  :  The vector being subtracted from this vector
   *
   * Returns:
   *      - Vector    :  The vector holding the difference of the two vectors
   */
  Vector &operator-(const Vector &rhs) {
    Vector V;                // Holds the value for the return
    Node *LHS = this->head;  // Left side of subtraction
    Node *RHS = rhs.head;    // Right side of subtraction

    while (LHS && RHS) {
      cout << LHS->data - RHS->data << endl;
      V.pushRear(LHS->data - RHS->data);
      RHS = RHS->next;  // While both pointers have data, subtract RHS
      LHS = LHS->next;  // from LHS
    }
    if (RHS == NULL) {  
      cout << LHS->data << endl;
      while (LHS) {
        V.pushRear(LHS->data);  // Place the remaining data in whichever
        LHS = LHS->next;        // vector was bigger onto the end of V
      }
    } else {
      cout << RHS->data << endl;
      while (RHS) {
        V.pushRear(RHS->data);
        RHS = RHS->next;
      }
    }
    return V;  // Returns V after the operations
  }

  /**
   * Public : &operator=
   *
   * Description:
   *      Overloads the assignment operator to set two vectors equal to one
   *      another.
   *
   * Params:
   *      - const Vector  :  The vector this vector is being set equal to
   *
   * Returns:
   *      - Vector    :  The overwritten vector
   */
  Vector &operator=(const Vector &v) {
    this->head = v.head;
    return *this;
  }

/**
   * Public : operator==
   *
   * Description:
   *      Overloads the equality operator to compare two vectors to determine
   *      equality.
   *
   * Params:
   *      - const Vector  :  The vector this vector is being compared to
   *
   * Returns:
   *      - bool    :  The boolean value result of the equality test
   */
  bool operator==(const Vector &v) {
    Node *temp = v.head;      // Node for traversing vector v
    Node *temp2 = this->head; // Node for traversing this vector

    while ((temp && temp2) && (temp->data == temp2->data)) {
      temp = temp->next;   // Loop checks that both pointers have are not NULL
      temp2 = temp2->next; // and that the data in each is equivalent.
    }
    if (!temp && !temp2)  // If both nodes are pointing to NULL then they
      return true;        // traversed fully through loop. Return true
    else
      return false;
  }
};

int main() {
  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  Vector v1(a1, 5);
  Vector v2(a2, 3);

  ofstream fout;
  fout.open("output.txt");

  fout << "Bryce Koch" << endl << "February 14" << endl << "Spring 2143";
  fout << endl;
  
  cout << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.

  fout << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  Vector v3 = v1 + v2;
  cout << v3 << endl;
  // writes out [11,22,33,4,9] to console.

  v3 = v1 - v2;
  cout << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  // writes out [9,18,27,4,9] to console.

  v3 = v2 * v1;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 * v2;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.
  /*
      v3 = v1 / v2;
      cout << v3 << endl;
      // writes out [0,0,0,4,9] to console.

      v3 = v2 / v1;
      cout << v3 << endl;
      // writes out [10,10,10,4,9] to console.
  */
  cout << (v2 == v1) << endl;
  // writes 0 to console (false) .

  Vector v4 = v1;
  cout << (v4 == v1) << endl;
  // writes 1 to console (true) .
}