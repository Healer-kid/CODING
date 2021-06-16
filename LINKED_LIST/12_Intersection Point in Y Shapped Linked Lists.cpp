Intersection Point in Y Shapped Linked Lists 

Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       

METHOD-1
USING DIFFERENCE
TIME:O(M+N)

CODE:

int intersectPoint(Node* head1, Node* head2)
{
  Node * temp1=head1,*temp2=head2;
    int count1=0,count2=0,count;
    while(temp1){
        count1++;
        temp1=temp1->next;
        
        
    }
    while(temp2){
        
        count2++;
        temp2=temp2->next;
        
    }
    if(count1>count2){
        count=count1-count2;
        while(count--){
            head1=head1->next;
            
        }
        
        
        
        
    }else{
        count=count2-count1;
        while(count--){
            head2=head2->next;
            
            
            
        }
        
        
    }
    while(head1!=head2){
        head1=head1->next;
        head2=head2->next;
        
        
    }
    
    
    return head1->data;
    
}




METHOD-2( 2-pointer technique ):

TIME:O(M+N)


Using Two pointers :

-->Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
-->Traverse through the lists,one node at a time.
-->When ptr1 reaches the end of a list, then redirect it to the head2.
-->similarly when ptr2 reaches the end of a list, redirect it the head1.
-->Once both of them go through reassigning,hey will be equidistant from
 the collision point
-->If at any node ptr1 meets ptr2, then it is the intersection node.
-->After second iteration if there is no intersection node it returns NULL.

Node* intersectPoint(Node* head1, Node* head2)
{
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    
    if (ptr1 == NULL || ptr2 == NULL) {

        return NULL;
    }

    
    while (ptr1 != ptr2) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

            
        if (ptr1 == NULL) {

            ptr1 = head2;
        }
       
        if (ptr2 == NULL) {

            ptr2 = head1;
        }
    }

    return ptr1;
}