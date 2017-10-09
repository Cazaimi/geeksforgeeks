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




	int main(){


	int n = 0;
	cin >> n;
	vector <int> input(n);
	loop(i,0,n){
		int temp = 0;
		cin >> temp;
		input.at(i) = temp;
	}

	print(input);
	quickS(0,n-1,input);
	print(input);

	return 0;
}