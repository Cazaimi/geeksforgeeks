/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You have to complete this function*/
void bfs(int s,vector<int> g[],bool visited[])
{
    queue <int> st;
    st.push(s);
    visited[s] = 1;
    while(!st.empty()){
        
        int currNode = st.front();
        st.pop();
        cout << currNode << " ";
        
        for(int i = 0;i < g[currNode].size();i++){
            if(visited[g[currNode][i]] == 0 ){
                visited[g[currNode][i]] = 1;
                st.push(g[currNode][i]);
            }
        }
    }
}
