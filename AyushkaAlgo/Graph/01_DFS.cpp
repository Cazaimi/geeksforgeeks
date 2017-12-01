/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You have to complete this function
which prints out the depth first level traversal of the 
graph starting from node s
the vector<int> g[i] represent the adjacency 
list of the ith node of the graph
 */

#define loop(i,a,n) for(int i = a;i < n; i++)
 
void dfs(int s, vector<int> g[], bool visited[])
{
    
    //loop(i,0,n)
    stack <int> st;
    st.push(s);
    visited[s] = 1;
    while(!st.empty()){
        
        int currNode = st.top();
        st.pop();
        cout << currNode << " ";
        
        for(int i = g[currNode].size()-1;i >= 0;i--){
            if(visited[g[currNode][i]] == 0 ){
                visited[g[currNode][i]] = 1;
                st.push(g[currNode][i]);
            }
        }
    }
}
