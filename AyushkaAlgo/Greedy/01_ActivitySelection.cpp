#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int findNextAct(int a,vector <pair <int,int> > &times){
	
	int currentEndTime = times[a].second;
	for(int i = a;i < times.size(); i++){
		if(times[i].first >= currentEndTime) return i;
	}
	
	return -1;
}

int random_function(vector <pair <int,int> > times){
	
	//Sorting the times according to the starting times.
	sort(times.begin(),times.end());
	int n = times.size(),count = 0,i = 0;
	/*loop(i,0,n) 
	cout << times.at(i).first << " " 
	<< times.at(i).second << endl;
	*/
	while(i < n){
		cout << "i:"<< i << "\n";
		int indexWhichIsChosen = i;
		for(int j = i+1;j < n;j++){
			if(times[j].second < times[indexWhichIsChosen].second){
				indexWhichIsChosen = j;
				cout << "j:" << j << endl;
			} 
		}
		cout << "At:" << i << " and Chosen index is:" << indexWhichIsChosen << endl;
		//Now, chose this activity.
		i = findNextAct(indexWhichIsChosen, times);
		count++;
		cout << "Found at:" << i << endl;
		if(i == -1) break; 
	}//	*/
	
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
	    vector <pair <int,int> > times(n);
	    loop(i,0,n)
	        cin >> times.at(i).first;
	    loop(i,0,n)
	        cin >> times.at(i).second;
	    
	    
	    cout << random_function(times) << endl;
	    
	    /* For the testing purpose: 
	    sort(times.begin(),times.end());
	    cout << findNextAct(1,times) << endl;
	    */
	}
	return 0;
}
