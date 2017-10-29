/* Serialize and Deserialize a Binary Tree (Function Problem)

Serialization is to store a tree in an array so that it can be later restored 
and Deserialization is reading tree back from the array. Now your task is to 
complete the function serialize which stores the tree into an array A[ ] and 
deSerialize which deserializes the array to tree and returns it.

Note: The structure of tree must be maintained.

Input:
The task is to complete two method serialize and deSerialize.  The method 
serialize takes  two arguments, the first is the root of Binary Tree and 
second argument is an array A[ ] which stores the serialized tree. The method 
deSerialize takes only one argument which is the serialized array A[] and 
returns the deserialzed tree's root . The struct Node has a data part which 
stores the data, pointer to left child and pointer to right child.There are 
multiple test cases. For each test case, this method will be called individually.

Output:
The  output in the expected output will be the inorder traversal of the returned tree .

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 100

Example(To be used only for expected output):
Input
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
2 1 3
40 20 60 10 30



There are two test casess.  First case represents a tree with 3 nodes and 2 edges 
where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test 
case represents a tree with 4 edges and 5 nodes.

Note:The Input/Ouput format and Example given above are used for system's 
internal purpose, and should be used by a user for Expected Output only. As it 
is a function problem, hence a user should not read any input from stdin/console, 
and should not print anything on stdout/console. The task is to complete the function 
specified, and not to write the full code.
 */

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
	if(root == NULL){
		;//do nothing.
	}
    serialize(root -> left, A);
    //A.push_back(root -> data);
    serialize(root -> right,A);
}
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
   //Your code here
	bool left = false;
	bool right = false;
	Node * head = new Node;
	Node * prev = new Node;
	head -> data = A.at(0);
	/*prev = head;
	for(int i = 0;i < A.size();i++){
		Node * current = new Node;
		prev -> right = current;
		prev = current;
	}*/
	return head;
}
