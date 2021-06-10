Bishu and Soldiers

LINK:https://www.youtube.com/watch?v=hT1sOIcenBA

Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.

The second line contains an array of N numbers denoting the power of each soldier

This third line contains Q, which denotes the number of rounds.

Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:

For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.

CONSTRAINTS:

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100

Sample Input
7
1 2 3 4 5 6 7
3
3
10
2
Sample Output
3 6
7 28
2 3

QUESTION INSHORT

you need to find the no of soldiers who have power less than bishu in each round 
as well as calculate the power he will get if he kills them in that particular round


LOGIC:
-->sort the array
-->maintain a previous sum array which starts from 1'th index ,which will have the total powers ,he will get if he killed that many ppl
-->use upper bound to find the no of soldiers he can kill (who are less than his power)

eg) if the number to be found is 3 in an array of (1,2 ,3,4,5)
	it will return 3 (no of elements less than or equal to 3)






#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];


sort(a,a+n); 

int presum[n];
presum[0]=0;
for(int i=1;i<=n;i++)
{
presum[i]=a[i-1]+presum[i-1];

}
	int q;
	cin>>q;
	while(q){
		int x;
		cin>>x;
		int idx=upper_bound(a,a+n,x)-a;
		cout<<idx<<" "<<presum[idx]<<"\n";
		q--;

	}




	return 0;
}