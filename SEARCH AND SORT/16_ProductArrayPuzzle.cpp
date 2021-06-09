

Product array puzzle 

Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Example 2:

Input:
n = 2
nums[] = {12,0}
Output:
0 12


METHOD-1
TIME:O(N^2)
SPACE:O(N)




class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> v;
        long long int mul;
        for(long long int i=0;i<(long long int)nums.size();i++)
        {
            mul=(long long int)1;
            for(long long int j=0;j<(long long int)nums.size();j++)
            {
                if(i==j)
                continue;
                
                mul*=nums[j];
                
            }
            v.push_back(mul);
        }
       return v; 
    }
};




METHOD-2

TIME:O(2N) //2 TRAVERSAL
SPACE:O(N)



LOGIC:

DO TWO TRAVERSALS


		left traversal
		<--------> i
			    <------>	
				right traversal

WHEN YOU DO RIGHT TRAVERSAL,MULTIPLY THE ANSWER STORED IN THAT INDEX AS A RESULT OF LEFT TRAVERSAL
WITH THE RIGHT TRAVERSAL PRODUCT




 vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> v(n,1);
        
        long long left=nums[0],right=nums[n-1];

        for(int i=1;i<(int)nums.size();i++)
        {
            
            v[i]=left;
            left*=nums[i];
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            v[i]*=right;
            right*=nums[i];
            
        }
        
        
       return v; 
    }
};



