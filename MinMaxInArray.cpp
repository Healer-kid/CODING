Maximum and minimum of an array using minimum number of comparisons
Difficulty Level : Medium


METHOD 1
O(N)
LINEAR SEARCH

struct pair{
int min
int max
}
struct pair getminmax(){
struct pair minmaxi;
if(n==1)
{
	minmaxi.min=a[0];
	minmaxi.max=a[0];
}
else{
	if(a[0]<a[1]){
	minmaxi.min=a[0];
	minmaxi.max=a[1];
	}
	else{
	minmaxi.min=a[1];
	minmaxi.max=a[0];
	}
	
	
}
for(i=2;i<n;i++){
	if(a[i]<minmaxi.min)
	minmaxi.min=a[i];
	if(minmaxi.max<a[i])
	minmaxi.max=a[i];

}
return minmaxi;

}









METHOD 2	//REFER THIS BLOG 
https://afteracademy.com/blog/find-the-minimum-and-maximum-value
TOURNAMENT METHOD(TWO HALF)
	tournament method A method of finding a specific element in some set (e.g. largest of a set of numbers), so called because it involves pairing elements 
	and comparing them to find which one goes through to the next stage, leaving just one element at the end that has not lost.
Recursion

struct pair{
int min
int max
}
struct pair getminmax(int a[],int low,int high){
struct pair minmaxi,mml,mmr;
if(low==high)
{
	minmaxi.min=a[low];
	minmaxi.max=a[low];
	return minmaxi;
}
else if(high==low+1){
	if(a[low]<a[high]){
	minmaxi.min=a[low];
	minmaxi.max=a[high];
	}
	else{
	minmaxi.min=a[low];
	minmaxi.max=a[high];
	}
	return minmaxi;
	
}
int mid=(low+high)/2;
mml=getminmax(a,low,mid);
mmr=getminmax(a,mid+1.high);

if(mml.min<mmr.min)
minmaxi.min=mml.min;
else
minmaxi.min=mmr.min;

if(mmr.max>mml.max)
minmaxi.max=mmr.max;
else
minmaxi.max=mml.max;

return minmaxi

}





