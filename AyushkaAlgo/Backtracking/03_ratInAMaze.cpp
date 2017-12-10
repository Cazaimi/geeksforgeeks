/*Function problem*/

/*Rat in a Maze Problem (Function Problem)
Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). Your task is to complete the function which returns a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

For example
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer n denoting the size of the square matrix. The next line contains n*n space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

Constraints:
1<=T<=10
2<=n<=10
0<=m[][]<=1

Example(To be used only for expected output):
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR*/

#define loop(i,a,n) for(int i = a;i < n;i++)

bool isItSafe(int a, int b, vector <vector <int> > maze){
    
    int n = maze.size();
    if(a < n and b < n and a >= 0 and b >= 0){
        return maze[a][b]==1?true:false;
    }
    else return false;
}

bool printPathUtil(vector <vector <int> > maze, vector <string> &output, int row, int column,string &curr,vector <vector<int> > &visited){
    
    if(row == maze.size()-1 and column == maze.size()-1){
        output.push_back(curr);
        //cout << curr << " ";
    }
    
    //cout << "row:" << row << " column:" << column << endl;
    //cout << curr << "\n";
    visited[row][column] = 1;
    bool found = false;
    if(isItSafe(row-1,column,maze) and !visited[row-1][column]){
        curr = curr+"U";
        found = printPathUtil(maze,output,row-1,column,curr,visited);
        curr = curr.substr(0,curr.size()-1);
    }
    if(isItSafe(row,column-1,maze) and !visited[row][column-1]){
        curr = curr+"L";
        found = printPathUtil(maze,output,row,column-1,curr,visited);
        curr = curr.substr(0,curr.size()-1);
    }
    if(isItSafe(row+1,column,maze) and !visited[row+1][column]){
        //cout << "here\n";
        curr = curr+"D";
        found = printPathUtil(maze,output,row+1,column,curr,visited);
        curr = curr.substr(0,curr.size()-1);
    }
    if(isItSafe(row,column+1,maze) and !visited[row][column+1]){
        curr = curr+"R";
        found = printPathUtil(maze,output,row,column+1,curr,visited);
        curr = curr.substr(0,curr.size()-1);
    }
    
    visited[row][column] = 0;
    return found;
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    /*Getting a more sane version of the maze*/	
    vector <vector <int> > maze;
    vector <vector <int> > visited;
    loop(i,0,n){
        vector <int> row(n);
        vector <int> row2(n);
        loop(j,0,n){
            row.at(j) = m[i][j];
        }
        maze.push_back(row);
        visited.push_back(row2);
    }
    vector <string> output;
    string curr = "";
    
    
    /*loop(i,0,n){
        loop(j,0,n){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }*/
    
    bool temp =printPathUtil(maze,output,0,0,curr,visited);
    //cout << isItSafe(2,0,maze);
    
    sort(output.begin(),output.end());
    return output;
    
}
