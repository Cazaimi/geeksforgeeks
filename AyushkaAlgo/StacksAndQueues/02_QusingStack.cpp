/* Queue using two Stacks (Function Problem)

Implement a Queue using 2 stacks s1 and s2 .

Input (To be used for Expected Output):

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)

The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the queue is empty else the element poped out from the queue . 
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the quee  and pop which returns a integer poped out from othe queue.

Constraints:
1<=T<=100
1<=Q<=100
1<=x<=100

Example:
Input
1
5
1 2 1 3 2 1 4 2   

Output
2 3

Explanation:

In the first test case for query 
1 2    the quee will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3 
*/
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */
/* The method push to push element into the queue */

void transfer(stack <int> &s1, stack <int> &s2){
	//We will transfer from s1 to s2.

	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
}

void StackQueue :: push(int x)
 {
 	if(s1.empty() and s2.empty()){
 		s1.push(x);
 	}
 	else {
 		transfer(s1,s2);
 		s2.push(x);
 		transfer(s2,s1);
 	}


 }
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
	if(!s1.empty()){ 
       int a = s1.top();
       s1.pop();
       return a;      
     } 
     else {
     	return -1;
     }
}



