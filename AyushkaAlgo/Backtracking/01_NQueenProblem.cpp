/*N-Queen Problem
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. Given an integer n, print all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed in square brackets '[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where the number in the ith place denotes the ith-column queen is placed in the row with that number, if no solution exists print -1.

Constraints:
1<=T<=10
1<=n<=10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ] */

#include <bits/stdc++.h>
#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

bool isSafeHere(int a, int b, vector <vector <int> > board);
bool funcUtil(vector <vector <int> > &board, int column){
    
    int n = board.size();
    if(column >= n) {
        for(int j = 0;j < n; j++){
            cout << "[";
            for(int i = 0;i < n; i++){
                if(board[i][j] == 1){
                    if(j != n-1) cout << i << ",";
                    else cout << i << " ] ";
                }
            }
        }
        cout << "dummy\n";
        return true;
    }
    
    bool found = false;
    //iterate through rows.
    for(int k = 0;k < n; k++){
        
        //Place queen here.
        if(isSafeHere(k,column,board)){
         
            board[k][column] = 1;
            
            if(funcUtil(board,column+1))
                found = true;
                
            board[k][column] = 0;
        }
    }
    
    if(found) return true;
    else return true;
}

void func(int n){
    vector <vector <int> > board;
    
    //Chess Board
    loop(i,0,n){
        vector <int> row(n);
        board.push_back(row);
    }
    
    
    bool dummy = funcUtil(board, 0);
    if(dummy) ;
    else cout << "-1\n";
    
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    func(n);
	}
	return 0;
}

bool isSafeHere(int a, int b, vector <vector <int> > board){
    int n = board.size();
    loop(i,0,n){
        loop(j,0,n){
            if(board[i][j]){
                if(    a-i == 0
                    or b - j == 0 
                    or abs(a-i) == abs(b-j)  )
                    return false;
            }
        }
    }
    return true;
}

