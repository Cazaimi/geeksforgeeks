#include <bits/stdc++.h>
#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

vector <vector <int> > make_graph(vector <pair<int,int> > input){

    //We will ignore index '0'
    vector <vector <int> > graph;
    loop(i,0,31){
        vector <int> row (31);
        graph.push_back(row);
    }
    
    //No snakes or ladders.
    for(int i = 1;i < 31;i++){
        for(int j = 1;j < 31;j++){
            
            if(i == j)  graph[i][j] = 0;
            if(j == i+1 or j == i+2 or j == i+2 or j == i+3 or j == i+4 or j == i+5 or j == i+6){
                graph[i][j] = 1;
            }
        }
    }
    
    //Putting in snakes and ladders.
    for(int i = 0;i < input.size(); i++){
        pair <int,int> curr = input[i];
        graph[curr.first][curr.second] = 1;
    }
    
    return graph;
}

int los(int a, vector <pair<int,int> > input){
	
	loop(i,0,input.size()){
		if(input[i].first == a) return input[i].second;
	}
	
	return -1;
}

int lets_play(vector <vector <int> > graph, vector <pair<int,int> > input){

    vector <int> visited(31);
    
    
    int count = 0;
    
    /* <Position, rollsOfDice> */
    queue <pair<pair <int,int>,int> > q;
    q.push(make_pair(make_pair(1,0),-1));
	visited[1] = 1;
	
    //cout << "currPlace" << "\t" << "rolls" << "\t\t" << "Coming From\n";
    int answer = 0;
    while(!q.empty()){
        
        int currPlace = q.front().first.first;
        int rolls = q.front().first.second;
        int comingFrom = q.front().second;
        q.pop();

        visited[currPlace] = 1;
        
       //cout << currPlace << "\t\t" << rolls << "\t" << comingFrom << "\n";
        if(currPlace == 30){
            return rolls; 
        }
        
        for(int i=1;i < 31;i++){
            if(!visited[i] and graph[currPlace][i]){
                
                int trap = los(i,input);
                
                if(trap == -1)
	                q.push(make_pair(make_pair(i,rolls+1),currPlace));
	            else{
	            	if(!visited[trap]){	
	            		q.push(make_pair(make_pair(trap,rolls+1),currPlace));
	            	}
                
                }
                
            }
        }
    }
    
    //cout << endl;
    return answer-1;
    
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <pair<int,int> > input(n);
	    loop(i,0,n){
	        cin >> input.at(i).first >> input.at(i).second;
	    }
	    
	    vector <vector <int> > graph = make_graph(input);
	    
	    /* Testing
	    loop(i,0,31){
	        loop(j,0,31) cout << graph[i][j] << " ";
	        cout << endl;
	    }*/
	    
	    cout << lets_play(graph,input) << endl;
	}
	return 0;
}
