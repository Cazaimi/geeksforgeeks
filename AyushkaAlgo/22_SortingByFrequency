/*
	
Sorting Elements of an Array by Frequency
   
Given an array of integers, sort the array according to frequency of elements. For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}. 
If frequencies of two elements are same, print them in increasing order.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains
a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print each sorted array in a seperate line. For each array its numbers should be seperated by space.

Constraints:

1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ A [ i ] ≤ 60 

Example:
Input:
1
5
5 5 4 6 4
Output:
4 4 5 5 6 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(vector <int> &input){
    
    int n = input.size();
    sort(input.begin(),input.end());
    
    //Getting the frequency and storing them in min heap.
    priority_queue <pair <int,int> > count;
    int howmanytimesbro = 1;
    loop(i,1,n){
        if(input.at(i) == input.at(i-1)){
            howmanytimesbro++;
        }
        else {
            count.push(make_pair(howmanytimesbro,input.at(i-1)));
            howmanytimesbro = 1;
        }
    }
    
    //pushing in the last element.
    if(howmanytimesbro == 0){
        count.push(make_pair(1,input.at(n-1)));
    }
    else{
        count.push(make_pair(howmanytimesbro,input.at(n-1)));
    }
    
    //cout << count.size() << endl;
    /*while(!count.empty()){
        cout << count.top().first << "," << count.top().second << "\n";
        count.pop();
     }*/

    //Now comes the hard part.
    stack <pair < int,int> > s;
    int whatwasthelastcount = count.top().first;
    int whatwasthelastelement = count.top().second;
    count.pop();
    s.push(make_pair(whatwasthelastcount,whatwasthelastelement));
    while(!count.empty()){
        
        pair <int,int> p = count.top();
        count.pop();
        
        
        if(p.first == whatwasthelastcount){
            s.push(p);
        } 
        else{
            while(!s.empty()){
                loop(i,0,s.top().first){
                    cout << s.top().second << " ";
                }
                s.pop();
            }
            s.push(p);
            whatwasthelastcount = p.first;
            whatwasthelastelement = p.second;          
        }  
        
    }
    
    while(!s.empty()){
        pair <int,int> p = s.top();
        loop(i,0,p.first){
            cout << s.top().second << " ";
        }
        s.pop();
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
	    vector <int> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }
	    
	    random_function(input);
	}
	return 0;
}
