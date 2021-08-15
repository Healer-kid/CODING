Palindromic patitioning 
Hard Accuracy: 52.73% Submissions: 24912 Points: 8
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)





class Solution{
public:
int dp[505][505];
    bool ispalindrome(string s,int start,int end)
{
        if(start>end)
        return false;
        if(start==end)
    return true;
    while(start<end){
        if(s[start]!=s[end])
        return false;
        start++;
        end--;
        
    }
    return true;
    
}
int solve(string str,int i,int j){
    
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(ispalindrome(str,i,j))
    return 0;
     dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int left=0,right=0;
        if(dp[i][k]!=-1){
            left=dp[i][k];
        }else{
            left=solve(str,i,k);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
            
        }else{
            dp[k+1][j]=solve(str,k+1,j);
            right=dp[k+1][j];
            
        }
        
        
        dp[i][j]=min(dp[i][j],1+right+left);
        
    }
    
    return dp[i][j];
}



    int palindromicPartition(string str)
    {
        // code here
        
        int i=0;
        int j=str.length()-1;
        memset(dp,-1,sizeof(dp));
        return solve(str,i,j);
        
    }
};








---------------------------------
TABULATION
----------------



{	int t;cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	   /* int n=str.length();
	    bool p[n][n];
	    int c[n][n];
	    for(int i=0;i<n;i++)
	    {
	        p[i][i]=true;
	        c[i][i]=0;
	    }
	    for(int L=2;L<=n;L++){
	        
	        for(int i=0;i<n-L+1;i++){
	            
	            int j=i+L-1;
	            if(L==2)
	            p[i][j]=(str[i]==str[j]);
	            else 
	            p[i][j]=(str[i]==str[j] && p[i+1][j-1]);
	           
	           
	           if(p[i][j])
	           c[i][j]=0;
	           else{
	               c[i][j]=INT_MAX;
	               for(int k=i;k<=j-1;k++){
	                   
	                   c[i][j]=min(c[i][j],c[i][k]+c[k+1][j]+1);
	                   
	               }
	               
	               
	               
	               
	           }
	            
	        }
	        
	    }
	    
	   cout<<c[0][n-1]<<"\n"; 
	}
	
	
	return 0;
}*/