Deletion from a Circular Linked List

We have already discussed circular linked list and traversal in a circular linked list in the below articles: 
Introduction to circular linked list 


We will be given a node and our task is to delete that node from the circular linked list.

Examples: 

Input : 2->5->7->8->10->(head node)
        data = 5
Output : 2->7->8->10->(head node)

Input : 2->5->7->8->10->(head node)
         7
Output : 2->5->8->10->2(head node)
Algorithm
Case 1: List is empty. 


If the list is empty we will simply return.
Case 2:List is not empty  

If the list is not empty then we define two pointers curr and prev and initialize the pointer curr with the head node.
Traverse the list using curr to find the node to be deleted and before moving to curr to the next node, every time set prev = curr.
If the node is found, check if it is the only node in the list. If yes, set head = NULL and free(curr).
If the list has more than one node, check if it is the first node of the list. Condition to check this( curr == head). If yes, then move prev until it reaches the last node. After prev reaches the last node, set head = head -> next and prev -> next = head. Delete curr.
If curr is not the first node, we check if it is the last node in the list. Condition to check this is (curr -> next == head).
If curr is the last node. Set prev -> next = head and delete the node curr by free(curr).
If the node to be deleted is neither the first node nor the last node, then set prev -> next = curr -> next and delete curr.

CODE:


void deleteNode(Node** head, int key) 
{
      
    				// If linked list is empty
    if (*head == NULL)
        return;
          
    				// If the list contains only a single node
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
      
    Node *last=*head,*d;
      
   					 // If head is to be deleted
    if((*head)->data==key) 
    {
          
        				// Find the last node of the list
        while(last->next!=*head)
            last=last->next;
              
        			// Point last node to the next of head i.e. 
        			// the second node of the list
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
    }
      
   					 // Either the node to be deleted is not found 
   					 // or the end of list is not reached
    while(last->next!=*head&&last->next->data!=key) 
    {
        last=last->next;
    }
      
    					// If node to be deleted was found
    if(last->next->data==key) 
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
    }