/* Print a Binary Tree in Vertical Order (Function Problem)
Given a binary tree, your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order .

     1
    / \
  2    3
 /    /
4    5

The nodes of the above tree printed in vertical order will be
4
2
1 5
3
Your output should be 4 $2 $1 5 $3 $

Note: Each vertical line will be separated by a "$" without quotes.

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes in vertical order where  each vertical line is separated by a "$" without quotes.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20


Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 $1 $2 $
40 $20 $10 60 $30 $


There are two test cases.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.
*/
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should print vertical order such that each vertical line
   is separated by $ */
void verticalOrder(Node *root)
{
     int execute = 1;
     if(root == NULL) execute = 0;
     if(root -> left == NULL and root -> right == NULL and execute == 1){
               cout << root -> data;
     }
     else if(root -> left != NULL or root -> right != NULL and execute == 1){
          stack <pair <Node *,int> > q;
          priority_queue <pair <int,pair<int,int> >,vector<pair <int,pair<int,int> > >, greater<pair <int,pair<int,int> > >  >pq;
          int i = 0;
          q.push(make_pair(root,0));
          while(!q.empty()){
               Node * current = q.top().first;
               int level = q.top().second;
               q.pop();
               pq.push(make_pair(level,make_pair(i,current -> data)));
               //cout << pq.top().second.second << " ";
               if(current -> right != NULL) q.push(make_pair(current -> right,level + 1));
               if(current -> left != NULL) q.push(make_pair(current -> left,level - 1 ));
               i++;
          }
          //cout << endl;
          int level = pq.top().first;
          while(!pq.empty()){
               if(pq.top().first != level) {
                    cout << "$";
                    level = pq.top().first;
               }
               cout << pq.top().second.second << " ";
               pq.pop();
          }
          cout << "$";
     }
}
