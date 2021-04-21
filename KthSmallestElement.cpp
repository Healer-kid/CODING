Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct.



METHOD 1
SORTING
O(N)

#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;
	    cin>>k;
	    sort(a,a+n);
	    int ans=a[k-1];
	    cout<<ans<<"\n";
	    
	    
	}
	
	
	return 0;
}






MEHTOD 2
using priority queue
O(Nlogk)

#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;
	    cin>>k;
	    priority_queue<int,vector<int>,greater<int>> pq;
	    for(int i=0;i<n;i++){
	        pq.push(a[i]);
	        
	    }
	    int ans;
	    while(k!=0){
	        ans=pq.top();
	        pq.pop();
	        k--;
	        
	    }
	    cout<<ans<<"\n";
	    
	    
	}
	
	
	return 0;
}
