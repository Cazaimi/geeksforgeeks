/* Implement a Stack using 2 queue q1 and q2 .

Input (To be used for Expected Output):

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)

The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack . 
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the stack  and pop which returns a integer poped out from the stack.

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
3 4

Explanation:

In the first test case for query 
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4   */
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void transfer(queue <int> &qa,queue <int> &qb){

    //we will transfer from q1 to q2.
    while(!qa.empty()){
      qb.push(qa.front());
      qa.pop();
    }

    queue <int> q3 = qa;
}

void QueueStack :: push(int x)
{
  if(q1.empty() and q2.empty()){
    q1.push(x);
  }
  else{
      transfer(q1,q2);
      q1.push(x);
      transfer(q2,q1);
  }
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(!q1.empty()){
      int a = q1.front();
      q1.pop();
      return a;
    }
    else return -1;
}