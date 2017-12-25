#include <bits/stdc++.h>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void initialize(vector <vector <int> > &input, int n){
    
    loop(i,0,n){
        vector <int> row(n);
        input.push_back(row);
    }
}

int costs(vector <vector <int> > input){
    
    int n = input.size();
       
    priority_queue <pair<int,pair<int,int> >, vector <pair<int,pair<int,int> > >, greater <pair<int,pair<int,int> > > > pq;
    pq.push(make_pair(input[0][0],make_pair(0,0)));
    
    vector <vector <int> > visited;
    initialize(visited,n);
    
    int weight = 0;
    while(!pq.empty()){
        
        pair <int,pair <int,int> > Curr = pq.top();
        pq.pop();
        
        int currWeight = Curr.first,
        i = Curr.second.first,
        j = Curr.second.second;
        
        //cout << i << " " << j << " " << currWeight << endl;
        
        if(i == n-1 and j == n-1){
            return currWeight;
        }
        
        //if(!visited[CurrNode])
        visited[i][j] = 1;
        if(i != 0){
            if(!visited[i-1][j]){
                pq.push(make_pair(currWeight+input[i-1][j], make_pair(i-1,j)));
            }
        }
        if(j != 0){
            if(!visited[i][j-1]){
                pq.push(make_pair(currWeight+input[i][j-1], make_pair(i,j-1)));
            }
        }
        if(i != n-1){
            if(!visited[i+1][j]){
                pq.push(make_pair(currWeight+input[i+1][j], make_pair(i+1,j)));
            }
        }
        if(j != n-1){
            if(!visited[i][j+1]){
                pq.push(make_pair(currWeight+input[i][j+1], make_pair(i,j+1)));
            }
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
	    vector <vector <int> > input;
	    loop(i,0,n){
	        vector <int> row(n);
	        loop(j,0,n){
    	        cin >> row[j];
	            //cout << row[j] << "\t";
	        }
	        //cout << endl;
    	    input.push_back(row);
	    }
	    
	    cout << costs(input) << endl;
	}
	return 0;
}
