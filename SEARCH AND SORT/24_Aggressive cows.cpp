LINK:https://www.youtube.com/watch?v=wSOfYesTBRk

AGGRCOW - Aggressive cows
#binary-search
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.


QUESTION IN SHORT:

-->you have to place the cows everytime you will find the difference bw them ,store the minimum difference at each time when you arrange
-->Now find the largest of the minimum differences found so far

LOGIC:

REFER NOTE,USE BINARY SEARCH

#include<bits/stdc++.h>
using namespace std;

bool CanPlaceCows(int a[],int cows,int n,int dist){
	
	int count=1;
	int lastplacedcow=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-lastplacedcow>=dist)
		{
			count++;
			lastplacedcow=a[i];
		}
	
		
	}
		if(count>=cows)
		return true;
	return false;
	
	
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n,cows;
	cin>>n>>cows;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	
	int low=1,high=a[n-1]-a[0];
	
	while(low<=high)
	{
		int mid=(low+high)>>1;        //similar to dividing it by 2
		if(CanPlaceCows(a,cows,n,mid))
		{
		
			low=mid+1;
		}else
		high=mid-1;
		
		
	}
cout<< high <<"\n";	
}	
	return 0;
}