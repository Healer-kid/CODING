Reverse a Doubly Linked List 

Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

CODE:



Node* reverseDLL(Node * head)
{
    

		 Node *curr = head, *prev = NULL, *next;
		while(curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			curr->prev = next;
			prev = curr;
			curr = next;
		}
	return prev;

    
}