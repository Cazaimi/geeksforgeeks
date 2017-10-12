/* Find the element that appears once in sorted array
   
 
 
 
 
 

Given a sorted array of integers, every element appears twice except for one. Find that single one in linear time complexity and without using extra memory.

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.

 


Output:

In each separate line print the number that appears only once in the array.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100000


Example:

Input:

1
11
1 1 2 2 3 3 4 50 50 65 65

Output:

4
*/

#include <iostream>
#include <vector>

using namespace std;

int random_function(vector <int> input){
    
    int n = input.size();

    for(int i = 1;i < n;i++){
        
        //cout << i << " ";
        if(i % 2 != 0){
            if(input.at(i) != input.at(i-1)) {
                cout << input.at(i-1);cout << endl;
                return 0;
            }
        }
    }
    
    //If we have reached here, it means that the last number
    //in the array is the odd one out.
    cout << input.at(n-1) << endl;
    return 0;
}

int main(){
    int t = 0;
    cin >> t;
    for(int j = 0;j < t;j++){
        
        int n = 0;
        cin >> n;
        vector <int> input(n);
        for(int i = 0;i < n;i++){
            int temp;cin >> temp;input.at(i) =temp;
        }
        
    int temp = random_function(input);
    }
    return 0;
}
