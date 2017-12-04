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

int custom(pair <char,int> a, pair <char,int> b){
	
	return a.second < b.second? 1:0;
}

string decode_file(struct MinHeapNode* root, string s)
{
	vector <pair<char,int> > frequencies(26);
	int n = s.size();
	loop(i,0,26) frequencies[i].first = 96+i;
	loop(i,0,n){
		frequencies[s[i]-97].second++;
	}
	sort(frequencies.begin(), frequencies.end(), custom);	
	/*Now, the frequencies array is sorted according to the
	frequency of occurence of characters in the string, in
	ascending order.*/
	
	vector <pair <char,int> > newFreq = trimFreq(frequencies);
	
	if(newFreq.size() == 1){
		MinHeapNode* mhn = new MinHeapNode;
		mhn -> data = newFreq[0].first;
		mhn -> left = nullptr;
		mhn -> right = nullptr;
		mhn -> freq = newFreq[0].second;
	}
	
	else {
		int i = 0;
		while(i < newFreq.size()){
			
			MinHeapNode* left = new MinHeapNode;
			MinHeapNode* right = new MinHeapNode;			
			left -> data = newFreq[i].first;
			left -> freq = newFreq[i].second;
			right -> data = newFreq[i].first;
			right -> freq = newFreq[i].second;
			mhn -> left = newFreq[i].first;
			 
			i+=2;
		}
	}
	
	
		 	
}











