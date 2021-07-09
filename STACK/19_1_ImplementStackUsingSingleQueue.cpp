ALGO
we will dequeue the elements and add them one by one after the newly pushed element 
thereby making it as the front element






queue<int> q
void Stack::push(int val)
{
    


int s=q.size();
q.push(x);
for(int i=0;i<s;i++){
	q.push(q.front());
	q.pop();


}

}
void Stack::pop()
{
    if (q.empty())
        return;
    else
        q.pop();
}