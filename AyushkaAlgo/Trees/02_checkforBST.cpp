/*Check for BST (Function Problem)
Given a binary tree, return true if it is BST, else false. For example, the following tree is not BST, because 11 is in left subtree of 10.

        10
     /     \
   7       39
     \
      11



Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return 1 if BST else return 0.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
0

Both of the given trees are not BST.

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.
Second test case represents a tree with 4 edges and 5 nodes. */

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be 1 for following tree.
         20
     /      \
   10       30
  and return value should be 0 for following tree.
         10
     /      \
   20       30 */

 struct Node_mod{
	 Node_mod * left,*right;
	 int data;
	 int visited;
 };
Node_mod * initialize(Node * root){
	if(root == NULL){
		return NULL;//do nothing
	}
	else{
		Node_mod * temp = new Node_mod;
		temp -> data = root -> data;
		temp -> visited = 0;
		temp -> left = initialize(root -> left);
		temp -> right = initialize(root -> right);
		return temp;
	}
}

bool isBST(Node* root) {

	//Modifying the tree to include a visited variable.
	Node_mod * root_new = new Node_mod;
	if(root == NULL) return true;
	root_new = initialize(root);


	stack <Node_mod*> s;
	queue <Node_mod*> q;

	s.push(root_new);
	while(!s.empty()){
		Node_mod* current = new Node_mod;
		current = s.top();
		s.pop();
		if(current -> visited == 0){
			if(current -> right != NULL) s.push(current -> right);
			s.push(current);
			if(current ->left != NULL) s.push(current -> left);
			current -> visited = 1;

		}
		else if(current -> visited == 1){
			q.push(current);
		}
	}
	int maxx = q.front() -> data;
	bool isit = true;
	//q.pop();
	while(!q.empty()){
		//cout << q.front -> data << endl;
		if(q.front() -> data < maxx){
			isit = false;
			break;
		}
		maxx = q.front() -> data;
		q.pop();
	}
	//cout << endl;
	return isit;
}

