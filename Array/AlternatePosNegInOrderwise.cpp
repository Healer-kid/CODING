Alternate positive and negative numbers 

Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with positive number.
 

Example 1:

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2

METHOD-1
TIME:O(n) SPACE:O(n)

	void rearrange(int arr[], int n) {
	    // code here
	    // code here
	    vector<int> pos;
	    vector<int> neg;
	    int i,j,k;
	    for(i=0;i<n;i++)
	    {
	        if(arr[i] >= 0)
	          pos.push_back(arr[i]);
	        else
	          neg.push_back(arr[i]);
	    }
	    i=0;
	    j=0;
	    k=0;
	    while(i < pos.size() and j < neg.size())
	    {
	        arr[k++]=pos[i++];
	        arr[k++]=neg[j++];
	    }
	    while(j < neg.size())
	    {
	        arr[k++]=neg[j++];
	    }
	    while(i < pos.size())
	    {
	        arr[k++]=pos[i++];
	    }
	
	}
};



METHOD -2
NOTE: RANDOM ARRANGEMENT,BETTER NOT USE THIS APPROACH
LOGIC:
if negative elements should be placed first,then when moving -ve and +ve to one side,keep -ve at the array end ,so that atlast when we swap,it will give the correct output 
-->again for pos elements vice versa
 

void rearrange(int arr[], int n) {
	    // code here
	    int left=0,right=n-1;
	    while(left<=right){
	        
	        if(arr[left]>0 && arr[right]<0)
	        {
	            swap(arr[left++],arr[right--]);
	            
	        }
	        else if(arr[left]<0 && arr[right]>0)
	        {
	            left++;
	            right--;
	        }
	        else if(arr[left]<0){
	            left++;
	            
	        }
	        else{
	            right--;
	        }
	    }
	    if(left==n||left==0)
	    return ;
	    int k=0;
	    while(left<n && k<n)
	    {
	        swap(arr[left],arr[k]);
	        k+=2;
	        left++;
	        
	    }
	    
	    return ;
	    
	}
};



METHOD:3
TIME:O(n) ,SPACE:O(1)
LOGIC:
if there is a negative element at even index,then wrongindex
if there is a positive element at odd index,then wrongindex

if the current index has opposite sign element,then rightrotate from the wrongindex to current element




void rightshift(int arr[],int from,int to){
        
        int temp=arr[to];
        for(int i=to;i>from;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[from]=temp;
        return;
    }



	void rearrange(int arr[], int n) {
	   
	   int wrongIndex=-1;
	   for(int i=0;i<n;i++){
	       if(wrongIndex!=-1)
            {
               if((arr[wrongIndex]<0 && arr[i]>=0 )||(arr[wrongIndex]>=0 && arr[i]<0) ) 
                {rightshift(arr,wrongIndex,i);
                
                if(i-wrongIndex>=2)
                wrongIndex+=2;
                else
                wrongIndex=-1;
                
                }
            }	       
	       else{
	           if((arr[i]<0 && i%2==0)||(arr[i]>=0 && i%2==1))
	            wrongIndex=i;
	           
	       }
	       
	       
	   }
	   
	   
	   return;
	   
	}
};



