Remove loop in Linked List 

You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
Example 2:

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 



void removeTheLoop(Node *head)
{
    		 //Your code here
     Node *sp=head,*fp=head,*begin=head;
		while(sp && fp && fp->next)
		{
			sp=sp->next;
			fp=fp->next->next;
			if(sp==fp)
			break;
		}
			

				if(sp==fp){ 
				sp=head;
						 //because sometimes no loop ll will be given hence we have to check//
				while(fp->next!=sp->next){
   				 fp=fp->next;
    				 sp=sp->next;
    
    
				}
					fp->next=NULL;

				}

			}