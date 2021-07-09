Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.


queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<long long int> temp;
   
    for(int i=0;i<k;i++){
        long long val=q.front();
        q.pop();
        temp.push(val);
            }
    queue<ll> nq;
    for(int i=0;i<k;i++){
        long long val=temp.top();
        temp.pop();
        nq.push(val);
        
    }
while(!q.empty()){
    long long int val=q.front();
    q.pop();
    nq.push(val);
    
    
}
    return nq;
}