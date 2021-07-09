Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:

Input:
6
4 3 1 10 2 6

Output: 
6 2 10 1 3 4

Explanation: 
After reversing the given
elements of the queue , the resultant
queue will be 6 2 10 1 3 4.


METHOD-1
USING RECURSION:

void helper(queue<int> &q){
    
   if(q.empty()) 
    return;
    else{
        int data=q.front();
        q.pop();
        helper(q);
        q.push(data);
       
        
    }    
    return ;
    
}
queue<int> rev(queue<int> q)
{
    // add code here.
   
    
    helper(q);
    return q;
}






METHOD-2
USING STACK

void reverseQueue(queue<int>& Queue)
{
    stack<int> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}
