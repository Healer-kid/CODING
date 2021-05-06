Maximum Product Subarray 

Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is  6, -3, -10 which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is 2, 3, 4, 5 which gives product as 120.


METHOD-1
NAIVE APPROACH

int result = arr[0];
 
    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        // traversing in current subarray
        for (int j = i + 1; j < n; j++)
        {
            // updating result every time
            // to keep an eye over the maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        // updating the result for (n-1)th index.
        result = max(result, mul);
    }
    return result;



METHOD-2
TIME:O(N)

LOGIC
-->Three cases (pos,neg,zero)
-->at each index,find max and min ,
-->locmax always be positive,locmin always be negative
-->if zero,then reset locmax and locmin to one,so that we can start finding new subarrays
-->if num==pos
	locmax=locmax*num;
	locmin=min(locmin*num,1) //eg) locmin=-3,now locmin=-3*10=-30
	
-->if num==0
	reset both
-->if num==neg
	temp=locmax     //pos
	locmax=max(locmin*num,1) //why we need 1? eg) [-8,5,3,1,6] if we dont use 1,then locmax=-ve,locmax should never be negative at any point.
	locmin=temp*num  //pos *neg = neg



CODE:

 long long locmax=1,locmin=1,globmax=INT_MIN;
	   
	    long long temp;
	    int flag=1;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>0){
	            locmax=locmax*arr[i];
	            locmin=min(locmin*arr[i],(long long )1);
	            flag=1;
	            
	        }else if(arr[i]==0){
	            
	            locmax=1;
	            locmin=1;
	            
	        }else{
	            
	            temp=locmax;
	            locmax=max(locmin*arr[i],(long long )1);
	            locmin=temp*arr[i];
	            
	            
	        }
	        
	        globmax=max(globmax,locmax);
	        
	        
	    }
	    if(flag==0 && globmax==INT_MIN)
	    return 0;
	    return globmax;
	    
	    
	}




METHOD-3
USING TWO TRAVERSAL
TIME:O(N)



maximum product is maximum of following two:

Maximum product in left to right traversal.
Maximum product in right to left traversal
For example, consider the above third sample input {-1, -2, -3, 4}. If we traverse the array only in forward direction (considering -1 as part of output), maximum product will be 2. If we traverse the array in backward direction (considering 4 as part of output), maximum product will be 24 i.e; { -2, -3, 4}.


CODE:

frwdmax=INT_MIN:
backmax=INT_MIN;
int locmax=1,istrue=0;
for(int i=0;i<n;i++)
{
	locmax=locmax*a[i];
	if(locmax==0)
	{
		istrue=1;
		locmax=1;//reset
		continue;
	}
	frwdmax=max(frwdmax,locmax);

}
locmax=1;
for(int i=n-1;i>=0;i--)
{
	locmax=locmax*a[i];
	if(locmax==0)
	{
		istrue=1;
		locmax=1;//reset
		continue;
	}
	backmax=max(backmax,locmax);

}

int res=max(frwdmax,backmax);
return res;





METHOD-4
USING SWAPPING

LOGIC:
 When multiplied by -ve number, maxVal becomes minVal and minVal becomes maxVal.


int minVal = arr[0];
    int maxVal = arr[0];
  
    int maxProduct = arr[0];
  
    for (int i = 1; i < n; i++) {
  
        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);
  
        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);
  
        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }
  
    // Return maximum product found in array.
    return maxProduct;




