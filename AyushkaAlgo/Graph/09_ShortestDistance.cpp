/* The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines . The first line of each test case contains two integers n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following line after it contains two integers x and y denoting the index of the destination.*/
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void pushNeighbors(int i,int j,stack <pair<int,int> > &s,vector <vector <int> > &visited,vector <vector <int> > input){
	
	int n = input.size(), m = input[0].size();
	
	if(i!=0){
		if(!visited[i-1][j]){
			if(input[i-1][j]) s.push(make_pair(i-1,j));
		}
	}
	
	if(j!=0){
		if(!visited[i][j-1]){
			if(input[i][j-1]) s.push(make_pair(i,j-1));
		}
	}

	if(i!=n-1){
		if(!visited[i+1][j]){
			if(input[i+1][j]) s.push(make_pair(i+1,j));
		}
	}
	
	if(j!=n-1){
		if(!visited[i][j+1]){
			if(input[i][j+1]) s.push(make_pair(i,j+1));
		}
	}
	


}

int spUtil(vector <vector <int> > input, vector <vector <int> > &visited, int x, int y, int i, int j){
	
	if(i == x and j == y and input[x][y] == 1) return 0;
	else if(i == x and j == y and input[x][y] == 0)return -1;
	visited[i][j] = 1;
	if(!input[i][j]) return -1;
	else{

		
		
		int n = input.size(), m = input[0].size();
		
		int a = -1, b = -1, c = -1,d = -1;
		if(i!=0){
			if(!visited[i-1][j]){
				if(input[i-1][j]) {
					 a = spUtil(input,visited,x,y,i-1,j);
					 if(a != -1) a += 1;
					 //else 
				}
			}
		}
	
		if(j!=0){
			if(!visited[i][j-1]){
				if(input[i][j-1]) {
					 b = spUtil(input,visited,x,y,i,j-1);
					 if(b != -1) b += 1;
				}
			}
		}

		if(i!=n-1){
			if(input[i+1][j]) {
				if(!visited[i+1][j]){
					 c = spUtil(input,visited,x,y,i+1,j);
					 if(c != -1) c += 1;
				}
			}
		}
	
		if(j!=m-1){
			if(input[i][j+1]) {
				if(!visited[i][j+1]){
					 d = spUtil(input,visited,x,y,i,j+1);
					 if(d != -1) d += 1;
				}
			}
		}		
		
		//cout << i << " " << j  << " " << a << " " << b << " " << c << " " << d << "\n";
		
		if(a == -1 and b == -1 and c == -1 and d == -1) return -1;
		if(a == -1) a = INT_MAX;
		if(b == -1) b = INT_MAX;
		if(c == -1) c = INT_MAX;
		if(d == -1) d = INT_MAX;
		return min(a,min(b,min(c,d)));
	}
}

int sp(vector <vector <int> > input, int x, int y){
	
	vector <vector <int> > visited;
	loop(i,0,input.size()){
	    vector <int> row(input[0].size());
		visited.push_back(row);
	}
	
	/*if (!x and !y ) {
		if(input.size() == 1 and input[0].size() == 1)
			return -1;
		else return 0;
	}*/
	
	return spUtil(input,visited,x,y,0,0);	
		
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0, m = 0;
	    cin >> n >> m;
	    vector <vector <int> > input;
	    loop(i,0,n){
	    	vector <int> row(m);
	    	loop(j,0,m){
		        cin >> row.at(j);
		    }
		    input.push_back(row);
	    }
	    int x,y;
	    cin >> x >> y;

	   	/*loop(i,0,n){
	   		loop(j,0,m){
	   			cout << input[i][j] << " ";
	   		}
	   		cout << endl;
	   	}*/
	    
	    cout << sp(input,x,y) << endl;
	}
	return 0;
}
