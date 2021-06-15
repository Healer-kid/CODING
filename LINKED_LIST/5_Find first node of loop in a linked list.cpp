Find first node of loop in a linked list

Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. If the loop is present then it returns point to the first node of the loop. Else it returns NULL.


METHOD-1
USING HASHMAP


ListNode* detectCycle(ListNode* A)
{
 
    					// declaring map to store node address
    unordered_set<ListNode*> uset;
 
    ListNode *ptr = A;
 
   				 // Default consider that no cycle is present
    while (ptr != NULL) {
 
       				 // checking if address is already present in map
        if (uset.find(ptr) != uset.end())
          return ptr;
 
        			// if address not present then insert into the set
        else
            uset.insert(ptr);
         
        ptr = ptr->next;
    }
    return NULL;
}







METHOD-2
USING TWO POINTERS APPROACH




Node* detectAndRemoveLoop(Node* head)
{
   						 // If list is empty or has only one node
    						// without loop
    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
 
   					 // Move slow and fast 1 and 2 steps
    					// ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    					// Search for loop using slow and
    					// fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    					// If loop does not exist
    if (slow != fast)
        return NULL;
 
    						// If loop exists. Start slow from
    						// head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
}
 