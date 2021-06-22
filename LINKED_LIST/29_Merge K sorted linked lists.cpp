Merge K sorted linked lists 

Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.


CODE:

//Function to merge K sorted linked list.
    Node* merge(Node *l1 , Node *l2){
        if(!l1)
            return l2 ;
        
        if(!l2)
            return l1 ;
            
        if(l1->data < l2->data){
            l1->next = merge(l1->next,l2);
            return l1 ;
        }else{
            l2->next = merge(l1,l2->next);
            return l2 ;
        }
        
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node* res = arr[0] ;
           
           for(int i = 1 ; i < K ; i++){
               res = merge(res,arr[i]);
           }
           
           return res ;
    }
    
};


