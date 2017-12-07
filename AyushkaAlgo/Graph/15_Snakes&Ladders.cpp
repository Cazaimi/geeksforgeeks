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



int lets_play(vector <vector <int> > graph){

    vector <int> visited(31);
    
    
    int count = 0;
    
    /* <Position, rollsOfDice> */
    queue <pair <int,int> > q;
    q.push(make_pair(1,0));

    cout << "currPlace" << "\t" << "rolls" << "\n";
    
    while(!q.empty()){
        
        int currPlace = q.front().first;
        int rolls = q.front().second;
        q.pop();

        visited[currPlace] = 1;
        
       cout << currPlace << "\t\t" << rolls << "\n";
        /*if(currPlace == 30){
            return rolls-1;
            break;  
        }*/ 
        
        for(int i=1;i < 31;i++){
            if(!visited[i] and graph[currPlace][i]){
                q.push(make_pair(i,rolls+1));
                //visited[i] = 1;
            }
        }
    }
    
    //cout << endl;
    //return 1;
    
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
	    
	    cout << lets_play(graph) << endl;
	}
	return 0;
}
