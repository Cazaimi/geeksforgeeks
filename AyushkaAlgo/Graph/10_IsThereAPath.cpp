/*	
Find whether path exist
   
 
 
 
 
 

Given a N X N matrix (M) filled with 1 , 0 , 2 , 3 . Your task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

    A value of cell 1 means Source.
    A value of cell 2 means Destination.
    A value of cell 3 means Blank cell.
    A value of cell 0 means Blank Wall.

Note : there is only single source and single destination.
 

Examples:

Input : M[3][3] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};
Output : Yes

Input : M[4][4] = {{ 0 , 3 , 1 , 0 },
                   { 3 , 0 , 3 , 3 },
                   { 2 , 3 , 0 , 3 },
                   { 0 , 3 , 3 , 3 }};
Output : Yes


Input:
The first line of input is an integer T denoting the no of test cases. Then T test cases follow. Each test case consists of 2 lines . The first line of each test case contains an integer N denoting the size of the square matrix . Then in the next line are N*N space separated values of the matrix (M) .

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0
Output:
1
0*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

pair <int,int> findPoint(vector <vector <int> > input, int a){
	
	loop(i,0,input.size()){
		loop(j,0,input[i].size()){
			if(input[i][j] == a)
				return make_pair(i,j);
		}
	}
	
	return make_pair(-1,-1);
}

int f(vector <vector <int> > input){
	
	int n = input.size();
	
	pair <int,int> source = findPoint(input,1);
	pair <int,int> dest = findPoint(input,2);

	stack <pair <int,int> > s;
	s.push(source);
	
	vector <vector <int> > visited;
	loop(i,0,n){
		vector <int> row(n);
		visited.push_back(row);
	} 
	
	while(!s.empty()){
		
		pair <int,int> currPoint = s.top();
		s.pop();
		
		int i = currPoint.first, j =currPoint.second;
		//cout << i << " " << j << endl;
		visited[i][j] = 1;
		
		if(currPoint == dest) return 1;
		
		if(i != 0){
			if(input[i-1][j] >= 2 and !visited[i-1][j] ) s.push(make_pair(i-1,j));
		}
		if(j != 0){
			if(input[i][j-1] >= 2 and !visited[i][j-1]) s.push(make_pair(i,j-1));
		}
		if(i != n-1 ){
			if(input[i+1][j] >= 2 and !visited[i+1][j] ) s.push(make_pair(i+1,j));
		}
		if(j != n-1){
			if(input[i][j+1] >= 2 and !visited[i][j+1]) s.push(make_pair(i,j+1));
		}
		
	}

	return 0;

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <vector <int> > input;
	    loop(i,0,n){
	    	vector <int> row(n);
			loop(j,0,n){
		        cin >> row.at(j);
		    }
		    input.push_back(row);
	    }
	    
	    
	    cout << f(input) << endl;
	    
	}
	return 0;
}
