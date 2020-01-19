//this function creates a new node structure, intializing it and allocating data for itself. as well as intializing the 'data' characteristic from the parameter. its left and right node characteristics get set as NULL
struct node *newNode(char data) {

 struct node *node = (struct node*)malloc(sizeof(struct node));

 node->data = data;

 node->left = NULL;

 node->right = NULL;

 return(node);

}

//createTree creates a binary tree which can be easily visualized. a one down the left and a zero traverses down to the right. this function takes the library of binary sequences and creates a tree structure
void createTree(struct node *root, struct Library *lib, int libSize) {
  //this is the current node, as in a way to navigate and place items in a tree
  struct node *current = root;
  //loops through each struct in the Library
  for (int i=0;i<libSize;i++) {
    //intializing the current to the root node
    current = root;
    //loops through each character in a sequence
    for (int j=0;j<sizeOf(lib[i].sequence);j++) {
        //checking if the character is a 1, then initilizing and moving the current to the left node, if the node is already initialize then just update the current node to the left
        if (lib[i].sequence[j] == '1'){
          
          if (current->left == NULL) {
            //if the end of the sequence is reached initialize the node's data with the sequence's corresponding letter
            if (j+1 == sizeOf(lib[i].sequence)) {

              current->left = newNode(lib[i].letter);

            } else {

              current->left = newNode('\0');

            }

          }

           current = current->left;
          
        }
        //checking if the character is a 0, then initilizing and moving the current to the right node, if the node is already initialize then just update the current node to the right
        if (lib[i].sequence[j] == '0'){
          
          if (current->right == NULL) {
            //if the end of the sequence is reached initialize the node's data with the sequence's corresponding letter
            if (j+1 == sizeOf(lib[i].sequence)) {
              
              current->right = newNode(lib[i].letter);

            } else {

              current->right = newNode('\0');

            }

          }

          current = current->right;

        }

    }

  }

}

//this function traverses through a structure tree, one that 'createTree' creates. It outputs the letters at the bottom of the tree using pre-order traversal
void pre_order_traversal(struct node* root) {
 
 if(root->data != '\0') {
  
  printf("%c ",root->data);

 }

 if(root->left != NULL) {
   
   pre_order_traversal(root->left);

 }
 if(root->right != NULL) {
   
   pre_order_traversal(root->right);

 }
 
}
