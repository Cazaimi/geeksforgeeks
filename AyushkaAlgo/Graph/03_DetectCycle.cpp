#include<bits/stdc++.h>



using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}



/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
*/
bool isThisCyclic(int v, vector <int> &visited, vector <int> &GreySet, vector <vector <int> > adj){
    
    if(visited[v] == 0){
        
            GreySet[v] = 1;
            for(int i = 0; i < adj[v].size(); i++){
                //cout << v << " " << adj[v][i] << endl;
                if( GreySet[adj[v][i]] == 1)  return true;
                bool cycle = isThisCyclic(adj[v][i], visited, GreySet, adj);
                if(cycle == true) return true;
            }
            
            visited[v] = 1;
            GreySet[v] = 0;
    }
    return false;
}
#define loop(i,a,n) for(int i = a;i < n; i++)
/*You are required to complete this method*/
bool Graph :: isCyclic()
{
//Your code here

    vector <int> visited(V);
    vector <int> GreySet(V);
    
    vector <vector <int> > adj_own;
    list <int>:: iterator t;
    loop(i,0,V){
        vector <int> row;
        for(t = adj[i].begin();t != adj[i].end(); t++){
            row.push_back(*t);
        }
        adj_own.push_back(row);
    }
    
    for(int i = 0; i < V;i++){
        
        if(isThisCyclic(i, visited, GreySet, adj_own))
            return true;
    }
    
    return false;
}


int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int _size,N;
        cin>>_size>>N;
        Graph *g = new Graph(_size);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);

        }
        cout<<g->isCyclic()<<endl;
    }
}

