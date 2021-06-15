Detect Loop in linked list 

Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
x = 2
Output: True
Explanation: In above test case N = 3.
The linked list with nodes N = 3 is
given. Then value of x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.
Example 2:

Input:
N = 4
value[] = {1,8,3,4}
x = 0
Output: False
Explanation: For N = 4 ,x = 0 means
then lastNode->next = NULL, then
the Linked list does not contains
any loop.

METHOD-1
USING HASHMAP
TIME:O(N)
SPACE:O(N)


bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
       				 			// If this node is already present
        						// in hashmap it means there is a cycle
       							 // (Because you we encountering the
        						// node for the second time).
        if (s.find(h) != s.end())
            return true;
 
        					// If we are seeing the node for
        					// the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}
 
METHOD-2
USING TWO POINTERS APPROACH (Floyd’s Cycle-Finding Algorithm )
TIME:O(N)
SPACE:O(1)

int detectloop(Node *head) {

   		 // your code here
    Node*fastp,*slowp;
    fastp=head;
    slowp=head;
    if(head==NULL)
    return 0;

	
    while(fastp && fastp->next){					while(fastp!=NULL) // while(fastp)

        fastp=fastp->next->next;
        slowp=slowp->next;
        if(fastp==slowp)
        return 1;
    }
    
    return 0;
    
}