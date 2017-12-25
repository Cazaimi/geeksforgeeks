#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <int> input){
    int n = input.size();
    vector <int> lis(n,1);
    int maxx = 0;
    loop(i,0,n){
        loop(j,i,n){
            if(input.at(j) > input.at(i)) {
                lis.at(j) = max(lis.at(i)+1,lis.at(j));
                maxx = max(lis.at(j),maxx);
            }
            else {
                maxx = max(lis.at(j),maxx);
                continue;
            }
        }
    }
    return maxx;
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

	    cout << random_function(input) << endl;
	}
	return 0;
}
