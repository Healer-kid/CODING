Merge Sort for Linked List 

Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.

SHORT AND CLEAN CODE
TIME:O(NLOGN)
LOGIC:
1)find the middle using slow and fast pointer technique
2) start merging them recursively



Node* merge(Node* l1,Node* l2)
{
		if(!l1)
		return l2;
		if(!l2)
		return l1;

	if(l1->data<l2->data)
	{
		l1->next=merge(l1->next,l2);
		return l1;
	}
	else
	{
		l2->next=merge(l1,l2->next);
		return l2;
	}
}
Node* mergeSort(Node* head) {
		// your code here
		if(head==NULL || head->next==NULL)
		return head;

		Node* slow=head;
		Node* fast=head->next;

		while(fast && fast->next)
		{
		slow=slow->next;
		fast=fast->next->next;
		}

		Node* newHead=slow->next;
		slow->next=NULL;

return merge(mergeSort(head),mergeSort(newHead));

}






EXPLAINED DETAILEDLY


void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
   
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
   
    FrontBackSplit(head, &a, &b);
 
   
    MergeSort(&a);
    MergeSort(&b);
 
    
    *headRef = SortedMerge(a, b);
}
 

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 

void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
   
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

















