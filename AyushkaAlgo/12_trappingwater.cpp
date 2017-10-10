#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> input){

	int n = input.size();

	//Getting the left_max array.
	vector <int> left_max_array(n);
	int left_max = input.at(0);
	loop(i,0,n){

		if(input.at(i) > left_max){
			left_max = input.at(i);
		}

		left_max_array.at(i) = left_max;
	}


	//Getting the right max array.
	vector <int> right_max_array(n);
	int right_max = input.at(n-1);
	for(int i = n-1;i > -1;i--){

		if(input.at(i) > right_max){
			right_max = input.at(i);
		}

		right_max_array.at(i) = right_max;
	}

	//Computing the depth. Oh yeah!
	int current_volume = 0, total_volume = 0;
	loop(i,0,n){
		current_volume = min(left_max_array.at(i),right_max_array.at(i)) - input.at(i);
		if(current_volume <= 0) current_volume = 0;
		total_volume += current_volume;
	}

	return total_volume;

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
	        int temp = 0;
	        cin >> temp;
	        input.at(i) = temp;
	    }
    	cout << random_function(input) << endl;

	}

	return 0;
}

