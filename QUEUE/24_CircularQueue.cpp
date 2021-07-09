WHY WE NEED CIRCULAR QUEUE?
In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.



INSERTION EDGE CASE (cant insert when) //overflow
1)front=0 ,rear=max_size	==>return
2)rear+1==front			==>return 

DELETION
1) front==-1,rear==-1	==> no elements,return
2)front==rear		==> only one element and it is gonna be removed,so make front and rear start from -1 again(empty queue)
3)front==max_size	==> the next cycle begins,so make front as 0
4)normal condn		==> increment front



void push(int ele)

{

	if(front ==0 && rear==size-1)		//	overflow
	return;
	if(rear+1==front)
	return;

	if(front==-1){				//	first time insertion
	rear=front=0;
	arr[rear]=ele

	}
	else if(rear==size-1 && front!=0)	//	next cycle of insertion and there is space in the front	
	{
		rear=0;
		arr[rear]=ele;	
	}
	else{					// neither first nor next cycle(normal insertion)
		arr[++rear]=ele
	}

}

int pop(){

	if(front==-1)			//underflow
	return -1;

	int x=arr[front];
	
	if(front ==rear)		//only one element
	front=rear=-1;

	else if(front==size-1)		//next cycle of deletion begins
	front=0;

	else				//normal
	front++;


return x;





}






