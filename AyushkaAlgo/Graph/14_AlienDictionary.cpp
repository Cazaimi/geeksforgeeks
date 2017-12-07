/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

#define loop(i,a,n) for(int i = a;i < n; i++)

void topoSortUtil(vector <vector <int> > g, int a, vector <int> &visited, stack <int> &s){
    
    visited[a] = true;
    
    loop(i,0,g[a].size()){
    
        if(!visited[i] and g[a][i]){
            topoSortUtil(g, i, visited, s);
        }    
    }
    s.push(a);
}

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */
string printOrder(string dict[], int n, int k)
{
   //Your code here
   vector <vector <int> > graph;
   loop(i,0,k){
       vector <int> row(k);
       graph.push_back(row);
   }
   
   for(int i = 0;i < n-1; i++){
       for(int j =0;j < min(dict[i].size(),dict[i+1].size()); j++ ){
           char a = dict[i][j], b = dict[i+1][j];
           if(a != b){
               graph[a-97][b-97] = 1;
               break;
           }
       }
   }
    
    /*Testing
    loop(i,0,k){
        loop(j,0,k){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/
    
    vector <int> visited(k);
    stack <int> s;
    
    loop(i,0,k){
        if(!visited[i]){
            topoSortUtil(graph, i, visited, s);
        }
    }
    
    string output = "";int i = 0;
    while(!s.empty()){
        char temp = s.top()+97;
        output += " ";
        output[i] = temp;
        i++;
        s.pop();
    }
    //cout << output;
    return output;
}
