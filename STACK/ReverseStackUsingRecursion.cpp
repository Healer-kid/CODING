Reverse a stack using recursion

Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)





stack<char> st;
  
// intializing a string to store
// result of reversed stack
string ns;
  
// Below is a recursive function 
// that inserts an element
// at the bottom of a stack.
char insert_at_bottom(char x)
{
  
    if(st.size() == 0)
    st.push(x);
  
    else
    {
          
        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if 
        // part is executed and the item is 
        // inserted at the bottom
              
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
  
        // push allthe items held in 
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}
  
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
char reverse()
{
    if(st.size()>0)
    {
          
        // Hold all items in Function 
        // Call Stack until we
        // reach end of the stack 
        char x = st.top();
        st.pop();
        reverse();
          
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom 
        // to top. Every item is
        // inserted at the bottom 
        insert_at_bottom(x);
    }
}