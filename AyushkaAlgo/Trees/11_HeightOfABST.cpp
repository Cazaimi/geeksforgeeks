/*Height of Binary Tree (Function Problem)
Given a binary tree, find height of it. Height of empty tree is 0 and height of below tree is 3.

        1
     /     \
   10      39
  /
5

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return height tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
2
3

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 2 and right child of 1 is 3.   Second test case represents a tree with 4 edges and 5 nodes.
*/

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
/* Computes the height of binary tree with given root.  */
int BSTheight(Node * root,int level){
	if(root == NULL){
		//cout << "here\n";
		return level;
		
	}
	else{
		return max(BSTheight(root -> left,level+1),BSTheight(root -> right,level+1));
	}
}

int height(Node* node)
{
	return BSTheight(node,0);
}
