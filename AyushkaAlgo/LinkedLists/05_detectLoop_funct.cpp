/* 	
Detect Loop in linked list (Function Problem)

Given a linked list, check if the the linked list has a loop. Linked list can contain self
loop.

Input:
In this problem, method takes one argument: the head of the linked list. The function 
should not read any input from stdin/console.The node structure has a data part which
stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Return 1 if linked list has a loop else 0.

Constraints:
1<=T<=50
1<=N<=300

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0
Output:
True
False

Explaination:
In above test case N = 3
The linked list with nodes N = 3 is given. Then value of x=2 is given which means
last node is connected with xth node of linked list. Therefore, there exists a loop. 
For N = 4
x = 0 means then lastNode->next = NULL, then the Linked list does not contains any loop. */

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/

#include <vector>

int detectloop(Node *list)
{
	Node * current = list;
	vector <Node*> addresses;
	int m = 1;
	addresses.push_back(current);
	while(current != nullptr){
		
		current = current -> next;
		for(int i = 0;i < m;i++){
		    if(current == addresses.at(i)){
		        //found.
		        //cout << "Current:" << current << " addresses.at(i):" << addresses.at(i) << endl;
		        //cout << "Returning\n";
		        return 1;
		    }
		}
		addresses.push_back(current);
		m++;
		//if(m == 10) break;
	}

	//If we reached here, that means the vector had an end.
	//no loops.
	return 0;
}


