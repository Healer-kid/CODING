Add two numbers represented by linked lists 

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).

LOGIC:
1.REVERSE BOTH THE LINKED LIST
2.ADD BOTH
3.REVERSE THE RESULTANT LINKED LIST



Node* reverse(Node* head){					//REVERSE
        
        Node*prev=NULL,*curr=head,*Next=NULL;
        while(curr!=NULL)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
            
            
            
        }
        return prev;
    }
    




Node* addTwoLists(Node* first, Node* second) {
    // Code here

	first=reverse(first);		//reverse both
	second=reverse(second);



    int sum=0,carry=0;
    Node*start=NULL,*temp,*end=NULL;
    while(first || second){
        sum=carry+(first?first->data:0)+(second?second->data:0);
        carry=sum>=10?1:0;
        sum=sum%10;
        Node*temp=new Node(sum);
        if(start==NULL){
        start=temp; 
        end=start;
        }
        else{
        end->next=temp;
        end=end->next;
        }
        if(first)
        first=first->next;
        if(second)
        second=second->next;
        
        
        
        
        
        
        
    }
    if(carry>0){
        end->next=new Node(carry);
    }
    
  


	start=reverse(start);	//reverse
  return start;
    
}