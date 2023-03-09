/*****************************************************************************
 *
 *  Author:           Bryce Koch
 *  Email:            brycekoch179@gmail.com
 *  Label:            P03
 *  Title:            GraphViz Class
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        This program allows the user to create dot language instructions
 *        for the GraphViz application. the user will be able to create
 *        nodes and edges using the given funtions. The proogram will
 *        translate what the user inputs into dot language that can be copy
 *        and pasted from the output file. This program also uses the Standard
 *        template libraries vector and map to simplify the problem.
 *
 *  Files:            main.cpp
 *                    test.out
 *****************************************************************************/
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * Attribute
 *
 * Description:
 *      Uses maps to hold and define the customization of a Node or edge.
 *
 * Public Methods:
 *                Attribute()
 *      void:     addAttributes(string key, string val)
 *      void:     addAttributes(map<string, string> atts)
 *      ostream:  &operator<<(ostream &os, Attribute &e)
 *      fstream:  &operator<<(fstream &fout, Attribute &e)
 *
 * Usage:
 *
 *      Attribute A;              // Creates an attribute instance.
 *
 *      A.addAttributes(Box);     // Uses the map passed in to add values
 *                                // to the attribute.
 *
 */
class Attribute {
protected:
  map<string, string> att; // attributes

public:
  Attribute() {}

  /**
   * Public : addAttributes
   *
   * Description:
   *      Adds the parameters for value and key to the map.
   *
   * Params:
   *      string    : The name of the value being stored (the key).
   *      string    : The value being stored in the map.
   *
   * Returns:
   *      Does not return anything (void).
   */
  void addAttribute(string key, string val) { att[key] = val; }

  /**
   * Public : addAttributes
   *
   * Description:
   *      Adds the value and key through a passed in map.
   *
   * Params:
   *      map<string,string>  : Map holding the parameters for the attribute.
   *
   * Returns:
   *      Does not return anything (void).
   */
  void addAttributes(map<string, string> atts) {
    for (auto const &x : atts) {
      att[x.first] = x.second;
    }
  }

  /**
   * Public : ostream &operator<<
   *
   * Description:
   *      Overloads the cout<< statement to print attributes to the console.
   *
   * Params:
   *      ostream    : Holds the values being printed to the console.
   *      Attribute  : The attribute instance being printed.
   *
   * Returns:
   *      ostream    : The variable holding all of the output.
   */
  friend ostream &operator<<(ostream &os, Attribute &e) {

    os << "[";

    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }

  /**
   * Public : fstream &operator<<
   *
   * Description:
   *      Overloads the << operator to print attributes to a file.
   *
   * Params:
   *      fstream    : Holds the values being printed to the file.
   *      Attribute  : The attribute instance being printed.
   *
   * Returns:
   *      fstream    : The variable holding all of the output.
   */
  friend fstream &operator<<(fstream &fout, Attribute &e) {

    fout << "[";
    int i = 0;
    for (auto const &x : e.att) {
      fout << x.first << "="
           << "\"" << x.second << "\"";
      if (i < e.att.size() - 1) {

        fout << ", ";
      }
      i++;
    }

    fout << "]";
    return fout;
  }
};

/**
 * Edge
 *
 * Description:
 *      Creates an edge using attributes and holds the value of where it
 *      begins and ends. Also contains and sets all of the attributes of the
 *      edge. Can be easily printed out using the overloaded << operator.
 *
 * Public Methods:
 *      Edge()
 *      Edge(string color, string arrow)
 *      Edge(int start, int end)
 *      Edge(int s, string sl, int e, string el)
 *      ostream &operator<<(ostream &os, Edge &e)
 *
 * Usage:
 *
 *      Edge();          // Creates a default edge.
 *
 *      Edge(red, vee);  // Creates an edge with line color red and arrow
 *                       // shape vee.
 *
 */
class Edge : public Attribute {
  int eid;
  int start;
  string sLabel;
  int end;
  string eLabel;
  int size;

public:
  /**
   * Public : Edge
   *
   * Description:
   *      Creates a default edge.
   *
   * Params:
   *      No parameters.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  Edge() {
    att["color"] = "black";   // default color
    att["arrowhead"] = "vee"; // default arrow shape
  }

  /**
   * Public : Edge
   *
   * Description:
   *      Creates an edge with attributes color and arrow type.
   *
   * Params:
   *      string    : The color of the edge.
   *      string    : The type of arrow for the edge.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  Edge(string color, string arrow) {
    att["color"] = color;
    att["arrowhead"] = arrow;
  }
  /**
   * Public : Edge
   *
   * Description:
   *      Creates an edge from the starting point to the ending point.
   *
   * Params:
   *      int    : The Node where the edge starts.
   *      int    : The Node where the edge point to (ends).
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  Edge(int start, int end) {
    this->start = start;
    this->end = end;
    size = 2;
  }
  /**
   * Public : Edge
   *
   * Description:
   *      Creates an edge for a record shape.
   *
   * Params:
   *      int    : The Node where the edge starts.
   *      string : The label of the record where the Edge points from.
   *      int    : The Node where the edge point to (ends).
   *      string : The label of the record where the Edge points to.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  Edge(int s, string sl, int e, string el) {
    this->start = s;
    this->sLabel = sl;
    this->end = e;
    this->eLabel = el;
  }

  /**
   * Public : ostream &operator<<
   *
   * Description:
   *      Overloads the cout<< statement to print attributes to the console.
   *
   * Params:
   *      ostream    : Holds the values being printed to the console.
   *      Edge       : The edge instance being printed.
   *
   * Returns:
   *      ostream    : The variable holding all of the output.
   */
  friend ostream &operator<<(ostream &os, Edge &e) {
    if (e.size == 2) {
      os << e.start << "->" << e.end << " ";
    } else {
      os << e.start << ":" << e.sLabel << "->" << e.end << ":" << e.eLabel;
    }
    os << "[";

    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";

      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";

    return os;
  }
};

/**
 * Node
 *
 * Description:
 *      Creates and defines the Node for the GraphViz software. Holds and sets
 *      the attributes of the node. Also creates an id for the Node so it van
 *      be accessed easily by the other functions and GraphViz.
 *
 * Public Methods:
 *      Node()
 *      Node(map<string, string> atts)
 *
 * Usage:
 *
 *      Node()      // Creates a default Node.
 *
 *      Node(atts)  // Creates a Node with the passed in attributes.
 *
 */
class Node : public Attribute {
  int nid;

public:
  /**
   * Public : Node
   *
   * Description:
   *      Creates a Node and gives it default attributes.
   *
   * Params:
   *      No parameters.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  Node() {
    att["color"] = "black";  // default color
    att["shape"] = "record"; // default arrow shape
  }
  /**
   * Public : Node
   *
   * Description:
   *      Creates a Node instance using an attribute map.
   *
   * Params:
   *      map<string, string> : The map holding the attribute of the Node.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  Node(map<string, string> atts) {
    for (auto const &x : atts) {
      att[x.first] = x.second;
    }
  }
};

/*
struct Shape {
  string shape;
  Shape(string name) { shape = name; }
};*/

/**
 * GraphViz
 *
 * Description:
 *      Description of your class and what it does
 *
 * Public Methods:
 *           GraphViz()
 *           GraphViz(string graph_name, string graph_shape)
 *      int  addNode()
 *      int  addNode(map<string, string> atts)
 *      void updateNode(int id, string key, string value)
 *      void addEdge(int start, int end)
 *      void addEdge(int start, int end, map<string, string> att)
 *      void addEdge(int s, string start, int e, string end,
 *           map<string, string> att)
 *      void printGraph(string graphName = "")
 *      ostream &operator<<(ostream &banana, GraphViz &g)
 *      ofstream &operator<<(ofstream &fout, GraphViz &g)
 *
 * Usage:
 *
 *      GraphViz A;      // Creates a default GraphViz object.
 *
 *      A.addNode(atts)  // Creates and adds a node to the GraphViz object.
 *
 *      A.addEdge(1, 2)  // Creates an edge that point to 2 from 1.
 *
 */
class GraphViz {
  int edgeId;
  int nodeId;
  vector<Edge> Edges;
  vector<Node> Nodes;
  string graphName;
  string graphShape;

public:
  /**
   * Public : GraphViz
   *
   * Description:
   *      Creates an instance of GraphViz with default attributes.
   *
   * Params:
   *      No parameters.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  GraphViz() {
    edgeId = 0;
    nodeId = 0;
    graphName = "foo";
  }

  /**
   * Public : GraphViz
   *
   * Description:
   *      Creates an instance of GraphViz and sets the name and shape.
   *
   * Params:
   *      string    : Name of the GraphViz graph.
   *      string    : Shape of the GraphViz graph.
   *
   * Returns:
   *      Does not return anything (constructor).
   */
  GraphViz(string graph_name, string graph_shape) {
    edgeId = 0;
    nodeId = 0;
    graphName = graph_name;
    graphShape = graph_shape;
  }

  /**
   * Public :addNode
   *
   * Description:
   *      Creates and adds a Node to the object.
   *
   * Params:
   *      No parameters.
   *
   * Returns:
   *      int  : The id for the Node.
   */
  int addNode() {
    Nodes.push_back(Node());
    return Nodes.size() - 1;
  }

  /**
   * Public : addNode
   *
   * Description:
   *      Create a Node from a map and adds it to the object.
   *
   * Params:
   *      map<string, string> : Attributes of the Node being created.
   *
   * Returns:
   *      int  : The id for the Node.
   */
  int addNode(map<string, string> atts) {
    Nodes.push_back(Node(atts));

    return Nodes.size() - 1;
  }

  /**
   * Public : updateNode
   *
   * Description:
   *      Adds or updates the attributes in the Node defined.
   *
   * Params:
   *      int    : The id of the Node being updated.
   *      string : The name of the attribute.
   *      string : the value of the attribute.
   *
   * Returns:
   *      Does not return anything (void).
   */
  void updateNode(int id, string key, string value) {
    Nodes[id].addAttribute(key, value);
  }

  /**
   * Public : addEdge
   *
   * Description:
   *      Creates an edge and adds it to the object.
   *
   * Params:
   *      int    : The Node id where the edge starts.
   *      int    : The Node id where the Node ends.
   *
   * Returns:
   *      Does not return anything (void).
   */
  void addEdge(int start, int end) { Edges.push_back(Edge(start, end)); }

  /**
   * Public : addEdge
   *
   * Description:
   *      Creates an edge with attributes and adds it to the object.
   *
   * Params:
   *      int    : The Node id where the edge starts.
   *      int    : The Node id where the Node ends.
   *      map<string, string> : The attributes for the edge.
   *
   * Returns:
   *      Does not return anything (void).
   */
  void addEdge(int start, int end, map<string, string> att) {

    Edges.push_back(Edge(start, end));
    Edges[Edges.size() - 1].addAttributes(att);
  }

  /**
   * Public : addEdge
   *
   * Description:
   *      Creates an edge for a record shape.
   *
   * Params:
   *      int    : The Node id where the edge starts.
   *      string : The label of the record where the Edge points from.
   *      int    : The Node id where the Node ends.
   *      string : The label of the record where the Edge points to.
   *      map<string, string> : The attributes for the edge.
   *
   * Returns:
   *      Does not return anything (void).
   */
  void addEdge(int s, string start, int e, string end,
               map<string, string> att) {

    Edges.push_back(Edge(s, start, e, end));
    Edges[Edges.size() - 1].addAttributes(att);
  }

  /**
   * Public : ostream &operator<<
   *
   * Description:
   *      Overloads the cout<< statement to print the entire
   *      GraphViz graph syntax.
   *
   * Params:
   *      ostream    : Holds the values being printed to the console.
   *      GraphViz   : The GraphViz object being printed.
   *
   * Returns:
   *      ostream    : The variable holding all of the output.
   */
  friend ostream &operator<<(ostream &banana, GraphViz &g) {
    for (int i = 0; i < g.Nodes.size(); i++) {
      banana << i << " " << g.Nodes[i] << endl;
    }
    for (int i = 0; i < g.Edges.size(); i++) {
      banana << g.Edges[i] << endl;
    }
    return banana;
  }

  /**
   * Public : ofstream &operator<<
   *
   * Description:
   *      Overloads the << operator to print the entire
   *      GraphViz graph syntax to a file.
   *
   * Params:
   *      ofstream   : Holds the values being printed to the console.
   *      GraphViz   : The GraphViz object being printed.
   *
   * Returns:
   *      ofstream   : The variable holding all of the output.
   */
  friend ofstream &operator<<(ofstream &fout, GraphViz &g) {
    for (int i = 0; i < g.Nodes.size(); i++) {
      fout << i << " " << g.Nodes[i] << endl;
    }
    for (int i = 0; i < g.Edges.size(); i++) {
      fout << g.Edges[i] << endl;
    }
    return fout;
  }
};

int main() {
  ofstream fout;
  fout.open("test.out");

  // The heading for output file.
  fout << "Bryce Koch" << endl << "CMPS 2143" << endl << "3/8/2023" << endl;

  // Syntax for the graphviz graph.
  fout << endl << "digraph Singly_Linked_List{" << endl;
  fout << "rankdir = LR" << endl;
  cout << "digraph Singly_Linked_List{" << endl;
  cout << "rankdir = LR" << endl;

  // create graphviz instances with specific shapes
  GraphViz G("LinkedList", "LL");
  GraphViz D("DoublyLinkedList", "DLL");
  GraphViz B("BinarySearchTree", "BST");
  GraphViz Z("BinarySearchTree", "BST");

  // used as an example to load attributes for a node
  map<string, string> Box;
  map<string, string> Arrow;
  map<string, string> Crow;
  map<string, string> Tee;
  map<string, string> Dot;
  // example attribute that gets a map of attributes and
  // adds them to "A"
  Attribute A;
  Box["shape"] = "box";
  Box["color"] = "blue";
  Box["opacity"] = "0.8";
  A.addAttributes(Box);

  Arrow["color"] = "red";
  Arrow["arrowhead"] = "vee";
  A.addAttributes(Arrow);

  Crow["color"] = "black";
  Crow["arrowhead"] = "crow";
  A.addAttributes(Crow);

  Tee["color"] = "blue";
  Tee["arrowhead"] = "tee";
  A.addAttributes(Tee);

  Dot["color"] = "green";
  Dot["arrowhead"] = "dot";
  A.addAttributes(Dot);

  // Creating nodes in graphviz and sending in default
  // colors / shapes, etc.
  int nodeId = G.addNode(Box);
  nodeId = G.addNode(Box);
  G.updateNode(nodeId, "shape", "circle");
  G.updateNode(nodeId, "color", "red");
  nodeId = G.addNode(Box);
  G.updateNode(nodeId, "shape", "egg");
  nodeId = G.addNode(Box);
  nodeId = G.addNode(Box);

  // Adding edges to the Nodes.
  G.addEdge(0, 1, Arrow);
  G.addEdge(1, 2, Crow);
  G.addEdge(2, 3, Tee);
  G.addEdge(3, 4, Dot);

  cout << G << endl << "}" << endl << endl;
  fout << G << endl << "}" << endl << endl;

  // making the doubly linked list
  // and sending in default colors and shapes
  fout << "digraph Doubly_Linked_List{" << endl;
  fout << "rankdir = LR" << endl;
  cout << "digraph Doubly_Linked_List{" << endl;
  cout << "rankdir = LR" << endl;
  nodeId = D.addNode(Box);
  nodeId = D.addNode(Box);
  nodeId = D.addNode(Box);
  nodeId = D.addNode(Box);
  nodeId = D.addNode(Box);

  //updating the color and shapes of some of the nodes.
  D.updateNode(1, "shape", "oval");
  D.updateNode(2, "shape", "triangle");
  D.updateNode(3, "color", "pink");

  D.addEdge(0, 1, Arrow);
  D.addEdge(1, 0, Arrow);
  D.addEdge(1, 2, Dot);
  D.addEdge(2, 1, Tee);
  D.addEdge(2, 3, Crow);
  D.addEdge(3, 2, Tee);
  D.addEdge(3, 4, Arrow);
  D.addEdge(4, 3, Arrow);

  cout << D << endl << "}" << endl << endl;
  fout << D << endl << "}" << endl << endl;
  ;

  // Making the binary search tree with default colors and shapes.
  fout << "digraph Binary_Search_Tree{" << endl;
  cout << "digraph Binary_Search_Tree{" << endl;
  nodeId = B.addNode(Box);
  nodeId = B.addNode(Box);
  nodeId = B.addNode(Box);
  nodeId = B.addNode(Box);
  nodeId = B.addNode(Box);
  nodeId = B.addNode(Box);
  nodeId = B.addNode(Box);

  B.addEdge(0, 1, Arrow);
  B.addEdge(0, 2, Arrow);
  B.addEdge(1, 3, Arrow);
  B.addEdge(1, 4, Arrow);
  B.addEdge(2, 5, Arrow);
  B.addEdge(2, 6, Arrow);

  cout << B << endl << "}" << endl << endl;
  fout << B << endl << "}" << endl << endl;

  //Making the record shape and passing in different parameters.
  map<string, string> Record1;
  map<string, string> Record2;
  map<string, string> Record3;

  Attribute R1;
  Attribute R2;
  Attribute R3;

  Record1["shape"] = "record";
  Record1["color"] = "red";
  R1.addAttributes(Record1);

  Record2["shape"] = "record";
  Record2["color"] = "blue";
  R2.addAttributes(Record2);

  Record3["shape"] = "record";
  Record3["color"] = "purple";
  R3.addAttributes(Record3);

  fout << "digraph Record{" << endl;
  fout << "rankdir = LR" << endl;
  fout << "tailclip = false" << endl;
  cout << "digraph Record{" << endl;
  cout << "rankdir = LR" << endl;

  nodeId = Z.addNode(Record1);
  nodeId = Z.addNode(Record1);
  nodeId = Z.addNode(Record2);
  nodeId = Z.addNode(Record2);
  nodeId = Z.addNode(Record3);
  Z.updateNode(0, "label", "{<A> 1 | 2 | <B> 3}");
  Z.updateNode(1, "label", "4");
  Z.updateNode(2, "label", "{<C> 5 | <D> }");
  Z.updateNode(3, "label", "6");
  Z.updateNode(4, "label", "{<E> 7 | <F> 8}");

  Z.addEdge(0, "A", 1, "1", Arrow);
  Z.addEdge(0, 2, Arrow);
  Z.addEdge(1, 3, Arrow);
  Z.addEdge(2, "D", 4, "F", Arrow);
  Z.addEdge(3, 4, Arrow);

  cout << Z << endl << "}";
  fout << Z << endl << "}";

  fout.close();
}