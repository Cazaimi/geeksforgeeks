/*	
Shop in Candy Store
In a candy store there are N different types of candies available  and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get atmost K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to tell what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to tell what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
 

Input  
The first line of the input contains T the number of test cases. Each test case consists of two lines. The first line of each test case contains the values of N and K as described above.  Then in the next line N integers follow denoting the price of each of the N different candies.
 
Output
For each test case output a single line containing 2 space separated integers , the first denoting the minimum amount of money required to be spent and the second denoting the maximum amount of money to be spent.
Remember to output the answer of each test case in a new line.

Constraints      
1 <= T <= 50
1 <= N <= 1000
 0 <= K <= N-1
1 <= Ai <= 100
 
Expected Time Complexity : O(nlogn)

Example:
Input    
 1
 4  2
 3 2 1 4

Output
 3 7

Explanation
As according to the offer if you but one candy you can take atmost two more for free.
So in the first case you buy the candy which costs 1 and take candies worth 3 and 4 for free, also you buy candy worth 2 as well.
So min cost = 1+2 =3.
In the second case I buy the candy which costs 4 and take candies worth 1 and 2 for free, also I  buy candy worth 3 as well.
So max cost = 3+4 =7.*/

#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(vector <int> input, int n, int k){
    
    int maxx = 0, minn = 0,j = n-1;
    sort(input.begin(), input.end());
    vector <int> bought(n,0);
    loop(i,0,n){
        if(bought[i] != 1){
            bought[i] = 1;
            minn += input[i];
            int thisRound = 0;
            while(j > i and thisRound < k){
                
                bought[j] = 1;
                j--;
                thisRound++;
            }
        }
    }
    
    bought.clear();
    loop(i,0,n) bought.push_back(0);
    j = 0;
    for(int i = n-1;i > -1; i--){
        if(bought[i] != 1){
            bought[i] = 1;
            maxx += input[i];
            int thisRound = 0;
            while(j < i and thisRound < k){
                bought[j] = 1;
                j++;
                thisRound++;
            }
        }
        
    }
    
    cout << minn << " " << maxx << endl;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0, k =0;
	    cin >> n >> k;
	    vector <int> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }
	    
	    random_function(input,n,k); 
	}
	return 0;
}
