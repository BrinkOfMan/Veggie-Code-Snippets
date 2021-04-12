#include <stdio.h>

// I am a C file single-line comment

/*
    I am a C file multi-line comment
*/


/*
* - -  This snippets extension works best alongside the "Better Comments" extension by Aaron Bond. - -

* - -  You can install "Better Comments" at https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments - -

* 	⭐ FEATURE: What are we building next? write the feature here
* 	📝 SCRIBBLE: Hmmm.. where to start? jot down some initial thoughts here
* 	✍🏾 TODO: Sweet, now we have a plan! jot down what needs to be worked on
* 	👾 BUGS: Everything works! well.. kinda. jot down any bugs you find
* 	📄 DOCUMENTATION: Everything really works! Summarize what your code does
* 	📌 COOL: Who knew THIS would make the function work? Note any interesting learnings.
* 	⏰ GANTT CHART: Create an ASCII Gantt chart to visualize how time will be used for different project tasks.
* 	🛑/⏳/✅ PROGRESS ICONS: Useful to see if production on something has stopped, is in progress, or has been completed.
* 	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
* 	⬇️ - - PREFIX USAGE - - ⬇️

* 		⭐ - - FEATURE - - ⭐  ==> !vftr
* 		⭐ - - FEATURES SECTION - - ⭐  ==> !vftrsec
* 		📝 - - SCRIBBLE - - 📝 ==>  !vscr 
* 		✍🏾 - - TODO - - ✍🏾 ==>  !vtodo 
* 		👾 - - BUG - - 👾 ==>  !vbug 
* 		👾 - - BUGS SECTION - - 👾 ==>  !vbugsec 
* 		📌 - - COOL - - 📌 ==>  !vcool
* 		📄 - - DOCUMENTATION - - 📄 ==>  !vdoc 
* 		⏰ - - GANTT CHART - - ⏰ ==>  !vchart 
* 		🛑/⏳/✅ - - PROGRESS ICONS - - ==>  !vprog
*/

int main(int argc, char **argv){

    printf("You typed: %s\n", argv[1]);

    return 0;
}