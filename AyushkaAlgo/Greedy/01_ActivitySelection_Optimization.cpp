#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int random_function(vector <pair <int,int> > times){
	
	sort(times.begin(),times.end());
	int n = times.size(),count = 1,i = 0;
	while(i < n){
	    int j = i;
	    //cout << i << endl;
		while(j < n){
		    if(times[j].second >= times[i].first) break;
		    j++;
		}
		
		//cout << "i:" << i << " j:" << j << " count:" << count << endl;
		if(j != n)
		count++;
		i = j;
		
	}
	
	return count;
}

int main()
 {
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <pair <int,int> > times(n);
	    loop(i,0,n)
	        cin >> times.at(i).second;
	    loop(i,0,n)
	        cin >> times.at(i).first;
	    
	    
	    cout << random_function(times) << endl;
	    
	    /* For the testing purpose: 
	    sort(times.begin(),times.end());
	    cout << findNextAct(1,times) << endl;
	    */
	}
	return 0;
}

