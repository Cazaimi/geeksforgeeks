/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

#define loop(i,a,n) for(int i = a;i < n; i++)

void initialize(vector <vector <int> > &input, int N, int M){
    loop(i,0,N){
        vector <int> row;
        loop(j,0,M) row.push_back(0);
        input.push_back(row);
    }
}

void pushIntoStack(stack <pair<int,int> > &s, vector <vector <int> > &visited, int i, int j, int A[MAX][MAX]){
    
    int n = visited.size(), m = visited[0].size();
    if(i != 0){
        if(!visited[i-1][j]){
            if(A[i-1][j] == 1){
                s.push(make_pair(i-1,j));
            }
        }
    }
    
    if(j != 0){
        if(!visited[i][j-1]){
            if(A[i][j-1] == 1){
                s.push(make_pair(i,j-1));
            }
        }
    }
    
    if(i != n-1){
        if(!visited[i+1][j]){
            if(A[i+1][j] == 1){
                s.push(make_pair(i+1,j));
            }
        }
    }
    
    if(j != m-1){
        if(!visited[i][j+1]){
            if(A[i][j+1] == 1){
                s.push(make_pair(i,j+1));
            }
        }    
    }
    
    if(i != 0 and j != 0){
        if(!visited[i-1][j-1]){
            if(A[i-1][j-1] == 1){
                s.push(make_pair(i-1,j-1));
            }
        }    
    }
    
    if(i != 0 and j != m-1){
        if(!visited[i-1][j+1]){
            if(A[i-1][j+1] == 1){
                s.push(make_pair(i-1,j+1));
            }
        }    
    }
    
    if(i != n-1 and j != 0){
        if(!visited[i+1][j-1]){
            if(A[i+1][j-1] == 1){
                s.push(make_pair(i+1,j-1));
            }
        }    
    }
    if(i!= n-1 and j != m-1){
        if(!visited[i+1][j+1]){
            if(A[i+1][j+1] == 1){
                s.push(make_pair(i+1,j+1));
            }
        }    
    }
}

int findIslandsUtil(stack <pair<int,int> > s, vector <vector <int> > &visited, int A[MAX][MAX]){
    
    bool flag = false;
    if(!s.empty()) flag = true; 
    while(!s.empty()){
        int i = s.top().first,
            j = s.top().second;
            
        //cout << i << " " << j << endl;
        s.pop();
        visited[i][j] = 1;
        
        pushIntoStack(s,visited,i,j,A);
        
    }
    
    return  1;
}

/*you are required to complete this method*/
int findIslands(int A[MAX][MAX], int N, int M)
{
    //Your code here 
    stack <pair <int,int> > s;
    
    vector <vector <int> > visited;
    initialize(visited,N,M);
    
    int count = 0;
    loop(i,0,N){
        loop(j,0,M){
            if(visited[i][j] == 0 and A[i][j] == 1){
                
                /*push into stack, all the neighbouring ones
                that have not yet been visited.*/
                pushIntoStack(s,visited,i,j,A);
                
                visited[i][j] = 1;
                count += findIslandsUtil(s,visited,A);
            }
        }
    }

    return count;
}
