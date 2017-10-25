  /*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
int whichIsIt(int root, int n1, int n2){
    int temp = min(n1,n2);
    n2 = max(n1,n2);
    n1 = temp;
    if(root < n1 and root < n2) return 1;
    else if(root == n1) return 2;
    else if(root > n1 and root < n2) return 3;
    else if(root == n2) return 4;
    else if(root > n1 and root > n2) return 5;
}

Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL) return NULL;
   //Your code here
    int temp = min(n1,n2);
    n2 = max(n1,n2);
    n1 = temp;
    
    int which = whichIsIt(root->data,n1,n2);
    if(which == 1){
        return LCA(root->right,n1,n2);
    }
    else if(which == 2){
        return root;
    }
    else if(which == 3){
        return root;
    }
    else if(which == 4){
        return root;
    }
    else if(which == 5){
        return LCA(root -> left,n1,n2);
    }
    
}
