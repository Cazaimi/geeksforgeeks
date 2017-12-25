/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

#define loop(i,a,n) for(int i = 0;i < n; i++)

void topoSortUtil(vector<int> g[], int a, vector <int> &visited, stack <int> &s){
    
    visited[a] = true;
    
    loop(i,0,g[a].size()){
        
        if(!visited[g[a][i]])
            topoSortUtil(g, g[a][i], visited, s);
    }

    s.push(a);
}

/* You need to complete this function */
int * topoSort(vector<int> graph[], int n)
{
	// Your code here
	vector <int> visited(n);
	stack <int> s;

	loop(i,0,n){
		if(!visited[i]){
			topoSortUtil(graph, i, visited, s);
		}
	}
	
	int * point;
	int output[n];
	loop(i,0,n){
		if(!s.empty()){
		    output[i] = s.top();
		    s.pop();
		}
	    //output[i] = i;
	}
    
    point = output;
	return point;
}
