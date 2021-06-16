Intersection of two sorted Linked lists 

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40



CODE:

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    
    Node* temp=NULL,* head=NULL,*newnode=NULL;
    while(head1 && head2)
    {
        if(head1->data == head2->data)
        {
            newnode=new Node(head1->data);
            if(head)
            {
               temp->next=newnode; 
            }
            else{
                head=newnode;
            }
            temp=newnode;
           head1=head1->next;
           head2=head2->next;
        }else if(head1->data<head2->data)
        {
            head1=head1->next;
            
        }else{
            
            head2=head2->next;
        }
        
        
    }
    
    
    
    
    return head;
    
    
    
    