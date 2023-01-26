
/*****************************************************************************
 *
 *  Author:           Bryce Koch
 *  Email:            bakoch1223@my.msutexas.edu
 *  Label:            A03
 *  Title:            Commenting Code
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        This program allows the user to create and manipulate a circular
 *        queue. The queue is an array that is default size 10 but can have 
 *        a size of user's choice. Queues use a system known as FIFO (first
 *        in first out) where new items are added to the back of the array
 *        and the oldest item is removed first.The user can add items by
 *        pushing them onto the end of the queue and remove them by popping
 *        them off the front.
 *
 *  Files:
 *       main.cpp  : Driver Program
 *****************************************************************************/

#include <iostream>

using namespace std;

/**
 * Class CircularArrayQue
 *
 * Description:
 *      This class creates an array based circular queue and allows the user
 *      to push items onto the list and pop items off of the list.
 *
 * Public Methods:
 *              CircularArrayQue()
 *              CircularArrayQue(int size)
 *      void    Push(int item)
 *      int     Pop()
 *
 * Private Methods:
 *      void    init(int size = 0)
 *      bool    Full()
 *
 * Usage:
 *
 *      CircularArrayQue C;        //Creates a queue of default size 10
 *
 *                                 //or
 *
 *      CircularArrayQue C(6);     //Creates a queue of custom size 6
 *
 *      C.Push(5);                 //Pushes 5 to the front of Queue C
 *      C.Pop();                   //Removes the item at the front of te queue
 */

class CircularArrayQue {
private:
  int *Container;  // pointer for storing the values of the queue
  int Front;       // Front of the queue
  int Rear;        // The back of the queue
  int QueSize;     // Items in the queue
  int CurrentSize; // The size of the queue

  /**
   * Private : init
   *
   * Description:
   *      Initializes the circular queue by setting the front, back, and of
   *      current size of the queue to 0. Also sets the maximum queue size.
   *
   * Params:
   *      int    :  queue size
   *
   * Returns:
   *      Does not return  anything (void).
   */
  void init(int size = 0) {
    Front = Rear = CurrentSize = 0;
    QueSize = size;
  }

  /**
   * Private : Full
   *
   * Description:
   *      Checks to see if the queue is full.
   *
   * Params:
   *
   * Returns:
   *      bool    :  A true or false value
   */
  bool Full() { return CurrentSize == QueSize; }

public:
  /**
   * Public : CircularArrayQue
   *
   * Description:
   *      Constructor used to create a queue of default size 10.
   *
   * Params:
   *      No parameters
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  CircularArrayQue() {
    Container = new int[10];   //Creates queue of size 10
    init(10);                  //Calls init to set up queue
  }
  /**
   * Public : CircularArrayQue
   *
   * Description:
   *      Constructor used to create a queue of custom size.
   *
   * Params:
   *      int    :  Size of the queue
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  CircularArrayQue(int size) {
    Container = new int[size];   //Creates queue
    init(size);                  //Calls init to set the queue
  }

  /**
   * Public : Push
   *
   * Description:
   *      Adds an item to the queue if it is not full.
   *
   * Params:
   *      int    :  Item being added to the queue
   *
   * Returns:
   *      Does not return anything (void).
   */
  void Push(int item) {
    if (!Full()) {                 // Calls Full function to check queue size
      Container[Rear] = item;      // Points the end of the queue to the item
      Rear = (Rear + 1) % QueSize; // Moves rear to the end of the queue
      CurrentSize++;               // Fixes the size of the array
    } else {
      cout << "FULL!!!!" << endl;
    }
  }

  /**
   * Public : Pop
   *
   * Description:
   *      Removes the front of the queue
   *
   * Params:
   *      No parameters
   *
   * Returns:
   *      int    :  the item at the front of the queue
   */
  int Pop() {
    int temp = Container[Front];   // Creates an int and sets it to equal front
    Front = (Front + 1) % QueSize; // Moves front to the correct location
    CurrentSize--;                 // Corrects the new size of the queue
    return temp;                   // Returns the item
  }
  friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) { 
                                                      //Overloads cout
  for (int i = other.Front; i < other.CurrentSize; 
       i = (i + 1) % other.QueSize) {
    os << other.Container[i] << " ";
  }
  os << endl;
  return os;                                              
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
  CircularArrayQue C1(5); // Creates a queue called C1 and sets the size to 5

  // C1.Push(34);
  // C1.Push(38);
  // C1.Push(44);
  // C1.Push(22);
  // C1.Push(99);
  // C1.Push(100);

  C1.Push(1);
  C1.Push(2);             // Calls the Push function to add 3 numbers
  C1.Push(3);             // onto the queue
  // C1.Push(6);
  // C1.Push(7);
  cout << C1 << endl;     // Calls the overloaded cout operator to
                          // print out the queue
  // C1.Push(1);
  // C1.Push(2);
  // C1.Push(3);

  cout << C1 << endl;
}
