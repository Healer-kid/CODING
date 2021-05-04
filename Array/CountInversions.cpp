Count Inversions 

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).


METHOD 1:
TIME:O(N^2)

		int count=0;
	    for(int i=0;i<n;i++){
	        
	        for(int j=i+1;j<n;j++){
	            
	            if(a[j]<a[i]){
	                count++;
	            }
	            
	        }
	        
	    }


METHOD 2:
USING MERGE SORT
O(N^2)

IDEA:
partition array into two and each of them should be sorted
--> so if the element in the right array is smaller than the i'th element in the left array
then all the elements after the ith element must be greater,so we can get the count using 
(mid-i),so what mid is? mid is the ending index of left array. 







long long int merge(int arr[],int temp[],int left,int mid,int right){
  long long  int inv_count=0;
    int i=left;
    int j=mid;
    int k=left;
    while((i<=mid-1)&&(j<=right))
    {
        if(arr[i]<=arr[j]){
            
            temp[k++]=arr[i++];
            
        }else{
            
            temp[k++]=arr[j++];
            inv_count=inv_count+(mid-i);
            
        }
        
        
        
        
    }
    
    
    
    while(i<=mid-1){
    temp[k++]=arr[i++];
    
    }
    while(j<=right){
        
        temp[k++]=arr[j++];
    }
    for(int i=left;i<=right;i++){
        
        arr[i]=temp[i];
        
    }
    return inv_count;
    
    
    
    
}




long long int mergesort(int arr[],int temp[],int left,int right ){
  long long int inv_count=0;
    if(left<right){
        
        int mid=(left+right)/2;
      inv_count+=  mergesort(arr,temp,left,mid);
    inv_count+= mergesort(arr,temp,mid+1,right);
        inv_count+= merge(arr,temp,left,mid+1,right);
        
        
        
        
    }
    return inv_count;
    
    
}




long long int countings(int arr[],int n){
    int temp[n];
  return   mergesort(arr,temp,0,n-1 );
    
    
    
}



int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	   cout<< countings(arr,n)<<"\n";
	}
	return 0;
}