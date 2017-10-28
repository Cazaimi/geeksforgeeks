/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
int countLeaves(Node* root)
{
  if(root == NULL){
      return 0;
  }
  else{
      if(root -> right == NULL and root -> left == NULL){
          return 1;
      }
      int lef = countLeaves(root -> left);
      int righ = countLeaves(root -> right);
      return lef+righ;
  }
}

