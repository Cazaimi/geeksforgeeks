#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(int n){
    
    int count = 0;
    while(n > 0){
        
        if(n%2!=0) n-= 1;
        else n /= 2;
        count++;
    }
    
    return count;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    cout << random_function(n) << endl;
	}
	return 0;
}
