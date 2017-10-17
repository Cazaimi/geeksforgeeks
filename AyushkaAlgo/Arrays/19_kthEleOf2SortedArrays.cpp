/* K-th element of two sorted Arrays
   
Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.

Input:
First line consists of test cases T. First line of every test case consists of 3 integers N, M and K, denoting number of elements in array1, number of elements in array2 and K-th element respectively. Second and Third line of every test case consists of elements of Array1 and Array2 respectively.

Output:
Print the element at the Kth position.

Constraints:
1<=T<=200
1<=N,M<=1000
1<=Ai,Bi<=1000
1<=K<=N+M

Example:
Input:
1
5 4 5
2 3 6 7 9
1 4 8 10
Output:
6
*/

#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(vector <int> a, vector <int> b,int k){
    int pointer_a = 0;
    int pointer_b = 0;
    
    int n = a.size(), m = b.size();
    int counter = 0,whichWasSentLast = 1;
    
    while(pointer_a < n and pointer_b < m){
        if(a.at(pointer_a) < b.at(pointer_b) ){
            pointer_a++;
            counter++;
            whichWasSentLast = 1;
        }
        else if(a.at(pointer_a) > b.at(pointer_b) ){
            pointer_b++;
            counter++;
            whichWasSentLast = 2;
        }
        
        if(counter == k){
            if(whichWasSentLast == 1){
                cout << a.at(pointer_a - 1);
            }
            else cout << b.at(pointer_b - 1);
            cout << endl;
            break;
        }
    }
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0,m = 0,k = 0;
	    cin >> n >> m >> k;
	    vector <int> a(n); vector <int> b(m);
        loop(i,0,n){
            cin >> a.at(i);
        }
        loop(i,0,m){
            cin >> b.at(i);
        }
        
        //cout << "fs";
        random_function(a,b,k);
    }
	return 0;
}
