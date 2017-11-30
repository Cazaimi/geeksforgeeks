/*Huffman Decoding-1 (Function Problem)
   
 
 
 

Given a encoded string, your task is to print the decoded String.

Input:
First line consists of T test cases. Only line of every test case consists of String S.

Output:
Single line output, return the Decoded String.

Constraints:
1<=T<=100
2<=S<=1000

Example:
Input:
2
abc
geeksforgeeks
Output:
abc
geeksforgeeks */

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below 
Which contains 2 arguments 
1) root of the tree formed while encoding
2) Encoded String*/

#define loop(i,a,n) for(int i = a;i < n; i++)

string decode_file(struct MinHeapNode* root, string s)
{
	priority_queue<pair<int,char>, vector <pair <int,char> >, greater <pair<int,char> >
	vector < int > frequencies(26);
	int n = s.size();
	loop(i,0,n){
		frequencies[s[i]-97]++;
	}
	//data freq left right
	 	
}
