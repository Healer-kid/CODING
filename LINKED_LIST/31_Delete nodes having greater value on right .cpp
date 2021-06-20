Delete nodes having greater value on right 

Given a singly linked list, remove all the nodes which have a greater value on its following nodes.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on their next node. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60


LOGIC:

1. Reverse the Linked List.
2. Take an integer MAX and initialise it with the value in head of LL.
3. Traverse the Linked List again and update MAX at each iteration and delete a node if it has a lesser value than MAX by maintaining a PREVIOUS node.
4. Reverse the Linked List again.

Time: O(N)
Space: O(1)


class Solution
{
    public:
    Node* reverse(Node* head){
        
        Node *prev=NULL, *Next=NULL,*cur=head;
        while(cur!=NULL)
        {
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
            
            
        }
        return prev;
        
    }
    
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next)
        return head;
        
        head=reverse(head);
        int maxi=head->data;
        Node*prev=head;
        Node* cur=head;
        head=head->next;
        while(head)
        {
            if(head->data>=maxi)
            {
               maxi=head->data;
               prev=head;
               head=head->next;
                
                
            }else{
                
                prev->next=head->next;
                head=head->next;
                
                
            }
            
            
            
        }
        
    
       head=reverse(cur); 
        
        
      return head;  
        
        
        
    }
    
};