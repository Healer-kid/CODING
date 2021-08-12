Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 


  int findTargetSumWays(vector<int>& nums, int target) {
        
      int sum=0,n=nums.size(),zero=0;
        for(auto num : nums){
            sum+=num;
            if(num==0)
                zero++;
        }
        if((target+sum)%2) return 0;  //if odd ,then no target can be found
        sum = (target + sum) / 2;
        
        int dp[n+1][sum+1];
        
       for(int i=0;i<=n;i++)
           for(int j=0;j<sum+1;j++){
               if(i==0 and j==0)
                   dp[i][j]=1;
               else if(i==0)
                   dp[i][j]=0;
               else if(j==0)
                   dp[i][j]=1;
           }
    
    
    for(int i=1;i<=n;i++){
        
        for(int j=0;j<=sum;j++){
            
            if(nums[i-1]>j or nums[i-1]==0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
        }
        
    }
        
        
    return pow(2,zero)* dp[n][sum];  //zeros should be taken into account//as every zero can be written as +0,-0  
    
    }
    
};