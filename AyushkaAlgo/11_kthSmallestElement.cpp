/* 
K’th smallest element
   
Given an array and a number k where k is smaller than size of array, the task is to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Input:

First Line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:

Corresponding to each test case, print the desired output in a new line.

Constraints:

1<=T<=200
1<=N<=1000
K

Expected Time Complexity: O(n)

Example:

INPUT
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:

7
15
*/

#include <iostream>
#include <vector>
#define loop(i,a,n) for(int i = a;i < n;i++)
#define nl cout << endl

using namespace std;

void print(vector <int> &input){

	loop(i,0,input.size()){
		cout << input.at(i) << " ";
	}
	nl;
}

int partition(int start, int end, vector <int> &input){

	int pivot = input.at(end);
	int index = start;


	loop(j,start,end){

		if(input.at(j) < pivot){
			swap(input.at(j), input.at(index));
			index++;
		}
	} 
	swap(input.at(index),input.at(end));
	return index;
}

void quickS(int start, int end, vector <int> &input){
 	if(start < end){

		//First get the position of the pivot.
		int pos = partition(start, end, input);

		//Then quicksort the left and right partitions.
		quickS(start,pos-1,input);
		quickS(pos+1,end,input);

		//Done.
	}
}


int random_function(vector <int> &input,int k){
	quickS(0,input.size() - 1,input);
	return input.at(k);
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <int> input(n);
	    loop(i,0,n){
	    	int temp = 0;
	    	cin >> temp;
	    	input.at(i) = temp;
	    }
	    int k = 0;
	    cin >> k;
	    random_function(input,k)
	}
	return 0;
}