/* sizeOf returns the size of a char array or string that is passed as a parameter, as an interger*/

int sizeOf(char arr[]) {

  int count = 0;

  for (count;;count++){

    if(arr[count] == '\0'){

      break;

    }

  }
  
  return count;
}

/*decode takes three parameters, a binary sequence (char array), an array of structs (Library structs) and the size of that array (int). This function decoces the binary sequence and prints the letters instead, using the Library*/

void decode(char binarySequence[], struct Library *lib, int libSize) {
  //to keep track of the position in the binary sequence
  int binaryPos = 0;
  //a control for the while loop
  int flag = 1;
  //loops over and over until the end of the binary sequence is reached
  while (flag) {
    //loops through each struct, letter, in the Library
    for (int i=0;i<libSize;i++){
      //another control to check if a letters sequence matches a segment in the binary sequence
      int isTrue = 1;
      //loops through individual characters in a letters sequence
      for (int j=0;j<sizeOf(lib[i].sequence);j++) {
        //checking if any of the characters between the binary sequence and a letter sequence font match, also taking in consideration their position and each letters key (position in array)
        if (lib[i].sequence[j] != binarySequence[j+binaryPos]){
          //if any letters dont match, change the control to 0 (false)
          isTrue = 0;

          break;

        }

      }
      //check if the control is true, if yes than the sequence of a letter fit in the binary sequence postion
      if (isTrue) {
        //print the corresponding letter
        printf("%c",lib[i].letter);
        //update the binary position, that portion of the binary sequence has been "decoded"
        binaryPos += sizeOf(lib[i].sequence);

      }

    }
    //if the binary position is equal to the length of the binary positition, the end has been reached and then break out of the while loop
    if (binaryPos == sizeOf(binarySequence)){

      flag = 0;

    }

  }

}


//compares two strings or char arrays. x should always be smaller or equal in length to y. if x fits in y or if x is the same as y (in terms of their values), then return 1. If x is a prefix of y, return 1, if not 0 

int compare(char x[], char y[]) {

  int isValid = 1;

  for (int i = 0;i<sizeOf(x);i++){

    if (x[i] != y[i]) {

      isValid = 0;

      break;

    }

  }

  return isValid;

}

//isPrefix checks a struct array (Library) if there are any prefixes in the sequences. returns 1 (true), if there are prefixes and returns 0 (false), if there the Library is prefix free.

int isPrefix(struct Library *lib, int libSize) {
  //a control that stays false unless a prefix is found
  int isValid = 0;
  //loops through each individual struct in the Library
  for (int i=0;i<libSize-1;i++) {
    //if a prefix is found break the loop
    if (isValid) {

        break;

      }
    //loops through each struct in the library again, however starts at 1 further than the loop prior to this one. the two loops are checking every library struct with eachother (no struct is being checked with itself)
    for (int j=i+1;j<libSize;j++) {
      //checking which sequence is smaller. the compare method parameters must have the first paramter smaller or equal to the second paramater. if a prefix is found, isValid becomes true (gets a value of 1)
      if (sizeOf(lib[i].sequence)>sizeOf(lib[j].sequence)) {
        
        isValid = compare(lib[j].sequence, lib[i].sequence);
        
      } else {

        isValid = compare(lib[i].sequence, lib[j].sequence);
        
      }
      //if a prefix is found break the loop
      if (isValid) {

        break;

      }

    }

  }

  return isValid;

}