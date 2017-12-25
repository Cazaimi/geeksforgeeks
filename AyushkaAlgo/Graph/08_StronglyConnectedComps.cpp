/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/
#include<bits/stdc++.h>

#define loop(i,a,n) for(int i =a;i < n;i++)

struct cSux{

	vector <int> g[MAX];
};

void f1(vector <int> g[MAX], int a, int n, vector <int> &visited,stack <int> s){
	
	visited[a] = true;
	
	loop(i,0,g[a].size()){
		if(!visited[g[a][i]]){
			f1(g,g[a]g[i],n,visited,s);
		}
	}
	
	s.push(i);
}

vector <vector <int> >  getTranspose(vector<int> &g[MAX], int n){
	
	
	vector <int> new_g[MAX];
	loop(i,0,n){
		loop(j,0,g[i].size()){
			//
			g[j].push_back(g[i]g[j]);
		}
	}
	
	cSux cReallySux = new cSux;
	cReallySux.g = new_g;
	return cReallySux;
	
}

void f2(vector <int> new_g[MAX], int a, int n, vector <int> &new_visited,stack <int> s){

	new_visited[a] = 1;
	
	loop(i,0,n){
		if(!new_visited[g[a][i]]){
			f2(f2(g,g[a][i],n,new_visited,s);
		}
	}
	
}

/* The function takes an adjacency list representation of the graph g
    and two integers N and M as specified in the problem statement
    You are required to complete this method. */
int kosaraju(vector<int> g[MAX], int n, int m)
{
    // Your code here
    vector <int> visited(n);
    stack <int> Kosaraju;
    
    loop(i,0,n){
    	if(!visited[i]){
    		f1(g,i,n,visited,Kosaraju);
    	}
    }
    
    cSux ItSux = getTranspose(g,n);
   	
   	
   	vector <int> new_visited(n);
   	
   	int count = 0;
   	while(!kosaraju.empty()){
   		
   		int i = kosaraju.top();
   		kosarju.pop();
   		
   		if(!new_visited[i]){
   			f2(itSux.g,i,n,new_visited,Kosaraju);
   			count++;
   		}
   	} 
    
    
    return count;
}

 
using namespace std;
 #define MAX 10001

int kosaraju(vector<int> g[MAX],int ,int );
 
int main()
{
	int t;
	cin>>t;
	std::vector<int> g[10001];
	while(t--)
	{
		
	

	
	memset(g,0,sizeof g);

 

	int n,m;
	cin>>n>>m;
 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
 
	cout<<kosaraju(g,n,m)<<endl;
	}
	
}
