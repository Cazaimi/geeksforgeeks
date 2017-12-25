/*	
Page Faults in LRU
In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when new page comes in. Whenever a new page is referred and is not present in memory, page fault occurs and Operating System replaces one of the existing pages with newly needed page.
Given a sequence of pages and memory capacity, your task is to find the number of page faluts using Least Recently Used (LRU) Algorithm .

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains number of pages n and next line contains space seaprated sequence of pages. The following line consist of the capacity of the memory.
Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then index 1 and so on). Memory is empty at the start .

Output:
Output the number of page faults.

Constraints:
1<=T<=100
1<=n<=1000
4<=capacity<=100

Example:
Input:
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4
Output:
8
7*/

#include <iostream>
#include <vector>
#include <stack>

#define loop(i,a,n) for(int i = a; i < n; i++)

using namespace std;

bool foundInCache(stack <int> s, int a){
	while(!s.empty()){
		if(s.top() == a) return true;
		else {
			s.pop();
		}	
	}
	
	return false;
}

void print(stack <int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void refreshCache(stack <int> &s, int a){
	stack <int> temp;
	temp.push(a);
	while(!s.empty()){
		if(s.top() == a){
			s.pop();
			break;
		}
		else{
			temp.push(s.top());
			s.pop();
		}
	}
	
	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}
}

void updateCache(stack <int> &s, int a, int max_size){
	
	if(s.size() < max_size) s.push(a);
	else{
		stack <int> temp;
		temp.push(a);
		while(s.size() > 1) {
			temp.push(s.top());
			s.pop();
		}
	
		s.pop();
		
		while(!temp.empty()){
			s.push(temp.top());
			temp.pop();
		}
	}
}

int pf(vector <int> input, int k){
	
	stack <int> memory;
	int misses = 0, n = input.size();
	loop(i,0,n){
		//cout << input[i] << " ";
		if(foundInCache(memory,input[i])){
			//cout << "found \n";
			refreshCache(memory,input[i]);
			//don't increment misses.
		}
		else {
			//cout << "not found \n";
			misses++;
			updateCache(memory,input[i],k);
		}
		
		//cout << "misses:" << misses << "\n";
		//print(memory); 
	}
	
	return misses;
}

int main(){

	int t = 0;
	cin >> t;
	loop(i,0,t){
		int n, k;
		cin >> n;
		vector <int> input(n);
		loop(i,0,n) cin >> input[i];
		cin >> k;
		cout << pf(input, k) << endl;
	}
}