LINK:https://www.youtube.com/watch?v=lhhqbGH7Pao
Longest Prefix Suffix 

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix

METHOD:
USING KMP STRING MATCHING ALGORITHM
HERE WE USE THE PATTERN ARRAY WHICH WE USE IN THE KMP TO SOLVE THIS PROBLEM

class Solution{
public:		

		int lps(string s) {
	    
	    int n=s.length();
	    vector<int> lps(n,0);
	    
	    for(int i=1;i<n;i++){

	        int j=lps[i-1];
	        
	        while(j>0 and s[i]!=s[j])
	        j=lps[j-1];
	        
	        
	        if(s[i]==s[j])
	        {
	            j++;
	            lps[i]=j;
	        }
	        
	    }
	   return lps[n-1]; 
	}
};
		return v[n-1]; //dont need to find for maximium value in the array
 //here the value stored in dp[i] is the maximum length of a proper prefix that is also a proper suffix of string 0 to i.
 So we need to find for the whole string that's why we are returning the last value i.e. lps[n - 1] for string 0 to n - 1;
	    
	     
	    












Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
gigummcnu

Its Correct output is:
0

And Your Code's output is:
1


EXPLANATION
Yes, it's 0. Pay attention to the question. It asked for the length of the longest "proper" prefix which is also a "proper" suffix.
 In your input 'gigummcnu', I believe you've taken g and g as common and think the output should be 1. That is incorrect. 
Since the initial 'g' is a proper prefix but the g in the middle is not a proper suffix.

Suffix starts at the 0-th index and the prefix ends at the last index. For this string, if your code is giving 1 as the output, 
it is basically consider "g" equal to "u" and that's clearly wrong.