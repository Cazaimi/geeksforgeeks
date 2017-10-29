/*  
Parenthesis Checker
Given an expression string exp, examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:

The first line of input contains an integer T denoting the number of test cases. 
Each test case consist of a string of expression, in a separate line.

Output:

Print 'balanced' without quotes if pair of parenthesis are balanced else print 'not balanced' in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ |s| ≤ 100


Example:

Input:
3
{([])}
()
()[]

Output:
balanced
balanced
balanced
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

char correspondingChar(char input){
    if( input == '{') return '}';
    else if(input == '(') return ')';
    else if(input == '[') return ']';
}

string random_function(string input){
    stack <char> s;
    //cout << "inside the function\n";
    for(int i = 0;i < input.length();i++){
        char here = input.at(i);
        if(here == '{' or here == '(' or here == '['){
            //cout << "here"; 
            s.push(here);
        }
        else{
            if(s.empty()){
              s.push(here);
              break;
            } 
            char closingbracket = correspondingChar(s.top());
            if(closingbracket == here) s.pop();
            else break;
        }
    }
    string answer;
    if(!s.empty()) answer = "not balanced";
    else answer = "balanced";
    //cout << answer;
    return answer;
}

int main()
 {
    //code
    int t = 0;
    cin >> t;
    loop(j,0,t){
    
        string input;
        cin >> input;
        //cout << input << endl;
        cout << random_function(input) << endl;
    }
    return 0;
}