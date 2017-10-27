/*	
Symmetric Tree (Function Problem)

Given a Binary Tree of size N, your task is to complete the function 
isSymettric(), that check whether a binary is Symmetric or not, i.e. 
the binary tree is Mirror image of itself or not.
For example:
The following binary tree is symmetric:

        1
      /   \
    2       2
  /   \   /   \
 3     4 4     3


But the following is not:

       1
     /   \
    2      2
     \      \
      3      3

Input:

The function takes a single argument as input, the root node of the binary tree. 
There will be T test cases and for each test case the function will be called separately. 
 

Output:
For each testcase the function should return a boolean value.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
1 1
1 2 L 1 2 R 0
2 1
10 20 R 10 20 L 20 30 R 5
2 2
10 20 R 10 20 L 10 20 R 10 20 L 20 30 L 100 

Output:
True
False
True

Explanation:
TestCase 1:

             0
           /   \
          1     1
         /       \
        2         2

Tree is mirror image of itself i.e. tree is symmetric

TestCase 2:

             5
          /    \
        10      20
      /    \      \
    20     20      30 

Tree is not mirror image of itself i.e. tree is not symmetric

TestCase 3:

              100
            /     \
          10       10
         /   \    /   \
       20     20 20    20

Tree is mirror image of itself i.e. tree is symmetric

Note:The Input/Ouput format and Example given are used for system's internal purpose,
and should be used by a user for Expected Output only. As it is a function problem,
hence a user should not read any input from stdin/console. The task is to complete
the function specified, and not to write the full code.

*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool rightandleft(Node * r1, Node * r2){
	if(r1 == NULL and r2 == NULL) return true;
	else if(r1 == NULL and r2 != NULL) return false;
	else if(r1 != NULL and r2 == NULL) return false;
	else if(r1 != NULL and r2 != NULL){
		bool left = rightandleft(r1 -> left, r2 -> right);
		bool right = rightandleft(r1 -> right, r2 -> left);
		bool current = r1 -> data == r2 -> data?true:false;
		if(left and right and current) return true;
		else return false;
	} 
}

bool isSymmetric(struct Node* root)
{
	// Code here
	return rightandleft(root,root);
}
