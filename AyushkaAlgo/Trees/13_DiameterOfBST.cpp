/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */

int maxx;

int maxheight(Node * root, int level){
    if(root == NULL){
        return 1;
    }
    else{
        int leftheight = maxheight(root -> left,level+1);
        int rightheight = maxheight(root -> right, level+1);
        maxx = max(leftheight + rightheight-1,maxx);
        return max(leftheight,rightheight);
         
    }
}

int diameter(Node* node)
{
   // Your code here
   maxx = 1;
   int temp = maxheight(node,1);
   return maxx;
}