Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


BRUTE FORCE:   -->O(N^2)
--------------------------------------
 string longestCommonPrefix(vector<string>& strs) {
        string s=strs[0];
       int glob=INT_MAX;
        for(int i=1;i<strs.size();i++){
            int len1=strs[0].length();
            int len=strs[i].length();
            int j=0;
            int loc=0;
            
            while(len-- and len1--){
                if(strs[i][j]==s[j])
                    loc++;
                else
                    break;
                j++;
                
            }
            glob=min(loc,glob);
            
        }
      return s.substr(0,glob);  
    }
};


-------------------------------------------------------
LOGIC://OPTIMAL -->O(nLOGn)

We first sort the array of strings.
Then, we choose the first and last string in the array. [They are supposed to be the most different among all the pairs of strings in the sorted array]
We just compare how many common characters match from index i = 0 of these two strings.


class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));	
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
};