#include <iostream>
#include <vector>
#include <string>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

string palindromicLengthOdd(string input, int center){
    int i = center-1, j = center+1;
    string answer = input.substr(center,1);
    while(i >=0 and j < input.length()){
        if(input.at(i) == input.at(j)){
            answer = input.at(i) + answer + input.at(j);
        }
        else break;
        i--;
        j++;
    }
    return answer;
}

string palindromicLengthEven(string input, int left){
    int i = left, j = left + 1;
    string answer = "";
    while(i >= 0 and j < input.length() ){
        if(input.at(i) == input.at(j)){
            answer = input.at(i) + answer + input.at(j);
        }
        else break;
        i--;
        j++;
    }
    return answer;
}


int random_function(string input){
    
    int n = input.length();
    //For odd sequences
    string maxPalindrome = "";
    for(int i = 0;i < n;i++){
        string ith = palindromicLengthOdd(input,i);
        if(ith.length() > maxPalindrome.length()){
            maxPalindrome = ith;
        }
    }
    
    for(int i = 0;i < n-1;i++){
        string ith = palindromicLengthEven(input,i);
        if(ith.length() > maxPalindrome.length()){
            maxPalindrome = ith;
        }
    }
    
    cout << maxPalindrome << endl;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){
	
	    string input;
	    cin >> input;
	    random_function(input);
	    
	    /* Testing out the functions
	    cout << palindromicLengthOdd("abcdcba",3) << endl;
	    cout << palindromicLengthEven("abccba",2);
	    
	    */
	}
	return 0;
}