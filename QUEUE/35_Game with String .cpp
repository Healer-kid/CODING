Game with String 
Easy Accuracy: 69.51% Submissions: 4260 Points: 2
Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
 

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22
 

Example 2:

Input: s = aabcbcbcabcc, k = 3
Output: 27
Explaination: We remove two 'c' and one 'b'. 
Now we get the value as 32 + 32 + 32.




 int minValue(string s, int k){
        // code here
        int count[26]={0};
        for(int i=0;i<s.length();i++)
        count[s[i]-'a']++;
        
        priority_queue<int> pq;
        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
            pq.push(count[i]);
        }
        while(!pq.empty() and k--)
        {
            int freq=pq.top();
            pq.pop();
            pq.push(freq-1);
            
            
        }
        int ans=0,res;
        while(!pq.empty())
        {
            res=pq.top();
            pq.pop();
            ans+=pow(res,2);
        }
        
       return ans; 
    }
};
