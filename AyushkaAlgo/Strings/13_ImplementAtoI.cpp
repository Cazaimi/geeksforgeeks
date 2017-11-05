/*Implement Atoi (Function Problem)
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string str .

Output:
For each test case in a new line output will be an integer denoting the converted integer, if the input string is not a numerical string then output will be -1.

Constraints:
1<=T<=100
1<=length of (s,x)<=10

Example(To be used only for expected output) :
Input:
2
123
21a

Output:
123
-1
*/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method */
int atoi(string str)
{
     int n = str.length();
     int sum = 0;
     for (int i = n-1; i > -1; i--) {
          char now = str.at(i);
          int place = n-1-i;
         if(now <= 57 and now >= 48){
              sum  = sum + (now-48) * pow(10,place);
         }
         else if(now == 45) ;//do nothing
         else return -1;
     }
     if(str[0] == 45) return sum*-1;
     return sum;
}
