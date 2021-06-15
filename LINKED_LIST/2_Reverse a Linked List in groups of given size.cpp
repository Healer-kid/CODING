Reverse a Linked List in groups of given size. 

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.



struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node*prev=NULL;
    node*Next=NULL;
    node*current=head;
    
        
        int count=0;

        while(count<k && current!=NULL){			//1 2 3 4 5 6 7 8 9
         Next=current->next;
         current->next=prev;
         prev=current;							// 3 2 1 6 5 4 9 8 7
         current=Next;
         count++;   
        }
        
    if(Next!=NULL)
    head->next=reverse(Next,k);
    
        
    return prev;    
        
    
    
    
    
    
    
    
    
    
}