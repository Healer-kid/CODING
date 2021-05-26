 
Count the Reversals 

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.

TIME:O(N)
SPACE:O(N)

LOGIC:
we will try to remove the already matched brackets ,then the mismatched brackets must be 
equal to  ceil(opening/2) + ceil (closing/2)
how?
eg)

}} {{{{ 		-->in this case, 2/2 + 4/2 =3

}}} {{{{{	        -->in this case, ceil(3/2) +ceil(5/2) =2+3=5

so if its odd no of brackets,then we need to use ceil separately for opening as well as closing brackets

1) if the string is of odd length,then we can never balance,so return -1
2) if even,then maintain two counters ,say close,open
	 if its a opening bracket,add it to the stack and increment open
	 if its a closing bracket and the top is opening bracket,then decrement open(poping the matched brackets from the stack)

	else increment close


3) if the open and close are even,then divide by 2 
   if the open and close are odd,then (divide by 2 )+1  //which is equal to ceiling







int ans=0;
    stack<char> st;
    int op=0,cl=0;
    int len=s.length();
    if(len%2==0)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='{')
            {
                st.push('{');
                op++;
            }
            else if(s[i]=='}' && !st.empty() && st.top()=='{')
            {
                st.pop();
                op--;
            }
           else
            cl++;
            
            
        }
        if(cl&1)
        cl=(cl/2)+1;
        else
        cl=cl/2;
        
        
        
        if(op&1)
        op=(op/2)+1;
        else
        op=op/2;
        
        
        ans=cl+op;
    }
    else{
        return -1;
    }
    
    
    return ans;
    
    
}