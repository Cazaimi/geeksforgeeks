/*
    
Check for Balanced Tree (Function Problem)
Given a binary tree, find if it is height balanced or not.  A tree is heigh balanced 
if difference between heights of left and right subtrees is not more than one for all 
nodes of tree. Expected time complexity is O(n).

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

 

Input:
The task is to complete the method which takes one argument, root of Binary Tree. 
The struct Node has a data part which stores the data, pointer to left child and 
pointer to right child. There are multiple test cases. For each test case, this 
method will be called individually.

Output:
The function should return true if tree is height balanced, else false.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 2 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
1
 

There are two test casess.  First case represents a tree with 3 nodes and 
2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.   
Second test case represents a tree with 4 edges and 5 nodes.
*/
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */
// This function should return tree if passed  tree 
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree
bool isBalanced(Node *root)
{
    //  Your Code here
    int wasit = height(root);
    if(wasit == -1) return true;
    else return false;
}

int height(Node * root){
    if(root == NULL) {
        return 0;
    }
    else{
        int lef = height(root -> left)+1;
        int righ = height(root -> right)+1;
        if(lef == -1 or righ == -1) return -2;
        if(max(lef,righ) - min(lef,righ) > 1) return -2;
        return max(lef,righ);
    }
}
