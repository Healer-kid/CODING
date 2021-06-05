LINK:https://www.youtube.com/watch?v=bg6r_fgtpMQ

Majority Element 

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

METHOD-1
USING TWO LOOPS
TIME:O(N^2)
SPACE:O(1)


static void findMajority(int arr[], int n)
    {
        int maxCount = 0;
        int index = -1; // sentinels
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j])
                    count++;
            }
 
           			 // update maxCount if count of
           		 	// current element is greater
            if (count > maxCount) {
                maxCount = count;
                index = i;
            }
        }
 
       				 // if maxCount is greater than n/2
       				 // return the corresponding element
        if (maxCount > n / 2)
            System.out.println(arr[index]);
 
        else
            System.out.println("No Majority Element");
    }

METHOD-2
USING HASHMAP
TIME:O(N)
SPACE:O(N)


unordered_map<int,int> mp;
       for(int i=0;i<size;i++){
           
           mp[a[i]]++;
           
       }
       int maxi=size/2;
       int majority=-1;
       for(i:mp){
           if(i.second>maxi)
           {
               majority=i.first;
               break;
           }
           
       }
        return majority;
    }


METHOD-3
USING MOORE VOTING ALGORITHM
TIME:O(N)
SPACE:O(1)

IT WORKS ONLY FOR ARRAY WHICH HAS AN ELEMENT (WHICH IS GREATER THAN N/2 TIMES )

REASON:

since this method cancels elements and which one is left will be returned
eg)

		1 1 1 2 2  --> so the first one and the first two will get cancelled
			   --> the second one and second two will cancel each other
			   --> the third one is left alone


int majorityElement(int a[], int size)
{
        
        int majority=a[0],count=1;
        for(int i=0;i<size;i++)
        {
            if(a[i]==majority)
            {
                count++;
                
                
            }else{
                count--;
                if(count==0)
                {
                    majority=a[i];
                }
                
                
            }
        }
        return majority;
}