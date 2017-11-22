#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int game(int n, int turn){
    
	//base cases.
	if(n <= 0){
		if(turn % 2 == 0)
		return 0;
		else return 1;  
	}
	
	int winner = (turn + 1) % 2;
	for(int i = 1;i < n; i++){
		if(n % i == 0){
			winner = game(n - i,turn+1);
			if(winner != turn % 2) continue;
			else break;
		}
	}

	return winner;

}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    cout << game(n,1) << endl;
	}
	return 0;
}
