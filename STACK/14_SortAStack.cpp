link:https://www.youtube.com/watch?v=K0XXVSL4wUo

Sort a stack 

Given a stack, the task is to sort it such that the top of the stack has the greatest element.
METHOD -1 (WITHOUT RECURSION AND USING TWO STACKS) O(N) SPACE AND TIME


stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;
  
    while (!input.empty())
    {
        					// pop out the first element
        int tmp = input.top();
        input.pop();
  
       								 // while temporary stack is not empty and top
        							// of stack is greater than temp
        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
           								 // pop from temporary stack and push
          								 // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }
  
        								// push temp in tempory of stack
        tmpStack.push(tmp);
    }
  
    return tmpStack;
}