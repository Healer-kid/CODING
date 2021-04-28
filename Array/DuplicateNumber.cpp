 
Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

METHOD -1
using two for loops	O(N^2)

int ans=0;
int flag=0;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
	if(a[i]==a[j] && i!=j)
	{	flag=1;
		ans=a[i];
		break;
	}	
	if(flag)
	break;
}

return ans;




METHOD -2
USING SORT		O(NLogn)
a.sort();
for(int i=0;i<n-1;i++)
{
	if(a[i]==a[i+1])
	return a[i];

}



METHOD-3
USING HASHING		O(N) TIME AND SPACE
int count[n];

for(i=0;i<n;i++)
count[i]=0;

for(int i=0;i<n;i++)
{

if(count[i]==1)
ans=i;
count[a[i]]++;
}

return ans;





METHOD-4
USING TWO POINTER	O(N)


int findDuplicate(vector<int>& nums) {
       int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            
            
        }while(slow!=fast);		//FINDING WHETHER THERE IS A LOOP
        
        fast=nums[0];
        while(slow!=fast){		//FINDING THE DUPLICATE NUMBER
            
            slow=nums[slow];
            fast=nums[fast];
            
            
        }
        
        return fast;
    }



