/* [Reverse a linked list (Function Problem)]
   
Given pointer to the head node of a linked list, the task is to reverse the linked list.

Input:
You need to complete a method reverse() that takes head as argument and returns new head.
There are multiple test cases. For each test case, this method will be called individually.  The first line of input contains number of test cases.  Every test case has two lines, number of nodes first line and data values in next line.

Output:
Reverse the linked list and return head of the modified list.


Example:
Input:
1
6
1 2 3 4 5 6

Output:
6 5 4 3 2 1 */

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
// Should reverse list and return new head.
Node* reverse(Node *head)
{

    Node * current = head;
    Node * n = nullptr;
    Node * ntn = nullptr;
	n = current -> next;            //n means next
	if(current -> next != nullptr) ntn = current -> next -> next;  //ntn means nextToNext
	while(n != nullptr){

        n -> next = current;
		if (current == head){
			head -> next = nullptr;
		}
        
		current = n;
		n = ntn;
		if(n != nullptr) ntn = ntn -> next;

	}

	return current;
}