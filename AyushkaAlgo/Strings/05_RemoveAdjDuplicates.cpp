#include <iostream>
#include <vector>

#define loop(i,a,n) for(int i = a;i < n;i++)

using namespace std;

void random_function(string input){
    string answer = input;
    string temp;
    int n = input.length();

    int count = 1;
    while(1){
        count = 0;
        temp = "";
        //n =
        //cout << "answer.length():" << answer.length() << endl;
        for(int i = 0;i < answer.length();i++){
            //cout << answer.at(i);
            if(answer.length() == 1){
              temp+=answer.at(0);
            }
            else{
                  if(i == 0){
                    if(answer.at(i) != answer.at(i+1)){
                        temp+= answer.at(i);
                        //count++;
                    }
                }
                else if(i == answer.length()-1){
                    if(answer.at(i-1) != answer.at(i)) {
                        temp+= answer.at(i);
                        //count++;
                    }
                }
                else{
                    if(answer.at(i) != answer.at(i+1) and answer.at(i) != answer.at(i-1)) {
                        temp+=answer.at(i);
                        //count++;
                    }
                }
            }
        }
        if(temp == answer) break;
        answer = temp;
        //cout << endl << answer << endl;
    }

    cout << answer << endl;
}

int main()
 {
	//code
	int t = 0;
	cin >> t;
	loop(j,0,t){

	    string input;
	    cin >>  input;
	    random_function(input);
	    }

	return 0;
}
