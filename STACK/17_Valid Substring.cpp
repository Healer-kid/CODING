Valid Substring 
Easy Accuracy: 48.25% Submissions: 18787 Points: 2
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of smallest the valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.



int findMaxLen(string s) {
        // code here
        
        stack<int> stk ;
        stk.push(-1);
        int count = 0 ;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(')
                stk.push(i);
            else{
                stk.pop();
                if(!stk.empty())
                    count = max(count,i-stk.top());
                else
                    stk.push(i);
            }
        }
        return count ;
    }