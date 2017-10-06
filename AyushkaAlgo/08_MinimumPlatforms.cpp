#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define loop(a,n) for(int i = a;i < n;i++)

using namespace std;

int checkifgreaterthan60(int input){
    if(input % 100 >=60 )
        return input + 40;
        
    else return input;
}

int random_function(vector <pair<int,int> > schedule) {
    priority_queue <int, vector<int>, greater<int> > platform;
    int n = schedule.size();

    
    int notr = 1; int notr_max = notr;
    
    vector <int> arrival(n); vector <int> departure(n);
    loop(0,n){
        arrival.at(i) = schedule.at(i).first;
        departure.at(i) = schedule.at(i).second;
    }
    
    platform.push(departure.at(0)); 
    loop(1,n){
        while(arrival.at(i) >= platform.top() and !platform.empty()){
            platform.pop();
            notr--;
        }
        
        //Now put the train on the platform.
        platform.push(departure.at(i));
        notr++;
        if(notr > notr_max) notr_max = notr;
    }
    
    return notr_max;
}

int main() {
	//code
	int t = 0; 
	cin >> t;
	loop(0,t){
	    int n = 0;
	    cin >> n;
	    vector <pair <int,int>> schedule(n);
	    loop(0,n){
	        int temp = 0;
	        cin >> temp;
	        schedule.at(i).first = checkifgreaterthan60(temp);
	    }
	    loop(0,n){
	        int temp = 0;
	        cin >> temp;
	        if(temp < schedule.at(i).first) temp += 2400;
	        schedule.at(i).second = checkifgreaterthan60(temp);
	    }
	    
	    
	    sort(schedule.begin(),schedule.end());
	    
	    /* Testing
	    loop(0,n){
	        cout << schedule.at(i).first << " " << schedule.at(i).second << endl; 
	    } */
	    
	    cout << random_function(schedule) << endl;
	}
	
	return 0;
}
