Reverse a string using Stack 

You are given a string S, the task is to reverse the string using stack.

//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> st;
    
    for(int i=0;i<len;i++)
    {
        st.push(S[i]);
    }
    int i=0;
    while(!st.empty()){
    S[i]=st.top();
    st.pop();
    i++;
    }
    return S;
}