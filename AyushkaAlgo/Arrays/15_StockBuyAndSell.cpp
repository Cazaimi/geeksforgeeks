/* Stock buy and sell
   
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. 

Input:
First line contains number of test cases T. Each test case contain the integer value 'N' denoting days followed by an array of stock prices in N days.
Output:
The maximum profit is displayed as shown below. And if there is no profit then print "No Profit".


Constraints:
1 <=T<= 100
2 <=N<= 100
1 <=arr[i]<= 10000


Example

Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:

(0 3) (4 6) 
(1 4) (5 9) 

Notice: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.
*/

#include <iostream>
#include <vector>

using namespace std;

void random_function(vector<int> input){


	//Front and End are indexes that are used
	//to navigate through the array.
	int front = 0;
	int end = 1;


	int max_diff = 0;
	int n = input.size();
	
	//maxima and minima hold the values for buying and selling indexes.
	int minima = 0;
	int maxima = 1;

    int difference = 0,price_rise_fall = 0;

	//For no profit condition
	bool noProfit = true;	
	while(end < n){
		difference = input.at(end) - input.at(front);
		price_rise_fall = input.at(end) - input.at(end-1);

        //cout << "Front:" << front <<" End:" << end << " Max_diff:"  <<  max_diff  << endl;
    
		if (difference >= 0 and price_rise_fall >= 0){
			/* price increase */
			//great
			//update maxima
			//Do not update minima
			//Update max_diff
			//Update end.
			noProfit = false;

			if(difference > max_diff){
				/* Better selling price */
				max_diff = difference;
				maxima = end;
			}

			end++;
		}
		if(difference < 0){

			//sell previous if current max_diff > 0
			//which means that print current maxima and minima
			//update end: end+=1
			//update front = end - 1
			//maxima one step forward:maxima = end
			//update minima: minima = front
			//set max_diff = 0
            //cout << "In\n";
			if(max_diff > 0) cout << "(" << minima << " " << maxima << ")" << " ";
			end+=1;
			front = end - 1;
			maxima = end;
			minima = front;
			max_diff = 0;	
            
         //   cout << front << "," << end << endl;
		}
		
		if(price_rise_fall < 0 and difference > 0){
		    //sell previous if current max_diff > 0
			//which means that print current maxima and minima
			//update end: end+=1
			//update front = end - 1
			//maxima one step forward:maxima = end
			//update minima: minima = front
			//set max_diff = 0
            //cout << "In\n";
			if(max_diff > 0) cout << "(" << minima << " " << maxima << ")" << " ";
			front = end - 1;
			maxima = end;
			minima = front;
			max_diff = 0;	
		}
	}

	if(difference > 0){
		cout << "(" << minima << " " << maxima << ")";
	}
	if(noProfit) cout << "No Profit";
	
	cout << endl;
}

int main(){

	int t = 0;
	cin >> t;
	for(int i = 0;i < t;i++){

		int n = 0;
		cin >> n;
		vector <int> input(n);
		for(int j = 0;j < n;j++){
			int temp = 0;
			cin >> temp;
			input.at(j) = temp;
		}
        
        
		random_function(input);
	}
}