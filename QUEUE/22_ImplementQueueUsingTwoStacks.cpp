Implement Queue using two stacks


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    // Your Code
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
        
        
    }
    
    s1.push(x);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
        
    }
    
    return;
    
    
int StackQueue :: pop()
{
        // Your Code   
        if(s1.empty())
        return -1;
        int x=s1.top();
        s1.pop();
        return x;
        
        
        
}



METHOD 2||COSTLY POP OPERATION 


/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code  
        if(s1.empty())
        return -1;
        
        while(s1.size()!=1){
            
          s2.push(s1.top());
          s1.pop();
            
            
        }
     int x=s1.top();
     s1.pop();
     while(!s2.empty()){
         
         s1.push(s2.top());
         s2.pop();
         
     }
     return x;   
}

