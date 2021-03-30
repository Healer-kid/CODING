//MINIMUM ELEMENT FROM STACK USING O(1) TIME && O(N) SPACE

stack<int> actual;
stack<int> aux;

void push(int x){

actual.push(x);
if(aux.empty())
aux.push(x);
else
{
	if(aux.top()<actual.top())
		aux.push(aux.top());
	else
		aux.push(actual.top());
}


}


int pop(){
if(actual.empty())
return -1;
int x=actual.top();
actual.pop();
aux.pop();
}

int getmin(){
if(aux.empty())
return -1;
int x=aux.top();
return x;
}






