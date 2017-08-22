#include <iostream>
#include <vector>
using namespace std;

int main() {
	

	int t = 0;
	cin >> t;
	while(t > 0){
		
		int n = 0;
		cin >> n;
		vector <int> stations(n);

		//accepting station values
		for(int i =0;i < n;i++){
			int temp = 0;
			cin >> temp;
			stations.at(i) = temp;
		}

		//Calculating cumulative array
		vector <int> cumulative(n);
		cumulative.at(0) = -stations.at(0);
		
		for(int i = 1;i < n;i++){
			cumulative.at(i) = cumulative.at(i-1) + stations.at(i-1) - stations.at(i); 
		}

		//traversing and finding the most negative element.
		int least = cumulative.at(0);
		for(int i = 1;i<n;i++){
			if(cumulative.at(i) < least){
				least = cumulative.at(i);
			}
		}

		int p = 0;
		cin >> p;
		cout << -least * p << endl;
		t--;
	}
	return 0;
}
