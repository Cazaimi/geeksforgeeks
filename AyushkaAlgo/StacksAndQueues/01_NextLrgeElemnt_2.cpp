#include <iostream>
#include <vector>
#include <stack>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(vector <int> input){

    int n = input.size();
    stack <pair <int,int> > s;
    s.push(make_pair(input.at(0),0));
    vector <int> final(n);

    for(int i = 1;i < n;i++){
        if(input.at(i) > s.top().first){
            while(!s.empty() and input.at(i) > s.top().first){
                final.at(s.top().second) = input.at(i);
                s.pop();
            }
            s.push(make_pair(input.at(i),i));
        }
        else{
            s.push(make_pair(input.at(i),i));
        }
    }

    while(!s.empty()) {
        final.at(s.top().second) = -1;
        s.pop();
    }

    for(int i = 0;i < n;i++){
        cout << final.at(i) << " ";
    }
    cout << endl;
}

int main()
 {
    //code
    int t = 0;
    cin >> t;
    loop(j,0,t){
    
        int n = 0;
        cin >> n;
        vector <int> input(n);
        loop(i,0,n){
            cin >> input.at(i);
        }

        random_function(input);
    }
    return 0;
}