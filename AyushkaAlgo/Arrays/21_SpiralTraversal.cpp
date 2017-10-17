#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void increment(int &i,int &j, int direction){
    
    direction = direction % 4;
    if(direction == 1){
        j++;  //right
    }
    else if(direction == 2){
        i++;  //down
    }
    else if(direction == 3){
        j--;  //left
    }
    else if(direction == 0){
        i--;  //up
    }
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(test,0,t){
	
	    int n = 4;
        int arr[4][4];
	    loop(i,0,n){
	        loop(j,0,n){
    	        cin >> arr[i][j];
	        }
	    }
	    /* Testing loop(i,0,n){
	        loop(j,0,n){
	            cout << arr[i][j] << " ";
	        }
	        cout << endl;
	    } */
        
        int howlonguntildirectionchange = 4;
        int count = 1;   //reduce hludc when count = 2 
        int direction = 1;   //1 -> right, 2 -> down
        //, 3 -> left, 4 -> up
        
        int travel = 1;  //to keep track of moves
        int  i = 0, j = 0, tummy =0;
        
        while(howlonguntildirectionchange > 0){
            travel = 1;
            cout << arr[i][j] << " ";
            while(travel < howlonguntildirectionchange){
                travel++;
                increment(i,j,direction);
                cout << arr[i][j] << " ";
                
            }
        
            count++;
            direction++;
            increment(i,j,direction);
            if(count == 2){
                howlonguntildirectionchange--;
                count = 0;
            }
        }
        cout << endl;
	}
	return 0;
}
