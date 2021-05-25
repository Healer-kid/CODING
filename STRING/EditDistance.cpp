Edit Distance 

Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.


TIME:O(N^2)
LOGIC:


1.if both strings are empty,then zero operations
2.if str1 is zero ,then str2.length() number of the operations
3.if str2 is zero ,then str1.length() number of the operations


REFER NOTE
REFER:https://www.youtube.com/watch?v=We3YDTzNXEk&t=204s


 
int minimum(int x,int y,int z){
return min(min(x,y),z);
}
int editDistance(string s, string t)
{
int m = s.length();
int n = t.length();
int dp[m+1][n+1];
int i,j;
for(i=0;i<=m;i++){
for(j=0;j<=n;j++){
if(i == 0)
dp[i][j] = j;
else if(j == 0)
dp[i][j] = i;
else if(s[i-1] == t[j-1])
dp[i][j] = dp[i-1][j-1];
else{
int k = minimum(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
dp[i][j] = 1+k;
}
}
}
return dp[m][n];
}
};