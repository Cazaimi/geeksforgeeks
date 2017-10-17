/** Relative Sorting
   
Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those  in A2. For the elements not present in A2. Append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

Since 2 is present first in A2[], all occurrences of 2s should appear first in A[], then all occurrences 1s as 1 comes after 2 in A[]. Next all occurrences of 8 and then all occurrences of 3.  Finally we print all those elements of A1[] that are not present in A2[]
 

Input:

The first line of input contains an integer T denoting the number of test cases. The first line of each test case is M and N.  M is the number of elements in A1 and N is the number of elements in A2.
The second line of each test case contains M elements. The third line of each test case contains N elements.

Output:

Print the sorted array according order defined by another array.

Constraints:

1 ≤ T ≤ 50
1 ≤ M ≤ 50
1 ≤ N ≤ 10 & N ≤ M
1 ≤ A1[i], A2[i] ≤ 1000

Example:

Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9  */

#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void print(vector <int> in){
	loop(i,0,in.size()){
		cout << in.at(i) << " ";
	}
	cout << endl;
}

int Binary_search(vector <int> input, int toBeFound,int start,int end){
    
    int n = input.size(),num = 0;

    while(start < end){
        
        //cout << "Looking for:" << toBeFound << "from" ;
        //cout << "start " << start << " end " << end << endl;
        double half =  start + (end - start) / 2;
        //cout << "half " << half << endl;
        if(toBeFound >= input.at(half) ){
            start = half;
        }
        else {
            end = half;
        }
        
        if(input.at(start) == toBeFound) return start;
        if(input.at(end) == toBeFound) return end;
        

    }
    
    return -1;
}

int random_function(vector <int> &a, vector <int> &b){
    
    int n = a.size(),m = b.size();
    
    std::sort(a.begin(),a.end());
    //print(a);
    vector <int> visited(n);

    for(int i = 0;i < m;i++){
        
        int whatAreWeSearchingFor = b.at(i);
        int whereWasItFound = 0,start = 0,end = n-1;

        while(whereWasItFound != -1) {
        	whereWasItFound = Binary_search(a,whatAreWeSearchingFor,start,end);
        	if(whereWasItFound != -1) {
        		start = whereWasItFound + 1;
        		cout << a.at(whereWasItFound) << " ";
        		visited.at(whereWasItFound) = 1;
        	}
		}
    }

    for(int i = 0;i < n;i++){
    	if(visited.at(i) != 1) cout << a.at(i) << " ";
    }
	
	cout << endl;
	return 1;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0,m = 0;
	    cin >> n >> m;
	    vector <int> a(n);
        vector <int> b(m);
	    loop(i,0,n){
	        cin >> a.at(i);
	    }
        loop(i,0,m){
	        cin >> b.at(i);
	    }
        
        int temp = random_function(a,b);
	}
	return 0;
}
 
