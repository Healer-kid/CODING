
Check if Linked List is Palindrome 
Easy Accuracy: 39.25% Submissions: 100k+ Points: 2
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.



METHOD-1
USING EXTRA SPACE
TIME:O(N)
USING STACK

bool isPalindrome(Node *head)
{
   		 //Your code here
    int count=1;
    stack<int> s;
    Node* temp;
    temp=head;
    while(temp->next!=NULL){
    s.push(temp->data);
    temp=temp->next;
    count++;
    }
    s.push(temp->data);
    
    for(int i=0;i<count/2;i++){
        int x=s.top();
        s.pop();
        if(head->data==x){
        head=head->next;
         
        }
        else
        return 0;
    }
    
    return 1;
    
}










METHOD-2
USING REVERSE



Node* reverse(Node* slow)
   {
       Node* curr=slow;
       Node* next;
       Node* prev=NULL;
       while(curr!=NULL)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           
       }
       return prev;
   }
bool isPalindrome(Node *head)
{
    Node* slow=head;
          Node*  fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
           slow=slow->next;
            fast=fast->next->next;
        } 
        fast=head;
        slow=reverse(slow);
       					 // return checkit(str);
        while(slow!=NULL)
        {
            if(fast->data!=slow->data)
            {
                return false;
            }  
            slow=slow->next;
            fast=fast->next;
        } 
        return true;
}

