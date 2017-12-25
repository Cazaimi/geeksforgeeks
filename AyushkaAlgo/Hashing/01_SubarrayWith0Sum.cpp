/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this function*/
int maxLen(int A[],int n)
{
	map <int,int> hash;
	int sum = 0,max_len = 0;
	hash.insert(make_pair(0,-1));
	for(int i = 0;i < n; i++){
		sum += A[i];
		map <int,int> :: iterator itr = hash.find(sum);
		if(itr != hash.end()){
		  max_len = max(max_len,i-itr->second);
		}
		else hash.insert(make_pair(sum,i));
	}
	return max_len;
}
