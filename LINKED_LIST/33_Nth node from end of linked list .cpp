Nth node from end of linked list 

Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8.  
Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of nodes in the
linked list, the output is -1.


CODE:
USING TWO TRAVERSAL
USING LENGTH

int getNthFromLast(Node *head, int n)
{
       				// Your code here
       Node*dup=head;
       int count=0;
       int diff;
       while(dup!=NULL){
           
           count++;
           dup=dup->next;
           
       }
       if(count>=n){
           diff=count-n;
           
           while(diff--){
               
               head=head->next;
           }
           return head->data;
           
       }
       else
       return -1;
       
       
       
       }


METHOD-1
WITHOUT FINDING THE LENGTH
TIME:O(N)
ONLY ONE TRAVERSAL

int getNthFromLast(struct Node *head, int n)
{
    
    struct Node *currNode = head , *nthNode = head;
    
   
    while(n!=0)
        {
            if(currNode==NULL)
                return -1;
            currNode = currNode->next;
            n--;
        }
    
    while(currNode!=NULL)   
        {
            nthNode = nthNode->next;
            currNode = currNode->next;
        }
    
    
    if(nthNode!=NULL)
        return nthNode->data;
    else
        return -1;
        
}