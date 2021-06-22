Clone a linked list with next and random pointer 

You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1

Example 1:

Input:
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
re 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbit pointer
set, rest two nodes have arbit pointer
as NULL. Second line tells us the value
of four nodes. The third line gives the
information about arbitrary pointers.
The first node arbit pointer is set to
node 2.  The second node arbit pointer
is set to node 4.
Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.


METHOD-1
USING HASHMAP


 LinkedList* clone()
    {
       			 		// Initialize two references,
      				       // one with original list's head.
        Node *origCurr = head;
        Node *cloneCurr = NULL;
  
        				// Hash map which contains node 
      					  // to node mapping of original 
        				// and clone linked list.
        unordered_map<Node*, Node*> mymap;
  
        				// Traverse the original list and
       					 // make a copy of that in the 
       					 // clone linked list.
        while (origCurr != NULL)
        {
            cloneCurr = new Node(origCurr->data);
            mymap[origCurr] = cloneCurr;
            origCurr = origCurr->next;
        }
  
       					 // Adjusting the original list 
        				// reference again.
        origCurr = head;
  
        				// Traversal of original list again
        				// to adjust the next and random 
        				// references of clone list using 
        				// hash map.
        while (origCurr != NULL)
        {
            cloneCurr = mymap[origCurr];
            cloneCurr->next = mymap[origCurr->next];
            cloneCurr->random = mymap[origCurr->random];
            origCurr = origCurr->next;
        }
  
        				// return the head reference of 
        				// the clone list.
        Node *head1= mymap[head];
        return head1;
    }
};



METHOD-2
WITHOUT EXTRA SPACE

LOGIC:
1)inserting a clone linked list to the original linked list (in between and copy only the next nodes )
2)copy the arbitrary nodes 
3)separate the two linked lists 



Node *copyList(Node *head) {
    
	Node* curr = head, *temp; 

				// insert additional node after 
				// every node of original list 
	while (curr) 
	{ 
		temp = curr->next; 

				// Inserting node 
		curr->next = new Node(curr->data); 
		curr->next->next = temp; 
		curr = temp; 
	} 

	curr = head; 

				// adjust the random pointers of the 
				// newly added nodes 
	while (curr) 
	{ 
		if(curr->arb) 
			curr->next->arb = curr->arb->next ; 

				// move to the next newly added node by 
				// skipping an original node 
		curr = curr->next?curr->next->next:curr->next; 
	} 

	Node* original = head, *copy = head->next; 

				// save the start of copied linked list 
	temp = copy; 

				// now separate the original list and copied list 
	while (original && copy) 
	{ 
		original->next = 
		original->next? original->next->next : original->next; 

		copy->next = copy->next?copy->next->next:copy->next; 
		original = original->next; 
		copy = copy->next; 
	} 

	return temp; 


}