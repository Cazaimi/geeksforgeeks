/* Rotten Oranges
   
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges 

So we have to determine what is the minimum time required so that all the oranges become rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next r line contains space separated c elements each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges.(-1 if it is impossible).

Constraints:
1<=T<=100
1<=r<=100
1<=c<=100
0<=a[i]<=2

Example:
Input:
2
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1

Output:
2
-1 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

queue <pair <int,int> > q;
queue <pair <int,int> > temp;


//Queue functions
void transfer(queue <pair <int,int> >& q1, queue <pair <int,int> > &q2){
	while(!q1.empty()){
		//cout << "Pushing " << q1.front().first << "," << q1.front().second << " ";
		q2.push(q1.front());
		q1.pop();

	}
}

void empty(queue <pair<int,int> > q1){
	while(!q1.empty()) q1.pop();
}

//Conversion to Rotten Functions
//Return 1 if conversion done. 0, otherwise
int top(vector <int> input[],int i,int j){
	if(i!=0){
		if(input[i-1].at(j) == 1){
			input[i-1].at(j) = 2;
			temp.push(make_pair(i-1,j));
			return 1;
		}
		else return 0;
	}
	else return 0;
}
int bottom(vector <int> input[],int i,int j,int n){
	if(i!=n-1){
		if(input[i+1].at(j) == 1){
			input[i+1].at(j) = 2;
			temp.push(make_pair(i+1,j));
			return 1;
		}
		else return 0;
	}
	else return 0;	
}
int left(vector <int> input[],int i,int j){
	if(j!=0){
		if(input[i].at(j-1) == 1){
			input[i].at(j-1) = 2;
			temp.push(make_pair(i,j-1));
			return 1;
		}
		else return 0;
	}
	else return 0;
}
int right(vector <int> input[],int i,int j,int m){
	if(j!=m-1){
		if(input[i].at(j+1) == 1){
			input[i].at(j+1) = 2;
			temp.push(make_pair(i,j+1));
			return 1;
		}
		else return 0;
	}
	else return 0;
}

//Print
void print(vector <int> input[],int n){
	loop(i,0,n){
		loop(j,0,input[i].size()){
			cout << input[i].at(j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void test_suite(vector <int> input[],int n){
	print(input,n);
	top(input,0,1);
	print(input,n);
	top(input,1,1);
	print(input,n);
}

//Main Execution function.
int random_function(vector <int> input[],int n){
	

	//Get all the rotten oranges at t=0, & store them in Q.
	for(int i = 0;i < n;i++){
		for(int j = 0;j < input[i].size();j++){
			if(input[i].at(j) == 2){
				q.push(make_pair(i,j));
			}
		}
	}
	
	//cout << "asd" << input[0].size() << input[1].size() << endl;

	int time = 0;
	int NumOfOnes = 0;
	int prevNumOfOnes = 0;

	temp.push(make_pair(0,0));
	//print(input,n);
	while(!temp.empty()){
		if(time == 0) temp.pop();
		prevNumOfOnes = NumOfOnes;
		//cout << q.size() << endl;
		transfer(temp,q);
		//cout << q.size() << endl;
		while(!q.empty()){
			int i = q.front().first, j = q.front().second;
			int convertedornot = -1;
			convertedornot = top(input,i,j);
			if(convertedornot) NumOfOnes++;
			convertedornot = bottom(input,i,j,n);
			if(convertedornot) NumOfOnes++;
			convertedornot = left(input,i,j);
			if(convertedornot) NumOfOnes++;
			convertedornot = right(input,i,j,input[i].size());
			if(convertedornot) NumOfOnes++;
			q.pop();
			//print(input,n);
		}
		if(NumOfOnes != prevNumOfOnes){
			//The Q is empty. All the 2's have been used.
			time++;
		}
		//cout << "time:" << time << " NO1s" << NumOfOnes << " temp_size:" << temp.size() << endl;
		//if(time ==2) break;
	}

	bool allconverted = true;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < input[i].size();j++){
			if(input[i].at(j) == 1){
				allconverted = false;
				break;
			}
		}
	}

	if(allconverted == true){
		return time;
	}
	else
	return -1;

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(k,0,t){
	
	    int n = 0,m = 0;
	    cin >> n >>m;
	    vector <int> input[n];
	    loop(i,0,n){
	    	loop(j,0,m){
	    		int temp = 0;
	    		cin >> temp;
	    		input[i].push_back(temp);
	    	}
	    }
	    //test_suite(input,n);
    	cout << random_function(input,n) << endl;
    	empty(q);
    	empty(temp);
	}
	return 0;

}