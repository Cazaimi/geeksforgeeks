     /*

     Rotate a Linked List (Function Problem)

     Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer smaller than or equal to length of the linked list.
     For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40.

     Input:

     In this problem, complete the method which takes two argument: the head of the linked list and int k. We should not read any input from stdin/console.
     The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
     There are multiple test cases. For each test case, this method will be called individually.

     Output:
     Rotate the link list from index k and return its new head pointer.


     Note: If you use "Test" or "Expected Output Button" use below example format

     Example:
     Input:
     1
     8
     1 2 3 4 5 6 7 8
     4

     Output:
     5 6 7 8 1 2 3 4
     */


     /*
     Please note that it's Function problem i.e.
     you need to write your solution in the form of Function(s) only.
     Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


     /*
     Rotate a linked list after node k
     The input list will have at least one element  
     Return pointer to head of rotated linked list 
     Node is defined as 
     struct node
     {
     int data;
     struct node *next;
     }
     */


void rotate(struct node **head_ref, int k){ 

     node * current = *head_ref;
     node * new_head = nullptr;
     node * new_headminus1 = nullptr;
     node * last = nullptr;
     int n = 1;
     while(current -> next!= nullptr){
          current = current -> next;
          n++;

     }
     last = current;

     //Now we know about the number of nodes in the linked list.
    
    if(k % n != 0){
          k = k % n;
          int m = 0;
          current = *head_ref;
          while(current != nullptr){
               if(m == k-1){
                    new_headminus1 = current;
               }
               if(m == k){
                    new_head = current;
               }
               current = current -> next;
               m++;
          }

          //Now, we have the values for new head, new head-1 and last.
          //10-20-30-40-50-60 -> 50-60-10-20-30-40
          new_headminus1 -> next = nullptr;
          last -> next = *head_ref;
          *head_ref = new_head;

          //cout << last -> data << " " << new_head -> data << " " << new_headminus1 -> data <<  endl;
     }
    // cout << last -> data << endl;

}

