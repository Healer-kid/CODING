Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.


Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0


METHOD-1
USING SET

TIME:O(2N)
SINCE i has to traverse as well as j
SPACE: O(256) ,since the set can contain at max all the 26 alphabets. It won't increase more with the size of data.

LOGIC:




int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        set<char> st;
        int maxsize=0;
        int i=0,j=0;
        while(j<n)
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                maxsize=max(maxsize,(int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return maxsize;
}


METHOD-2
USING HASHMAP

TIME:O(N)
SPACE:O(N)

int lengthOfLongestSubstring(string s) {
      int left = 0, len = 0;
        map<char, int> dict;
        for (int right=0; right<s.size(); right++) {
            if (dict.find(s[right]) != dict.end()) {
                left = max(left, dict[s[right]] + 1);
            }
            dict[s[right]] = right;
            len = max(len, right - left + 1);
        }
        return len;  
                

        
    }


NOTE:
WHY WE NEED TO USE max(left, dict[s[right]] + 1) ?
wont it be suffice if we use dict[s[right]]+1  alone


here is why,it can fail in these test cases

Input:
"abba"
Output:
3
Expected:
2




step1:	r=0,l=0
step2:	r=1,l=0
step3:  r=2,l=2
step4:  r=3,l=1 //we shouldnt go reverse (since the found substring may contain duplicates
,if we do so.eg) bba  ) so it should be max(left, dict[s[right]] + 1)





