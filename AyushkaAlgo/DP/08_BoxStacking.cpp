/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

#include<bits/stdc++.h>

using namespace std;

#define loop(i,a,n) for(int i = a;i < n; i++)

int compare(pair <int,pair<int,int> > a, pair <int,pair<int,int> > b){
	
	return a.first * a.second.first <= b.first * b.second.first ? 0:1;
}

vector <pair <int,pair <int,int> > > boxMaker(int height[],int width[],int length[],int n){
	//length -> breadth -> height
	vector < pair <int,pair<int,int> > > allBoxes; 
	loop(i,0,n){
		int h,l,b;
		h = height[i], l=length[i], b=width[i];
		//h,l,b|b,h,l|l,b,h
		allBoxes.push_back( make_pair( min(h,l),make_pair(max(h,l),b) ) );
		allBoxes.push_back( make_pair( min(b,h),make_pair(max(b,h),l) ) );
		allBoxes.push_back( make_pair( min(l,b),make_pair(max(l,b),h) ) );
	}
	
	/*loop(i,0,allBoxes.size()){
		cout << allBoxes.at(i).first << " " << allBoxes.at(i).second.first << " " << allBoxes.at(i).second.second;
		cout << endl; 
	}*/
	
	sort(allBoxes.begin(),allBoxes.end(),compare);
	
	/*loop(i,0,allBoxes.size()){
		cout << allBoxes.at(i).first << " " << allBoxes.at(i).second.first << " " << allBoxes.at(i).second.second;
		cout << endl; 
	}*/
	
	return allBoxes;
}

int maxHeight(int height[],int width[],int length[],int n)
{
	//Your code here
	vector < pair <int,pair<int,int> > > allBoxes = boxMaker(height,width,length,n);
	n = allBoxes.size();
	vector <int> heightStorer(n);
	
	loop(i,0,n) heightStorer.at(i) = allBoxes.at(i).second.second;
	
	int heightMax = 0;
	loop(i,0,n){
		int ib=allBoxes.at(i).first,il=allBoxes.at(i).second.first;
		loop(j,i+1,n){
			if( allBoxes.at(j).first < ib and allBoxes.at(j).second.first < il ){
				if(heightStorer.at(i)+allBoxes.at(j).second.second >= heightStorer.at(j)){
					heightStorer.at(j) = heightStorer.at(i) + allBoxes.at(j).second.second;
				}
			}
			heightMax = max(heightMax,heightStorer.at(j));
		}
	}
	
//	loop(i,0,n) cout << heightStorer.at(i) << " ";
//	cout << "\nMaximum height is: ";
	return heightMax;
}


int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout << maxHeight(A,B,C,n) << endl;
}
 
} 
