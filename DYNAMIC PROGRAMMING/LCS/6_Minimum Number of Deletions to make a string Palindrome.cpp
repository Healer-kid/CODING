
Minimum Deletions 
Easy Accuracy: 78.85% Submissions: 4524 Points: 2
Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: S = "aebcbda"
Output: 2
Explanation: Remove characters 'e' 
and 'd'.
Example 2:

Input: S = "geeksforgeeks"
Output: 8
Explanation: One of the possible result
string can be "eefee", so answer is 
13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.



----------------------------
class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        string S2=S;
        reverse(S2.begin(),S2.end());
         int m=S.length();					-------->MIN NO.OF INSERTION==MIN NO. OF DELETION-----------------<
	    int n=S2.length();
	    int dp[m+1][n+1];
	    for(int i=0;i<m+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 or j==0)
	            dp[i][j]=0;
	            else if(S[i-1]==S2[j-1])
	            dp[i][j]=dp[i-1][j-1]+1;
	            else
	            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            
	            
	            
	        }
	        
	        
	    }
	    
	    
        return m-dp[m][n];
    } 
};