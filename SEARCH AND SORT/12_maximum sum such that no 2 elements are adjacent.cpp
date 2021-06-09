maximum sum such that no 2 elements are adjacent

Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4


METHOD
USING DP MEMOIZATION
LOGIC:
1.We will take the current element or skip the current element
2.if we take the current element ,then we should take i-2'th element
3.if we skip the current element ,then we should take i-1'th element
4.we should check which is maximum at every instance


CODE:

class Solution
{
    public:
    
   
    int solve(int arr[],int i,int dp[])
   {
       if(i<=-1)
       return 0;
       else{
           if(dp[i]!=-1)
           return dp[i];
           int op1=arr[i]+solve(arr,i-2,dp);		//taking current element
           int op2=solve(arr,i-1,dp);			//skipping current element
           
            return dp[i]=max(op1,op2);
           
       }
       
       
   } 
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return solve(arr,n-1,dp);
        
        
    }
};




