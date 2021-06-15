Add 1 to a number represented as linked list 

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 


LOGIC:
1)REVERSE THE LINKED LIST
2) ADD ONE
3)REVERSE THE LINKED LIST AGAIN




  Node* reverse(Node* head){					//REVERSE
        
        Node*prev=NULL,*curr=head,*Next=NULL;
        while(curr!=NULL)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
            
            
            
        }
        return prev;
    }
    
    
    Node* addition(Node* head)				//ADDING ONE
    {
         Node*ans=head;
        Node*temp=NULL;
        
       
        int sum=0,carry=1;
        while(head!=NULL)
        {
            sum=carry+head->data;
             carry=(sum>=10)?1:0;
             sum=sum%10;
             head->data=sum;
             temp=head;
             head=head->next;
            
            
            
            
        }
        
        if(carry>0)			//IF THE RESULTANT ANSWER HAS AN EXTRA DIGIT
					//SAY 9999 + 1 ==> 10000  (5 DIGITS)
        temp->next=new Node(carry);
        
        
        return ans;
        
    }
    
    
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        
       head=addition(head);
       
        head=reverse(head);

        return head;
        
    }
};