BY MAKING POP OPERATION COSTLY





/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code  
if(q1.empty())
return -1;
while(q1.size()!=1){
    
    q2.push(q1.front());
    q1.pop();
    
}
int x=q1.front();
q1.pop();
queue<int> q;
q=q1;
q1=q2;
q2=q;
return x;
    
    
}
       



-------------------------------------------------------------------------------------------------
at the end of the push operation(function) ,the queue q1 will always be arranged in order that is ,it will be like a stack



void push(int x)
    {
        
  
        // Push x first in empty q2
        q2.push(x);
  
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
  
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
  
    void pop()
    {
  
        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
       
    } 
        

