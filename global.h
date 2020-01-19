//This struct is used to build the library where each struct contains a letter and its corresponding sequence
struct Library {

   char letter;
   char sequence[250];
   
};
//the node struct is used to build a binary tree structure. each node having two more undefined node structures named left and right. easy to visualize
struct node {

 char data;
 struct node *left;
 struct node *right;

};
