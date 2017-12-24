#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void head(int &i, int &j, char direction){
    if(direction == 'E') i++;
    if(direction == 'W') i--;
    if(direction == 'S') j++;
    if(direction == 'N') j--;
    
    
}

void headings(string input){

    int i = 0, j = 0;
    loop(x,0,input.size()){
        head(i,j,input[x]);
    }
    
    //cout << i << " " << j << endl;
    vector <char> final;
        for(int x = 0; x < i; x++){
            final.push_back('E');
        }
        for(int y = 0; y > j; y--){
            final.push_back('N');
        }
        for(int y = 0; y < j; y++){
            final.push_back('S');
        }
        for(int x = 0; x > i; x--){
            final.push_back('W');
        }
    
    loop(i,0,final.size()) cout << final[i];
    cout << endl; 
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
        string input;
        cin >> input;
        headings(input);
	}
	return 0;
}
