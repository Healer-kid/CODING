
Sort a stack 

Given a stack, the task is to sort it such that the top of the stack has the greatest element.
METHOD -1 (WITHOUT RECURSION AND USING TWO STACKS) O(N) SPACE AND TIME


void SortedStack :: sort()
{
   //Your code here
   stack<int> temp;		//Temp stack will have elements in descending order (i.e) greater element at the bottom 
   
   while(!s.empty()){
       
       int x=s.top();
       s.pop();
       while(!temp.empty() && temp.top()<x)
       {
           s.push(temp.top());
           temp.pop();
           
       }
       
       temp.push(x);
       
   }
   while(!temp.empty())
   {
       s.push(temp.top());
       temp.pop();
       
   }
   return;
   
   
   
}