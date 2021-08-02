

class Solution
{
  public:
  void dll(Node* &head,Node* &prev,Node*root){
     if(root==NULL)
     return;
     dll(head,prev,root->left);
     if(prev==NULL)
     {
         head=root;
         prev=root;
     }else{
         prev->right=root;
         prev->right->left=prev;
         prev=prev->right;
         
     }
      
     dll(head,prev,root->right);   
      
  }
  
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
    
    Node*head=NULL,*prev=NULL;
    
    dll(head,prev,root);
    
   

//	connecting the last node and first node to make it circular//
 Node*p=head;
    while(p->right)
    {
        p=p->right;
    }
    
    p->right=head;
    head->left=p;
    
    return head;
    
    }
};