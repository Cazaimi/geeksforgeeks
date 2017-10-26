/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1 == NULL and r2 != NULL) return false;
    else if(r1!= NULL and r2 == NULL) return false;
    else if(r1 == NULL and r2 == NULL) return true;
    else if(r1 != NULL and r2 != NULL){
        bool isitleft = isIdentical(r1 ->left,r2->left);
        bool isitright = isIdentical(r1 -> right,r2 -> right);
        bool isitcorrect = r1 -> data==r2 -> data?true:false;
        if(isitleft and isitright and isitcorrect) return true;
        else return false;
    }
}
