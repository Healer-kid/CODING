Insert a node in a BST 
Easy Accuracy: 32.7% Submissions: 64083 Points: 2
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.











Node* insert(Node* root, int Key)
{
    // Your code here
    
    if(root==NULL)
    {
       root=new Node(Key);
       return root;
        
    }
    
    else if(root->data>Key)
    root->left=insert(root->left,Key);
     
    else if(root->data<Key)
     root->right=insert(root->right,Key);
   
    else
    return root;
    
}