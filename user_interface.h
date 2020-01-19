//creates the struct Library array. takes an interger x as an input and then allocates memory to create x amount of structs then returning that interger x
int createLibrary(struct Library lib[]) {

  int keys;

  printf("Enter number of records: ");

  scanf("%d", &keys);

  lib = (struct Library*) malloc (keys * sizeof(struct Library));

  return keys;

}
//takes input which is a sequence of 0's and 1's, then initializes it using pointers
void createBinarySequence(char binarySequence[]) {

  printf("Enter a binary sequence: ");

  scanf("%s",binarySequence);

}
//this runs the user interface, doing a prefix check before as well
void run(struct Library *lib, int libSize, char binarySequence[], struct node *root) {
  //the if statement does a prefix check, if the there arnt any prefixes in the Library, the UI can run
  if (isPrefix(lib, libSize)) {

    printf("Error: a letter is a prefix of another");

  } else {
    //flag is a control for the while loop, the while loop keeps running until the user chooses to exit
    int flag = 1;
    while(flag) {

    printf("\nEnter an Option:\n1) Decode a binary sequence\n2) Traverse tree\n3) Exit\n");

    int option;

    scanf("%d", &option);
    printf("\n");
    //switch case gives user option with what to do with their Library, either decode a binary sequence or traverse through a tree, and the last one is to exit the system (breaks the while loop)
    switch(option) {

      case 1:
      
      createBinarySequence(binarySequence);
      decode(binarySequence,lib,libSize);
      printf("\n");
      break;

      case 2:
      
      createTree(root, lib, libSize);
      pre_order_traversal(root);
      printf("\n");
      break;

      case 3:
      flag = 0;
      break;

      default:
      printf("Error: Not a valid option");
      break;
    }
    
  }

  }

}