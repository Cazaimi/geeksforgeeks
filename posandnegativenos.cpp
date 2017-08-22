#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int t = 0;
	cin >> t;
	
	while(t>0){
	    
	    //the setup
	    int n = 0;
	    cin >> n;
    	vector <int> array(n);
    	for(int i=0;i<n;i++){
    	    int temp =0;
    	    cin >> temp;
    	    array.at(i) = temp;
    	}
    	
    	//the process
    	
    	//Old, better process. It doesn't work.
    	/*sort(array.begin(),array.end());
    	for(int j=0;j<n/2;j++){
    	    cout << array.at(j+n/2) << " " << array.at(j) << " ";
    	}*/
    	
    	//Newer, worse process.
    	int pos = 0, neg = 0, switc = 1, firstTimeCheck = 1;
    	while(neg < n and pos < n){
    	    if(switc == 1){
        	    if(array.at(pos) > 0){
    	            cout << array.at(pos) << " ";
    	            switc = -1;
    	            firstTimeCheck = 1;
	 	    neg++;
    	        }
    	        else{
    	            if(firstTimeCheck == 1){
    	                neg = pos;
    	                firstTimeCheck = -1;
    	            } 
    	            pos++;
    	        }
    	    }
    	    else if(switc == -1){
    	       if(array.at(neg) < 0){
    	            cout << array.at(neg) << " ";
    	            switc = 1;
    	            firstTimeCheck = 1;
		    pos++;
    	        }
    	        else{
    	            if(firstTimeCheck == 1){
    	                pos = neg;
    	                firstTimeCheck = -1;
    	            } 
    	            neg++;
    	        } 
    	    }
    	}
    	
    	t--;
    	cout << endl;
	}
	
	return 0;
}
