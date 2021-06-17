Find pairs with given sum in doubly linked list


Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 

Example:  

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)

LOGIC:


-->Initialize two pointer variables to find the candidate elements in the sorted doubly linked list.
		-->Initialize first with the start of the doubly linked list
 		i.e; first=head
 		-->initialize second with the last node of the doubly linked list
 		i.e; second=last_node.

-->We initialize first and second pointers as first and last nodes. Here we don’t have random access, so to find the second pointer,
we traverse the list to initialize the second.

-->If current sum of first and second is less than x, then we move first in forward direction.
 If current sum of first and second element is greater than x, then we move second in backward direction.

-->Loop termination conditions are also different from arrays.
The loop terminates when two pointers cross each other (second->next = first), or they become the same (first == second). 
The case when no pairs are present will be handled by the condition “first==second”

TIME:O(N)
SPACE:O(1)

void pairSum(struct Node *head, int x)
{
   			 // Set two pointers, first to the beginning of DLL
   			 // and second to the end of DLL.
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL)
        second = second->next;
 
   					 // To track if we find a pair or not
    bool found = false;
 
    				 // The loop terminates when two pointers
   				 // cross each other (second->next
   				 // == first), or they become same (first == second)
    while (first != second && second->next != first)
    {
      				  // pair found
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", "
                << second->data << ")" << endl;
 
            				// move first in forward direction
            first = first->next;
 
            				// move second in backward direction
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
 
   					 // if pair is not present
    if (found == false)
        cout << "No pair found";
}