/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
    Node * slow = node;
    Node * fast = node;
    
    cout << node -> next ->data << endl;
    
    /*
    int istherealoop  = 1;
    while(slow != fast){
        cout << "slow:" << slow ->data << " fast:" << fast -> data << endl;
        if(fast -> next == nullptr or fast == nullptr){
            cout << "In here\n";
            break;
            istherealoop = 0;
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    cout << slow -> data << " " << fast -> data << endl;
    slow -> next == nullptr;
    cout << "istherealoop:" << istherealoop << endl;
    /*if(istherealoop){
        int noofloopelements = 0;
        do{
            slow = slow -> next;
            fast = fast -> next -> next;
            noofloopelements++;
        }while(slow != fast);
        
        int k = 0;
        fast = node;
        while(k < noofloopelements){
            fast = fast -> next;
        }
        while(1){
            if(fast -> next == slow -> next){
                fast -> next = nullptr;
            }
        }
            
    }    */
    
    node -> next  = nullptr;
}
