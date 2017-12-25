#include <bits/stdc++.h>
#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void transfer ( queue <string> &s, priority_queue <string, vector <string>, greater<string> > &pq){
	
	while(!s.empty()){
		pq.push(s.front());
		s.pop();
	}
}

int cs(vector <string> input){
	
	int n = input.size();
	if(n == 1 and input[0].size() == 1) return 1;
	priority_queue <string, vector <string>, greater<string> > pq;
	loop(i,0,n){
		pq.push(input[i]);
	}
	
	loop(i,0,n){
		{
			queue <string> s;
			//cout << i << " input[i]:" << input[i] << endl;
			char currLast = input[i][input[i].size()-1];
			while(pq.top()[0] != currLast){
				if(pq.empty()) break;		
				
				//cout << pq.top() << "\n";
				s.push(pq.top());
				pq.pop();

			} 
			
			if(!pq.empty() and pq.top() == input[i]){
				s.push(pq.top());
				pq.pop();
				
				while(pq.top()[0] != currLast){
					if(pq.empty()) break;		
					
					//cout << pq.top() << "\n";
					s.push(pq.top());
					pq.pop();
				} 
			}
			
			if(pq.empty()) {
				//cout << "404 ";
				return 0;
			}
			pq.pop();
			transfer(s,pq);
		}
				
	}
	
	return 1;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <string> input(n);
	    loop(i,0,n){
	    	   string temp;
	        cin >> temp;
	        input[i] = temp;
	    }
	    
	    cout << cs(input) << endl;
	}
	return 0;
}
