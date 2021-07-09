Implement stack using array 

Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

/* The method push to push element into the stack */
void MyStack :: push(int x)
{
        // Your Code
      if(top>=1000)					//if opn==push,check overflow
      return;
      else
      arr[++top]=x;
      return;
        
        
}

/*The method pop which return the element 
  poped out of the stack*/
int MyStack :: pop()
{
        // Your Code 
        int x=0;				//if opn==pop,check underflow
        if(top<0)
        return -1;
        else
         x=arr[top--];
        return x;
        
}
