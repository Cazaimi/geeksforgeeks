/*Reverse words in a given string
   
Given a String of length N reverse the words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string containing spaces and characters.
 
Output:
For each test case, output a single line containing the reversed String.

Constraints:
1<=T<=20
1<=Lenght of String<=2000


Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

#include <iostream>
#include <string>
#include <stack>


#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(string input){
    stack <char> s;

    string output = " ";
    int count = 0;
	for(int i = input.length()-1;i > -1;i--){
	    s.push(input.at(i));
	    if(input.at(i) == '.' or i == 0){
	        if(!count) s.pop();
	        count++;
	        while(!s.empty()){
	            output+=s.top();//cout << s.top();
	            s.pop();
	        }
	        
	    }
	}
	cout << output << endl;
}


int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    string input;
	    cin >> input;
	    input = "." + input;
	    random_function(input);
	}
	return 0;
}