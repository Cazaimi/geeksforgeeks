/*	
N meetings in one room
There is one meeting room in Flipkart. There are n meetings in the form of (S [ i ], F [ i ]) where S [ i ] is start time of meeting i and F [ i ] is finish time of meeting i

What is the maximum number of meetings that can be accommodated in the meeting room ?

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].


Output:

In each separate line print the order in which the meetings take place separated by a space.


Constraints:

1 ≤ T ≤ 70

1 ≤ N ≤ 100

1 ≤ S[ i ], F[ i ] ≤ 100000


Example:

Input:

2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:

1 2 4 5
6 7 1 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n; i++)

using namespace std;

void random_function(vector <pair <int,int> > times){
	
	int n = times.size(), i = 0;
	vector <pair <pair<int,int>,int> > timesWithIndex;
	loop(i,0,n){
		timesWithIndex.push_back(make_pair(times[i],i+1));
	}
	sort(timesWithIndex.begin(), timesWithIndex.end());
	while(i < n){
		int j = i+1;
		while(j < n){
			if(timesWithIndex[j].first.second >= timesWithIndex[i].first.first) break;
			j++;
		}
		cout << timesWithIndex[i].second << " ";
		i = j;
	}
	cout << endl;
}

int main(){

	int t = 0,n = 0;
	cin >> t;
	loop(i,0,t){
		cin >> n;
		vector <pair <int,int> > times(n);
		loop(i,0,n) cin >> times[i].second;
		loop(i,0,n) cin >> times[i].first;
		random_function(times);		
	}
}
