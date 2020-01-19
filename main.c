#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "functions.h"
#include "tree_functions.h"
#include "user_interface.h"

int main(void) {
  
  struct Library *lib;

  int libSize;
  
  libSize = createLibrary(lib);
  //initializes each struct in the Library, setting a letter a sequence. this cannot be put into a function or it breaks the whole code. Ive tried and debugged, but its some very weird problem. You, Mr. Knowles, said its fine if I leave it in here
  for(int i = 0; i < libSize; i++) {

      printf("Enter a letter then its sequence:\n");

      scanf(" %c %s", &(lib+i)->letter, &(lib+i)->sequence);
        
  }
  
  char binarySequence[250];
  struct node *root = newNode('\0');

  run(lib, libSize, binarySequence, root);

return 0;
}



