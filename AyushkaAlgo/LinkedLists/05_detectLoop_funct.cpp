/* 	
Detect Loop in linked list (Function Problem)
   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

Given a linked list, check if the the linked list has a loop. Linked list can contain self loop.

Input:

In this problem, method takes one argument: the head of the linked list. The function should not read any input from stdin/console.
The node structure has a data part which stores the data and a next pointer which points to the next element of the linked list. 
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

The linked list with nodes N = 3 is given. Then value of x=2 is given which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

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


int Binary_search(vector <Node*> input, Node* toBeFound,int n){
    
    int num = 0;
    int end = n-1; int start = 0;
    if(n == 1){ if(input.at(0) == toBeFound){return -1;} else return 1;};
    while(start < end){
        
        cout << "start " << start << " end " << end << endl;
        double half =  start + (end - start) / 2;
        cout << "half " << half << endl;
        if(toBeFound >= input.at(half) ){
            //For ascending start = half;
            end = half; //for descending
        }
        else {
            //for ascending end = half;
            start = half; //for descending
        }
        
        if(input.at(start) == toBeFound) return start;
        if(input.at(end) == toBeFound) return end;

    }
    
    return -1;
}

int detectloop(Node *list)
{
	Node * current = list;
	vector <Node*> addresses;
	int m = 1;
	addresses.push_back(current);
	while(current != nullptr){
		
		current = current -> next;
		if(m >= 2){
			int wasItBloodyHellFound = Binary_search(addresses,current,m);
			if(wasItBloodyHellFound != -1){
			//Then it was bloody hell found
			return 1; 
			}
		}
		cout << "--------\n";
		addresses.push_back(current);
		m++;
	}

	//If we reached here, that means the vector had an end.
	//no loops.
	return -1;
}