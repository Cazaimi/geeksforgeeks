/*Minimum number of Coins
Given a value N, if we want to make change for N Rs, and we have infinite supply of each of the denominations in Indian currency, i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the
change.

Input:

The first line of input contains an integer T denoting the number of test cases.
Each test case consist of an Integer value N denoting the amount to get change for.


Output:

Print all the possible denominations needed to make the change in a separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 2000


Example:

Input
1
43
Output
20 20 2 1*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void denom(vector <int> input,int n){
    while(n > 0){
        int i = input.size() - 1;
        while(i > -1){
            if(n >= input[i]){
                n -= input[i];
                cout << input[i] << " ";
                break;
            }
            i--;
        }
    }
    cout << endl;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    int n = 0;
	    cin >> n;
	    vector <int> input(9);
	    input[0] = 1,
	    input[1] = 2,
	    input[2] = 5,
	    input[3] =10,
	    input[4] =20,
	    input[5] = 50,
	    input[6] = 100,
	    input[7] = 500,
	    input[8] = 1000;
	    denom(input, n);
	}
	return 0;
}
