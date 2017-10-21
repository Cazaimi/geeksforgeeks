/* Next larger element
   
Note:

In the editorial, they print the next greater element as:

1 2 4

1 --> 4
2 --> 4
4 --> -1

However, in the question we are asked to print it as: 

2 4 -1. Printing in this form, will require us to know the 
position of the elememt, which can only br found in O(n) time.
Hence, the total time, even if one uses Stacks becomes O(n2).
 
Here is a O(n2) solution.
 */

#include <iostream>
#include <vector>
#include <queue>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(vector <int> input){

    int n = input.size(), num = 0;
    bool flag = false;
    queue <int> temp;
    temp.push(input.at(0));
    for(int i = 0;i < n;i++){
        num = i;
        flag = false;
        for(int j = i;j < n;j++){
            if (input.at(j) > input.at(i)){
                cout << input.at(j) << " ";
                flag = true;
                break;
            }
            num++;
        }
        if(flag == false){
            cout << "-1 ";
        }    
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