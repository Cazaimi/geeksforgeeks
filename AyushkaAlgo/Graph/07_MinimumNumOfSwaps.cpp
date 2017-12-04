/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

#define loop(i,a,n) for(int i = a;i < n; i++)
/* You are required to complete this method */
int minSwaps(int input[], int n){
    /*Your code here */
    
    int count = 0;
    loop(i,0,n){
        int maxx = 0;
        for(int j = 0;j <= n-i-1; j++){
            if(input[j] > input[maxx]) maxx = j; 
        }
        if(maxx != n-i-1){
            swap(input[maxx],input[n-i-1]);
            count++;
        }
        
        //loop(k,0,n) cout << input[k] << " ";
        //cout << endl;
    }
    
    return count;
}

