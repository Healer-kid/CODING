Segregate even and odd nodes in a Link List 

Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.


Example 1:

Input: 
N = 7
Link List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 17,15,8,9 are odd so they appear 
first and 2,4,6 are the even numbers that appear later.

Example 2:

Input:
N = 4
Link List = 1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number. 
So ne need for modification.
METHOD-1
USING TWO ARRAYS
TIME:O(N)
SPACE:O(N)

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(!head || !head->next)
        return head;
        
        vector<int>even,odd;
        Node*head1=head;
        while(head!=NULL){
            
            if(head->data%2==0)
            even.push_back(head->data);
            else
            odd.push_back(head->data);
            head=head->next;
            
        }
        Node*temp=head1;
        for(int i=0;i<even.size();i++){
          temp->data=even[i];
          temp=temp->next;
            
        }
        for(int i=0;i<odd.size();i++){
          temp->data=odd[i];
          temp=temp->next;
            
        }
        
        return head1;
    }
};









METHOD-2
USING 2 LINKED LIST AND MERGING THEM
TIME:O(N)
SPACE;O(N)


class Solution{
public:
Node* divide(int N, Node *head){
// code here
	if(!head->next){
	return head;
	}

	Node* even;
	Node* odd;
	Node* firstodd = NULL;
	Node* firsteven = NULL;
	Node* temp = head;
	while(temp){
		if(temp->data % 2 == 0){
			if(!firsteven){
			firsteven = temp;
			even = temp;
			}
			else{
			even->next = temp;
			even = temp;
			}

		}
		else{

			if(!firstodd){
			firstodd = temp;
			odd = temp;
			}
			else{
			odd->next = temp;
			odd = temp;
			}
		}
		temp = temp->next;

		}

//NOW MERGING BOTH 

		if(!firsteven){
			return firstodd;
		}
		else {

			if(firstodd){
			even->next = firstodd;
			odd->next = NULL;
			return firsteven;

			}
			else{
			return firsteven;
			}

		}
}
};