Merge two sorted linked lists 

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.

Node* sortedMerge(Node* head1,   Node* head2)
{
	  Node *result,*dummy;
	dummy=new Node(0);
	result=dummy;
//Head Null checker
	if(head1==NULL)
	{
		return head2;
	}
	if(head2==NULL)
	{
		return head1;
	}
//now compare if both are not NULL
	
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data <= head2->data)
		{
			result->next=head1;
			head1=head1->next;
		}
		else
		{
			result->next=head2;
			head2=head2->next;
		}
		result=result->next;
	}
//if anyone got NULL first then
	
	if(head1!=NULL)
	{
		result->next=head1;
	}
	if(head2!=NULL)
	{
		result->next=head2;
	}
		return dummy->next;


}