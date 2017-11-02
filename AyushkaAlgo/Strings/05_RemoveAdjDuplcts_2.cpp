/*Recursively remove all adjacent duplicates






Given a string, recursively remove adjacent duplicate characters from string. The output string should not have any adjacent duplicates.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an string str.

Output:
For each test case output a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <utility>

#define loop(i,a,n) for(int i = a;i < n;i++)
using namespace std;

void transfer(stack <pair <char,int> > &a, stack <pair <char,int> > &b){
     while(!a.empty()){
          b.push(a.top());
          a.pop();
     }
}

void random_function(string input){

     int n = input.length();
     stack <pair <char,int> > mainstack;
     stack <pair <char,int> > auxstack;
     bool flag = false;
     pair <char,int> p = make_pair(0,0);
     loop(i,0,n){
          if(mainstack.empty()){
               mainstack.push(make_pair(input.at(i),0));
          }
          else{
               if(input.at(i) == mainstack.top().first){
                    mainstack.top().second = 1;
               }
               else{
                    while(mainstack.top().second == 1 and !mainstack.empty()){
                         if(mainstack.top().first == input.at(i)){
                              mainstack.top().second = 1;
                              p = mainstack.top();
                              flag = true;
                              break;
                         }
                         auxstack.push(mainstack.top());
                         mainstack.pop();
                    }
                    transfer(auxstack,mainstack);
                    if(p.first != 0){
                         mainstack.push(p);
                         p = make_pair(0,0);
                    }
                    if(flag == false){
                         mainstack.push(make_pair(input.at(i),0));
                    }
                    flag = false;
               }
          }
     }
     stack <pair < char,int> > q;
     while(!mainstack.empty()){
          q.push(mainstack.top());
          mainstack.pop();
     }

     while(!q.empty()){
          if(q.top().second != 1)
          cout << q.top().first;
          q.pop();
     }

     cout << endl;
}

int main(){
     int t = 0;
     cin >> t;
     loop(i,0,t){
          string input;
          cin >> input;
          random_function(input);
     }
}
