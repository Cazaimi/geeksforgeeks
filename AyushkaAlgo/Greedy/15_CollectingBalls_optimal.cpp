/* GFG's solution: #include
int main()
{
    //    freopen("1.txt","r",stdin);
    //    freopen("2.txt","w",stdout);
    int t,i,j,n,m;
    scanf("%d",&t);
    
    while(t--)
    {
      scanf("%d%d",&n,&m);
      int a[n],b[m];
      for(i=0;i       scanf("%d",&a[i]);
      
      for(i=0;i       scanf("%d",&b[i]);
      
      long long ans=0,sum1=0,sum2=0;
      
      for(i=0,j=0;i       {
          
          
          if(a[i]<b[j]){
              sum1+=a[i];
              i++;
        }
        else if(a[i]>b[j])
          {
              sum2+=b[j];
              j++;
        }
        else
        {
            sum1+=a[i];
            sum2+=b[j];
            i++;
            j++;
            
            if(sum1>sum2)
             ans+=sum1;
           else
             ans+=sum2;
             
             sum1=sum2=0;
        }
          
      }
      
      for(j;j       sum2+=b[j];
      
      for(i;i       sum1+=a[i];
      
      if(sum1>sum2)
             ans+=sum1;
           else
             ans+=sum2;
             
       printf("%lld\n",ans);         
      
    }
}
*/
/* Question statement at the bottom 
My Solution: O(n) - incomplete*/

#include <iostream>
#include <vector>
using namespace std;
int f(vector <int> a, vector <int> b, int n, int m){
	
	int i = 0, j = 0, cummI = 0, cummJ = 0, ps = 0;
	
	//cout << "i" << "\t" << "j" << "\t" << "cummI" << "\t" << "cummJ" << "\t" << "ps" << endl;
	while(i < n and j < m){
		bool truth = i < n?1:0;
		//cout << "i < n? " << truth << endl;
		//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
		if(a[i] == b[j]){
			cummI += a[i], cummJ += b[j];
			//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
			ps += max(cummI,cummJ);
			cummI = 0, cummJ = 0;
			i++; j++;
			//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
		}
		else {
			if(a[i] > b[j]){
				while(b[j] < a[i] and i < n and j < m){
					//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
					cummJ += b[j];
					j++;
					//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
				}
			}
			else {
				while(a[i] < b[j] and i < n and j < m){
					//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
					cummI += a[i];
					i++;
					//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
				}
			}
		}
	}
	//cout << i << "\t" << j << "\t" << cummI << "\t" << cummJ << "\t" << ps << endl;
	if(i != n) cummI += a[n-1];
	if(j != m) cummJ += b[m-1];
	ps += max(cummI,cummJ);
	return ps;
}
int main()
 {
	//code
	int t = 0;
	cin >> t;
	for(int j=0;j < t; j++){
	
	    int n = 0,m = 0;
	    cin >> n >> m;
	    vector <int> a(n);
	    vector <int> b(m);
	    for(int i=0;i < n; i++) cin >> a.at(i);
	  	for(int i=0;i < m; i++) cin >> b.at(i);
	  	cout << f(a,b,n,m) << endl;
	}
	return 0;
}

/*	
Geek collects the balls
   
 

There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. The buckets n both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the road which has the bucket with lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of road).
The geek can change the road only at the point of intersection(which means , buckets with the same number of balls on two roads). Now you need to help Geek to collect the maximum number of balls.

Input:
First line of input contains T denoting number of test cases. First line of each test case contains two integers N and M, denoting the number of buckets on road1 and road2 respectively. 2nd line of each test case contains N integers, number of balls in buckets on first road. 3rd line of each test case contains M integers, number of balls in buckets on second road.

Output:
For each test case output a single line containing the maximum possible balls that Geek can collect.

Constraints:
1<= T <= 1000
1<= N <= 103
1<= M <=103
0<= Ai,Bi <=109

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29

Explanation:

The path with maximum sum is (2,3,4)[5,6](9). Integers in [] are the buckets of first road and in () are the buckets of second road. So, max balls geek can collect is 29.*/

