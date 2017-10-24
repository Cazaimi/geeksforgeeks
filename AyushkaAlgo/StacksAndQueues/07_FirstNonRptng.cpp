#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n;i++)
#define print cout << 

using namespace std;

void random_function(vector <char> input){
    queue <char> q;
    vector <int> hash(26);
    char firstnonrptng = input.at(0);
    q.push(firstnonrptng );
    hash.at(input.at(0)-97)++;
    cout << firstnonrptng << " ";
    
    for(int i = 1;i < input.size();i++){
        //cout << "this\n";
        //if(!q.empty()) cout << q.front()-97 << " " << hash.at(q.front()-97) << endl;
        //else cout << -1 << endl;
        //cout << i << " " << input.at(i) << " ";
        if(input.at(i) == q.front()){
            hash.at(input.at(i) - 97)++;
            while( !q.empty() ){
                if((hash.at(q.front()-97) > 1)){
                    q.pop();
                }
                else break;
            }
          
            if(!q.empty()){ 
                cout << q.front() << " ";
            }
            else { 
                cout << "-1 ";
            }
        }
        else{
            if(hash.at(input.at(i)-97) == 0){
                q.push(input.at(i));
                //cout << "Pushing:" << input.at(i) << endl;
            }
            hash.at(input.at(i) - 97)++;            
            if(!q.empty()) cout << q.front() << " ";
            else { cout << "-1 ";}
        }
        //cout << endl;
    }
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    int n = 0;
	    cin >> n;
	    vector <char> input(n);
	    loop(i,0,n){
	        cin >> input.at(i);
	    }
	   random_function(input); 
	   cout << endl;
	}
	return 0;
}
