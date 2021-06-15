



REVERSE A LINKED LIST

ITERATIVE:

void reverse()
    {
        					// Initialize current, previous and
       			        		// next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            					// Store next
            next = current->next;
            					 // Reverse current node's pointer
            current->next = prev;
 
           					 // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }


RECURSIVE:

ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *node=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
    }