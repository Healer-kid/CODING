


Remove duplicates from an unsorted linked list 

Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.





class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     				// your code goes here
     if(!head || !head->next)
     return head;
     Node*temp=head->next,*prev=head;
     unordered_map<int,int> mp;
     mp[head->data]=1;
     while(temp!=NULL)
     {
         if(mp.find(temp->data)!=mp.end()){
         prev->next=temp->next;
		delete(temp);
	}
         else{
             
             mp[temp->data]++;
             prev=temp;
         }
         temp=temp->next;
     }
     
     return head;
     
     
    }
};