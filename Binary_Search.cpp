#include <iostream>
#include <vector>
#include <cmath>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int Binary_search(vector <int> input, int toBeFound){
    
    int n = input.size(),num = 0;
    int end = n-1; int start = 0;
    while(start <= end){
        
        cout << "start " << start << " end " << end << endl;
        double half =  start + (end - start) / 2;
        cout << "half " << half << endl;
        if(toBeFound >= input.at(half) ){
            //For ascending start = half;
            end = half; //for descending
        }
        else {
            //for ascending end = half;
            start = half; //for descending
        }
        
        if(input.at(start) == toBeFound) return start;
        if(input.at(end) == toBeFound) return end;

    }
    
    return -1;
}

int main(){
    
    
    int n = 0,k = 0;
    cin >> n >> k;
    vector <int> input(n);
    loop(i,0,n){
        cin >> input.at(i);
    }
    
    cout << Binary_search(input,k);
    
}
