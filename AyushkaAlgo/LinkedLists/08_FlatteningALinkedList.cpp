/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   
   Node rootToReturn = root;
   Node * branch1 = root;
   Node * branch2 = root -> next;

while(branch1 -> next != nullptr){

	Node branch1Node = branch1;
	Node branch2Node = branch2;
	while(branch1 != nullptr or branch2 != nullptr){
		Node newnode = new Node;
		if(branch1 != nullptr and branch2 != nullptr){
			if(branch1 -> data <= branch2 -> data){
				newnode -> data = branch1 -> data;
				newnode -> bottom = branch1 -> bottom;
				if(branch1->next != nullptr) newnode -> next = branch1 -> next -> next;
				branch1 = branch1 -> bottom;
			}	
			else{
				newnode -> data = branch2 -> data;
				newnode -> bottom = branch2 -> bottom;
				if(branch2->next != nullptr) newnode -> next = branch2 -> next;
				branch2 = branch2 -> bottom;
			}
		}
		else if(branch2 == nullptr and branch1 != nullptr){
			newnode -> data = branch1 -> data;
			newnode -> bottom = branch1 -> bottom;
			if(branch1->next != nullptr) newnode -> next = branch1 -> next -> next;
			branch1 = branch1 -> bottom;
		}
		else if(branch1 == nullptr and branch1 == nullptr){
			newnode -> data = branch2 -> data;
			newnode -> bottom = branch2 -> bottom;
			if(branch2->next != nullptr) newnode -> next = branch2 -> next;
			branch2 = branch2 -> bottom;
		}		
	}

	branch1 = branch1Node;
	if(branch2Node != nullptr)branch2 = branch2Node -> next;

}

}