
Second most repeated string in a sequence 
Easy Accuracy: 54.16% Submissions: 6162 Points: 2
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

LOGIC:
1.use a hashmap to store the string and the frequency
2.find the string with second maximum occurence 








 string secFrequent (string arr[], int n)
    {
        //code here.
        
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            
        }
        int firstmax=INT_MIN,secondmax=INT_MIN;
        for(auto i:mp)
        {
            if(i.second>firstmax)
            {
                secondmax=firstmax;
                firstmax=i.second;
                
            }else if(i.second> secondmax  && i.second!=firstmax)
                secondmax=i.second;
            
            
        }
        string ans="";
        for( auto i:mp)
        {
            if(i.second==secondmax){
            ans=i.first;
            break;
            }
        }
        
        
      return ans;  
        
        