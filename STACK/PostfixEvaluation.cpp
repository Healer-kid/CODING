Evaluation of Postfix Expression 

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.


int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<S.length();i++)
        {
            if(isdigit(S[i]))
            st.push(S[i]-'0');
            else if(S[i]=='+' || S[i]=='-'||S[i]=='*' || S[i]=='%'||S[i]=='/')
            {   int ans=0;
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(S[i]=='+')
                {
                    ans=num1+num2;
                    st.push(ans);
                }
                else if(S[i]=='-')
                {
                    ans=num1-num2;
                    st.push(ans);
                }
                
                else if(S[i]=='*')
                {
                    ans=num1*num2;
                    st.push(ans);
                }
                else if(S[i]=='/')
                {
                    ans=num1/num2;
                    st.push(ans);
                }
                else  if(S[i]=='%')
                {
                    ans=num1%num2;
                    st.push(ans);
                }
                
                
                
                
                
                
            }
        }
       int temp=st.top();
       return temp;
        
    }
};