Implement Queue using LInkedList


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode * temp=new QueueNode(x);
        if(rear==NULL)
        {
            front=temp;
            rear=temp;
            return;
            
        }
        else{
            
            rear->next=temp;
            rear=rear->next;
            
            
            
            
        }
        
        
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code 
       QueueNode * temp;
        if(front==NULL)
        return -1;
        
        int x=0;
        
        x=front->data;
        temp=front;
        front=front->next;
        delete(temp);
        
        
        if(front==NULL)			//Importatnt line,can screw up the code
        rear=NULL;
        
        return x;
        
        
        
        
}
