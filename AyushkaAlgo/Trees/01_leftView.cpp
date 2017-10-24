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
// A wrapper over leftViewUtil()
#include <queue>

void leftView(Node *root)
{
   queue <Node*> q;
   q.push(root);
   int thislevel = 0;
   int i = 0;
   int prevlevel = 1;
   cout << root -> data << " ";
   while(!q.empty()){
   		Node * current = q.front();
        cout << prevlevel << " " << i << " " << thislevel << endl; 
   		if(i == prevlevel){
   			cout << current -> data << " ";
   			i = 0; 
			prevlevel = thislevel;
   			thislevel = 0;

   		}

   		

   		if(current -> left != NULL){
   			q.push(current -> left);
   			thislevel++;
   		}
   		if(current -> right != NULL){
   			q.push(current -> right);
   			thislevel++;
   		}
   		
   		q.pop();
   		i++;
    }
}