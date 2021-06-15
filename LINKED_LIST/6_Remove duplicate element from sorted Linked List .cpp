Remove duplicate element from sorted Linked List 

Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.
Example 2:

Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list 
2 ->2 ->2 ->2 ->2, 2 is the only element
and is repeated 5 times.




Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node* current=root;
 Node* temp;
 while (current != NULL && current->next != NULL)
{
       if (current->data == current->next->data)
       {
           temp = current->next->next;
           current->next = temp;
       }
       else
       {
          current = current->next;
       }
       
}

return root;
 
 
}