/*Bottom View of Binary Tree (Function Problem)
Given a Binary Tree,  print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance from root.
Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                 20
               /    \
             8       22
           /   \        \
         5      3       25
               /   \
             10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.
For example, in the below diagram, 3 and 4 are both the bottom-most nodes at horizontal distance 0, we need to print 4.

                 20
               /    \
             8       22
           /   \     /   \
         5      3 4     25
                /    \
            10       14

For the above tree the output should be 5, 10, 4, 14, 25.

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which
stores the data, pointer to left child and pointer to right child.There are multiple test cases. For each test case,
this method will be called individually.

Output:
The function should print nodes in bottom view of Binary Tree.  Your code should not print a newline, it is added by
the caller code that runs your function.

Constraints:
1 <=T<= 30
0 <= Number of nodes<= 100
0 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
40 20 60 30

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3
and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.
*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
#define loop(i,a,n) for(int i = a;i < n;i++)

void print(vector <pair<int,int> > a){
    loop(i,0,a.size()) {
        if(a[i].first != -1 and a[i].second != -1)
        cout << a[i].first << " ";
    }
    //cout << endl;
}

void bottomViewUtil(Node *root, int width, int height, vector <pair<int,int> > &answer){
    
    if(root == nullptr){
        ;//do nothing.
        //cout << "height:" << height << " ";
        
    }
    else{
        if(height >= answer[width+100].second){
            answer[width+100].first = root -> data;
            answer[width+100].second = height;
            
        }
        
        bottomViewUtil(root -> left,width-1,height+1,answer);
        bottomViewUtil(root -> right,width+1,height+1,answer);
    }
}

void bottomView(Node *root){
   vector <pair<int,int> > answer(200,make_pair(-1,-1));
   
   bottomViewUtil(root,0,0,answer);
   print(answer);
}
