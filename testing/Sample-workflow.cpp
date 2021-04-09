/*
? 	📄  - - DOCUMENTATION - - 📄

? 	🥥 Ethan Brinkman - April 9, 2021 
? 	🥥 Example file for workfow documentation, ADS homework 19.

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

* 	⭐ - - FEATURE - - ⭐

* 	⭐ Node class 
* 	⭐ Represents a current state of buckets and the path required to reach it
* 	⭐ Also able to generate valid children states for use in BFS

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
! 	🥝 Accidentally had (j<=3) instead of  (j<3) in the While guard, so we were calling to buckets that didn't exist

*/

/*
* 	⭐ - - FEATURE - - ⭐

* 	⭐ Breadth-First Search algorithm 
* 	⭐ Implements a BFS style to test for solutions and search through child Nodes 

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

/*
? 	⏰ - - GANTT CHART - - ⏰

? Project Task:			Days: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
!		Brainstorm ideas	  ####
todo	Create Node class		  ####
*		Create BFS function	      ####
        Reduce time complexity                     ############  
?       Reduce space complexity                    ############
*/