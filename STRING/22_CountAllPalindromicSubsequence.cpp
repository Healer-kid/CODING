
LINK:https://www.youtube.com/watch?v=vlbA8oUxSV0&t=630s
Count All Palindromic Subsequence in a given String

Find how many palindromic subsequences (need not necessarily be distinct) can be formed in a given string. Note that the empty string is not considered as a palindrome. 
Examples: 

Input : str = "abcd"
Output : 4
Explanation :- palindromic  subsequence are : "a" ,"b", "c" ,"d" 

Input : str = "aab"
Output : 4
Explanation :- palindromic subsequence are :"a", "a", "b", "aa"

Input : str = "aaaa"
Output : 15

TIME:O(N^2) USING MEMOIZATION
LOGIC:
1.use two pointers,one pointing the first char and the second the last char
2.if they both are eqaul,then we got one palindrome right ,so the expression should be

count(i,j-1) +count(i+1,j)+1 //the one here refers the palindrome that we got and 
			     //check for the remaining palindromes leaving those two

3.if they both are not equal,then search for the remaining

count(i,j-1) + count(i+1,j) -count(i+1,j-1) //removing the common elements that will account to duplicates

CODE:


int countss(string &str,int i,int j,vector<vector<int>>&dp){
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];

    if(i==j){
     dp[i][j]=1;
     return dp[i][j];
    }
    
    if(str[i]==str[j]){
      dp[i][j]=countss(str,i+1,j,dp)+countss(str,i,j-1,dp)+1;  
     return dp[i][j];   
    }
    
    else{
    dp[i][j]=countss(str,i+1,j,dp)+countss(str,i,j-1,dp)-countss(str,i+1,j-1,dp);
    return dp[i][j];
    }
}