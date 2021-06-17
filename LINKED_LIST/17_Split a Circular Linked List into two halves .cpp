Split a Circular Linked List into two halves 

Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

 

Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
 

Example 2:

Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

CODE:

NOTE:

USE (FAST!=head OR FAST->Next!=head)  orelse  (FAST->next!=head OR FAST->Next->Next!=head)

LOGIC:
1.find the middle element using two pointer technique,the slow pointer will be pointing to the middle element
2.now make the next of slow as the second ll header
3.now make the next of slow point to the head (first circular ll created)
4.now traverse the second half and make the next of last points to the second header.




void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here

    
     Node *slow = head, *fast = head;
    
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *head1_ref = head;
    *head2_ref = slow->next;
    
    Node *temp = slow->next;
    
    slow->next = head;
    
    Node *curr = *head2_ref;
    
    while(curr->next != head)
    {
        curr=curr->next;
    }
    
    curr->next = *head2_ref;
 
    
    
    
    
    
    
}