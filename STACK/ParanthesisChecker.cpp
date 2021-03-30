Parenthesis Checker 

Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            
            if((x[i]=='{')||(x[i]=='[')||(x[i]=='('))
            s.push(x[i]);
           else if(!s.empty()){
               
             if((s.top()=='{')&&(x[i]=='}'))
             s.pop();
             
            else if((s.top()=='[')&&(x[i]==']'))
            s.pop();
           
            else if((s.top()=='(')&&(x[i]==')'))
             s.pop();
            else
            return false;
           }
            else
            return false;
            
        }
        if(s.empty())
        return true;
        else
        return false;
    }

};