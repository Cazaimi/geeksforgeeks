/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* struct Node
 {
   int data;
   Node* next;
 }; */
/* Should return data of n'th node from the end of linked list */
int getNthFromLast(Node *head, int n)
{
    Node * first = head;
    Node * second = head;
    int i = 0;
    while(i < n-1){
        second = second -> next;
        if(second == nullptr) return -1;
        i++;
    }
    
    while(second -> next != nullptr){
        first = first -> next;
        second = second -> next;
    }
    
    return first -> data;
    
}
