Implement queue using array




The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.



void MyQueue :: push(int x)
{
        // Your Code
        if(rear>=100004)
        return;
        else{
            arr[rear++]=x;
            
        }
        
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        int x=0;
        // Your Code    
        if(rear==front ||front>rear)
        return -1;
        else
        {
            x=arr[front];
            front++;
            
            
            
        }
        
        return x;
        
        
        
        
}
