/* Merge two sorted linked lists (Function Problem)
   
Given two linked lists sorted in ascending order. Merge them in-place and return head of the merged list.   
For example, if first list is 10->20->30 and second list is 15->17, then the result list should be 10->15->17->20->30.

It is strongly recommended to do merging in-place using O(1) extra space.

Input:
You have to complete the method which takes 2 argument: the head of the first linked list  and the head of second linked list. 
You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the list obtained by merging the two sorted linked list passed as argument.

Constraints:
1 <=T<= 200
1 <= size of linked lists <= 1000
1 <= Data in linked list nodes <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 

Output:

2 3 5 10 15 20 40 
1 1 2 4 

*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */

Node* SortedMerge(Node* n1,   Node* n2)
{
	Node * head = n1->data < n2->data?n1:n2;
	//cout << head -> data << endl;
	int i = 0;
	while(n1 != nullptr or n2!= nullptr){

		i++;
		//if(i == 10) break;
		if(n1 != nullptr and n2!= nullptr){

			cout << "n1:" << n1-> data << " n2:" << n2 -> data << endl;
			if(n1 -> data < n2 -> data){
				cout << "fjn\n";
				if(n1 -> next != nullptr){
					if(n1->next -> data < n2 -> data){
					//no need to change.
					n1 = n1 -> next;
					}
					else if(n1->next -> data >= n2 -> data){
						cout << "in here\n";
						Node * temp = n1 -> next;
						n1 -> next = n2;
						n1 = temp;  
					}
				}
				else{
					n1 -> next = n2;
					n1 = nullptr;
				}
			}
			else if(n1-> data > n2->data) {
				cout << "njf\n";
				if(n2 -> next != nullptr){
					if(n2 -> next -> data < n1 -> data){
						//no need to change.

						n2 = n2 -> next;
					}
					else if(n2 -> next -> data >= n1 -> data){
						Node * temp = n2 -> next;
						n2 -> next = n1;
						n2 = temp;
					}
				}
				else{
					n2 -> next = n1;
					n2 = nullptr;
				}
			}
			else if(n1 -> data == n2 -> data){
				if(n1 -> next == nullptr or n2 -> next == nullptr){
					if(n1 -> next == nullptr){
						n1 -> next = n2;
						n1 = nullptr;
					}
					else if (n2 -> next == nullptr){
						n2 -> next = n1;
						n2 = nullptr;
					}
				}
				else{
					Node * temp = n2 -> next;
					n2 -> next = n1;
					n2 = temp;
				}
			}
		}
		else if(n1 == nullptr){
			//don't do anything.
			n2 = n2 -> next;
		}
		else if(n2 == nullptr){	
			//don't do anything.
			n1 = n1 -> next;
		}
	} 

	return head;
}

/*/ C program to merge two sorted linked lists
// in-place.
#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
 
// Function to create newNode in a linkedlist
struct Node *newNode(int key)
{
    struct Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
// Merges two lists with headers as h1 and h2.
// It assumes that h1's data is smaller than
// or equal to h2's data.
struct Node *mergeUtil(struct Node *h1,
                      struct Node *h2)
{
    // if only one node in first list
    // simply point its head to second list
    if (!h1->next)
    {
        h1->next = h2;
        return h1;
    }
 
    // Initialize current and next pointers of
    // both lists
    struct Node *curr1 = h1, *next1 = h1->next;
    struct Node *curr2 = h2, *next2 = h2->next;
 
    while (next1 && next2)
    {
        // if curr2 lies in between curr1 and next1
        // then do curr1->curr2->next1
        if ((curr2->data) > (curr1->data) &&
            (curr2->data) < (next1->data))
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
 
            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // if more nodes in first list
            if (next1->next)
            {
                next1 = next1->next;
                curr1 = curr1->next;
            }
 
            // else point the last node of first list
            // to the remaining nodes of second list
            else
            {
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}
 
// Merges two given lists in-place. This function
// mainly compares head nodes and calls mergeUtil()
struct Node *merge(struct Node *h1,
                          struct Node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
 
    // start with the linked list
    // whose head data is the least
    if (h1->data < h2->data)
        return mergeUtil(h1, h2);
    else
        return mergeUtil(h2, h1);
}
 
// Driver program
int main()
{
    struct Node *head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
 
    // 1->3->5 LinkedList created
 
    struct Node *head2 = newNode(0);
    head2->next = newNode(2);
    head2->next->next = newNode(4);
 
    // 0->2->4 LinkedList created
 
    struct Node *mergedhead =
    merge(head1, head2);
 
    printList(mergedhead);
    return 0;
} */