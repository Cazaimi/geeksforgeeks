/*	
Minimum Spanning Tree (Function Problem)
   
 
 
 
 

Given a weighted, undirected and connected graph. The task is to find the sum of weights of  the edges of the Minimum Spanning Tree. You need to complete the function spanningTree which takes a graph g as its argument and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two integers n,e denoting the no of nodes and no of edges. Then in the next line are E*3 space separated values a b w where a,b denotes an edge from a to b and w is the weight of the edge.

Output:
For each test case in a new line print the sum of weights of  the edges of the Minimum Spanning Tree formed of the graph.

Constraints:
1<=T<=10
1<=n,e<=100
1<=w<=1000


Example(To be used only for expected output):
Input
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5
Output
4
5*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
    Graph is represented as adjacency list using array of vectors.  MAX 
    is an upper  limit on number of vertices.
   g[u] represents adjacency list of vertex u,  Every element of this list 
   is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
  Note : Vertex numbers start with 1 and don't need to be contiguous.   */
#define loop(i,a,n) for(int i = a;i < n; i++)
int spanningTree(vector <pair<int,int> > g[], int MAX)
{
	//Your code here
	/* Testing
	loop(i,0,MAX) {
	    loop(j,0,g[i].size()){
	        cout << g[i].at(j).first << " " << g[i][j].second << " ";
	    }	    
	    cout << endl;
	}*/ 
	
	priority_queue <pair <int,pair <int,int> >,vector <pair <int,pair <int,int> >>, greater <pair <int,pair <int,int> >> > pq;
	vector <int> visited(MAX);
	loop(i,0,g[1].size()) pq.push(make_pair( g[1][i].first,make_pair(1,g[1][i].second) ) );
	visited[1] = 1;
	int finalweight = 0;
	
	
	while(!pq.empty()){
		pair <int,pair<int,int> > p = pq.top();
		pq.pop();
		int currNode = p.second.first;
		int currWeight = p.first;
		int nextNode = p.second.second;
		
		//cout << currNode << " " << nextNode << " " << currWeight << endl; 
		if(visited[nextNode] == 0){
			visited[nextNode] = 1;
			finalweight += currWeight;
			loop(i,0,g[nextNode].size()) pq.push(make_pair( g[nextNode][i].first,make_pair(nextNode,g[nextNode][i].second) ) );
		}
	}
	
	/*loop(i,0,MAX) cout << visited[i] << " ";
	cout << endl;
	*/
	return finalweight;
}	

