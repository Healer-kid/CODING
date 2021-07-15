Binary Tree to DLL 
Hard Accuracy: 41.34% Submissions: 68765 Points: 8
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

TreeToList

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.


class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void helperfn(Node* &head,Node* &prev,Node* root)
    {
        if(!root)
        return;
      helperfn(head,prev,root->left);
      if(prev==NULL)
        {
            head=root;
            prev=root;
            
        }else{
            
            prev->right=root;
            prev->right->left=prev;
            prev=prev->right;
            
            
        }
        
         helperfn(head,prev,root->right); 
        
        
        
    }
    
    
    
    Node * bToDLL(Node *root)
    {
        // your code here
        Node*head=NULL,*prev=NULL;
        helperfn(head,prev,root);
        return head;
        
    }
};
