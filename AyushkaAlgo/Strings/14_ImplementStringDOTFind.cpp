/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function should return position where the target string
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     int found = -1, n = s.length(), m = x.length();
     for (int i = 0; i < n - m; i++) {
          /* code */
          int j = 0;
          while(j < m-1 and j < n-1 and s.at(i+j) == s.at(j)){
               if(j == m-1){
                    return i;
               }
               j++;
          }
     }
     return -1;
}
