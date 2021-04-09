/*
? 	📄  - - DOCUMENTATION - - 📄

? 	🥥 Ethan Brinkman - April 9, 2021 
? 	🥥 Example file for in-project documentation, ADS homework 19.

Ethan Brinkman & Sean Souksavath

Exercise 3.8: Pouring water.
We have three buckets whose sizes are 10 pints, 7 pints, and 4 pints, respectively.
The 7-pint and 4-pint buckets start out full of water, but the 10-pint bucket is initially empty.
We are allowed one type of operation: pouring the contents of one bucket into another, stopping ONLY when the source container is empty or the destination container is full.
We want to know if there is a sequence of pourings that leaves exactly 2 pints in the 7 pint or 4 pint bucket.

Write a program capable of producing a solution to this problem.
*/

/*
TODO: 	✍🏾 - - TODO - - ✍🏾

TODO: 	🥕 Create a class capable of representing the current state of buckets
TODO: 	🥕 Progress: ✅

TODO: 	🥕 Create a search algorithm to find solution sequences
TODO: 	  🥕 Create a method to generate valid upcoming neighbors
TODO: 	  🥕 Progress: ✅
TODO: 	🥕 Progress: ✅

TODO: 	🥕 Find a way to visually display the solution sequences
TODO: 	🥕 Progress: ✅

TODO: 	🥕 Reduce the time complexity (currently Θ(n^2)) 
TODO: 	🥕 Progress: ⏳

TODO: 	🥕 Reduce the space complexity (currently creates a vector path for EVERY instance of Node)
TODO:     🥕 Note: Possibly implement the path as a separate class? Only unique Nodes can add to a path?
TODO: 	🥕 Progress: ⏳
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/*
? 	📄  - - DOCUMENTATION - - 📄

? 	🥥 Node class
? 	🥥 Members:
? 	  🥥 buckets - Int ** that holds information on the current state of buckets
?     🥥 path - string vector that holds the path leading to the current state of buckets
? 	🥥 Methods:
? 	  🥥 Default constructor - receives 3 integers and creates a "buckets state" consisting with corresponding fill levels
? 	  🥥 Copy constructor - receives old "buckets state" and adds a new "buckets state" to the old path
? 	  🥥 gen_state - used in BFS; generates all valid neighbors from current "buckets state" and returns them
? 	  🥥 get_state - receives bucket index, returns its current fill value
? 	  🥥 get_rep - returns string representation of current "buckets state"
? 	  🥥 print_path - prints the path needed to reach the current "buckets state"

! 	👾 - - BUG - - 👾

! 	🥝 Invalid memory access when generating children nodes
! 	🥝 Occurs on lines 115, 122
! 	🥝 Progress: ✅
! 	🥝 Accidentally had (j<=3) instead of  (j<3) in the While guard, so we were calling to buckets that didn't exist (oops!)

*/

class Node{
  int **buckets;
  vector<string> path; // Path to reach specific Node

public:
  // Integer assignment constructor
  Node(int ten, int seven, int four){
    // Create 3 new "buckets"
    buckets = new int*[3];
    // For each bucket, assign a new int array to hold current value and max capacity
    for(int i=0; i<3; ++i){
      buckets[i] = new int[2];
    }
    // Assign bucket "ten" its current value and max capacity
    buckets[0][0]=ten; // Current value
    buckets[0][1]=10; // Max capacity
    // Do the same with bucket "seven" and "four"
    buckets[1][0]=seven;
    buckets[1][1]=7;
    buckets[2][0]=four;
    buckets[2][1]=4;

    path.push_back(this->get_rep());
  }

  // Copy + add a Node contructor
  Node(int **old, Node p){
    buckets = new int*[3];
    for(int i=0; i<3; ++i){
      buckets[i] = new int[2];
    }
    for(int i=0; i<3; ++i){
      for(int j=0; j<2; ++j){
        // Copy values from old (old node) into this bucket, add previous node to path.
        buckets[i][j]=old[i][j];
      }
    }
    path = p.path;
    path.push_back(this->get_rep());
  }

  vector<int**> gen_state(){
    //Generate all valid neightbours
    vector<int**> neighbours;
    bool next[] = {true, true, true, true, true, true};
    int pos[6][2] = {{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}}; // All possible pairs of buckets (3!)
    int j = 0;
    
    while(j<3){
      // if bucket is full, all situations it is poured into are false
      if(buckets[j][0]==buckets[j][1]){ // If the current amount of water in the bucket is equal to its max capacity
        for(int w = 0; w < 6; w++){
          if(pos[w][1]==(j)) // If the current position's bucket has a matching max capacity
            next[w]=false; // Don't fill it up anymore
        }
      }
      // if bucket is empty, all situations it is poured from are false
      if(buckets[j][0]==0){
        for(int w = 0; w < 6; w++){
          if(pos[w][0]==(j)) // If the current position's bucket has a matching current value
            next[w]=false; // Stop pouring
        }
      }
      ++j;
    }

    int i = 0;
    while(i < 6){ // Go through each position (3! possible permutations)
      // Create a new temporary bucket
      int **temp = new int*[3];
      for(int k=0; k<3; ++k){
        temp[k] = new int[2];
      }

      // Copy current bucket's values into temporary bucket
      for(int m = 0; m < 3; m++){
        for(int n = 0; n < 2; n++)
          temp[m][n]=buckets[m][n];
      }

      if(next[i]){
        int maxFill = buckets[pos[i][1]][1] - buckets[pos[i][1]][0]; // Set the maximum amount of liquid that can be filled before bucket is full
        int inAmount = buckets[pos[i][0]][0]; // How much is already in the bucket
        if(maxFill <= inAmount){ // If a valid pour is possible
          // Create a child node with: 
          temp[pos[i][0]][0]-=maxFill; // Subtract amount of liquid being poured from source bucket
          temp[pos[i][1]][0]+=maxFill; // Add that amount into receiving bucket
          neighbours.push_back(temp); // Add the valid Node to the neighbors vector
        }
        else{
          //new child with:
          temp[pos[i][0]][0]=0; // Empty source bucket
          temp[pos[i][1]][0]+=inAmount; // Add the amount that was in the now empty bucket into the receiving bucket
          neighbours.push_back(temp); // Add the valid Node to the neighbors vector
        }
      }
      i++;
    }
    // Return all valid subsequent states of buckets
    return neighbours;
  }

  int get_state(int i){
    // Return current state of bucket i's value
    return buckets[i][0];
  }

  string get_rep(){
    // Generate and return a string representation of a Node
    string s = "";
    s += '(' + std::to_string(buckets[0][0]) + ',';
    s += std::to_string(buckets[1][0]) + ',';
    s += std::to_string(buckets[2][0]) + ')';
    return s;
  }

  void print_path(){
    // Print the path to the current node
    for(int i=0; i<int(path.size()); ++i){
      cout<<path[i]<<endl;
    }
  }
};

/*
? 	📄  - - DOCUMENTATION - - 📄

? 	🥥 BFS function
? 	🥥 Variables:
? 	  🥥 FIFO queue that holds unique nodes (implemented via the use of the control map)
? 	  🥥 Control - map that holds all "buckets state"-count pairs in the search
? 	  🥥 Children - vector that holds all valid gnerated children nodes from current bucket state
? 	  🥥 Rep - acts as a return buffer from get_rep, holds string representation of node
? 	🥥 Gnereal idea of function (repeat until queue is empty):
? 	  🥥 Remove next unique Node from the top of the FIFO queue
? 	  🥥 Check if it was a solution state
? 	  🥥 Generate valid children Nodes
? 	  🥥 Check if children Nodes are unique, add to queue and control map 
*/

void BFS(Node root){
  queue<Node> FIFO;
  map<string, bool> control; // Map to see if a generated Node is unique or not
  vector<int**> children; // Will hold all possible children of a specific Node
  string rep = "";
  int steps = 0;

  FIFO.push(root); // Init queue with the root
  rep = root.get_rep(); // Get string representation of that Node, add it to map
  control[rep] = 1; // Map that string to be present


  while(!FIFO.empty()){ // While the queue isn't empty
    Node temp = FIFO.front(); // Create a temp Node from the first Node in the stack
    FIFO.pop(); // Pop top value off stack
    cout << "Queue operation " << steps << endl;

    if(temp.get_state(1) == 2 || temp.get_state(2) == 2){ // If either bucket "seven" or "four" contain 2 pints of water
      temp.print_path(); // Print the solution
      cout<< "This is a solution!\n\n";
    }
    children = temp.gen_state(); // Generate valid children nodes
    for(unsigned int i=0; i< children.size(); ++i){ // Loop through each one
      Node t(children[i], temp); // Create each child as a Node
      rep = t.get_rep(); // Get their string representation
      if(control.count(rep)){ // If this Node is a duplicate
        continue; // Do nothing
      }
      control[rep] = 1; // This string representation is now present in the map
      FIFO.push(t);
    }
    steps++; // Increment queue step counter
  }
  return;
}


int main(){

  // Create Node with buckets 10, 7, 4 holding 0, 7, and 4 pints, respectively.
  Node root(0,7,4);
  
  // Begin the BFS of possible states using root as the starting point
  BFS(root);
  

  return 0;
}