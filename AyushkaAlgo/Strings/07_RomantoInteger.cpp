#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

int getInt(char a){
  if(a == 'I') return 1;
  else if(a == 'V') return 5;
  else if(a == 'X') return 10;
  else if(a == 'L') return 50;
  else if(a == 'C') return 100;
  else if(a == 'D') return 500;
  else if(a == 'M') return 1000;
  else return -1;

}

void random_function(string input){
  int n = input.length();
  int sum = 0, prev = 4000;
  loop(i,0,n){

    if(i == n){
        sum += getInt(input.at(i));
    }
    else{
        if(getInt(input[i]) >= getInt(input[i+1])){
            sum += getInt(input[i]);
        }
        else {
            sum = sum + getInt(input[i+1]) - getInt(input[i]);
            i+=1;
        }
    }
    //cout << i << " " << input[i]  << " " << sum <<endl;
  }

  cout << sum << endl;
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
  }
	return 0;
}
