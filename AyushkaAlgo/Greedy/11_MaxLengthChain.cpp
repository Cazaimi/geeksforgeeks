/*	
Max length chain (Function Problem)
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow .Then T test cases follow . The first line of input contains an integer N denoting the no of pairs . In the next line are 2*N space separated values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output
3
1

Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain possible is only of length one.*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
#define loop(i,a,n) for(int i = a;i < n; i++)
#include <iostream>

int compare(val a, val b){
    
    if( a.second < b.second) return 1;
    else if(a.second > b.second) return 0;
    else if(a.second == b.second) {
    		if(a.first <= b.first) return 1;
    		else return 0; 
    }
}

int maxChainLen(struct val p[],int n)
{
	sort(p,p+n,compare);
	
	/*testing*/
	//loop(i,0,n) cout << p[i].first << " " << p[i].second << endl;
	
	int count = 1, last = 0;
	loop(i,1,n){
		if(p[last].second < p[i].first){ 
		    count++;
		    last = i;
		}
	}	
	
	return count;
}


