Flattening a Linked List 

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.



METHOD-1
TIME:O(M*N)
SPACE:O(N) 
USING MULTISET


Node *flatten(Node *root)
{
   // Your code here
   multiset<int> s;
   
   Node* right = root ;
   Node* down = root ;
   
   while(right){
       down = right ;
       while(down){
           s.insert(down->data);
           down = down->bottom;
       }
       right = right->next ;
   }
   
   Node* head = new Node(0);
   Node* temp = head ;
   
   for(int i : s){
       temp->bottom = new Node(i);
       temp = temp->bottom ;
   }
   
   return head->bottom ;
}



METHOD-2
USING RECURSION
TIME:O(M*N)
SPACE:O(1)


Node*merge(Node*a,Node*b){
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    Node*result;
    if(a->data<b->data){
    result=a;
    result->bottom=merge(a->bottom,b);
    }else{
        
        result=b;
        result->bottom=merge(a,b->bottom);
        
    }
    return result;
}    
    
    
    
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL||root->next==NULL)
   return root;
   
   return merge(root,flatten(root->next));
   
}





















