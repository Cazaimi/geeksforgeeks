#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int main(){

	int t = 0;
	cin >> t;
	for(int j = 0;j < t;j++){

		int n = 0;
		cin >> n;
		vector <int> input[n];
		for(int i = 0;i < n;i++){
			for(int k = 0;k < n;k++){
				int temp = 0;
				cin >> temp;
				input[i].push_back(temp);
			}
		}

		/* loop(i,0,n){
			loop(k,0,n){
				cout << input[i][j];
			}
		} */

		//indexes to traverse the matrix
		int i =0;j = 0;
		//Tells when to stop and change direction
		int EdgeTraversal = 4;
		//Tells when to change EdgeTraversal. Changes EdgeTraversal when Count = 1.  
		int EdgeTraversalCount = 0;
		//Tells how much has been travelled since the change of direction.
		int travel = 0;
		//Changes direction when count = 1;
		int directionCount = 0;

		do{
			cout << input[i][j] << " ";
			j++;
		}
		while(j <= 3);

		do{
			cout << input[i][j] << " ";
			i++;
		}
		while(i <= 3);
		
		do{
			cout << input[i][j] << " ";
			j--;
		}
		while(j >= 0);
		
		do{
			cout << input[i][j] << " ";
			i--;
		}
		while(i >= 1);

		do{
			cout << input[i][j] << " ";
			j++;
		}
		while(j <= 2);

		do{
			cout << input[i][j] << " ";
			i++;
		}
		while(i <= 2);

		cout << input[2][1] << "\n";
	}
}