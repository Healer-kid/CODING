Following is implementation of push(), pop() and findMiddle() operations. If there are even elements in stack, findMiddle() returns the second middle element. For example, if stack contains {1, 2, 3, 4}, then findMiddle() would return 3. 
ALGO
1)check if it is even when push
2)check if it is odd when pop



class ll{

int data;
ll* prev;
ll* next;

}

class stack{

int count=0;
stack * top;
stack * mid ;

}

push(x){

stack * st;
ll *temp = new ll();
temp->data=x;
temp->prev=NULL;
temp->next=st->top;

st->count+=1;
							//MIDDLE ELEMENT FINDING 			
if(st->count==1)
{
	st->mid=temp;
}
else{
	st->top->prev=temp  				//line(1)

	if(!(st->count&1))
	st->mid=st->mid->prev;
		
}

st->top =temp;						//line(2)//observe closely line 1 and 2 has connection


}



int pop(){

if(st->count==0)
return -1						//check for underflow always


ll * temp;
temp=st->top;
int x=temp->data;
st->top=temp->next;

st->top->prev=NULL				//change the prev to null once the node is ready to delete

st->count--;

if(count&1)
st->mid=st->mid->next;

free(temp)
return x;


}

int findmid(){
if(count==0)
return -1;
return st->mid->data

}
