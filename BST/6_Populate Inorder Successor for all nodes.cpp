Populate Inorder Successor for all nodes 
Medium Accuracy: 47.39% Submissions: 17865 Points: 4
Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Example 1:

Input:
           10
       /  \
      8    12
     /
    3
  

Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is :
3 8 10 12. So the next pointer of node 3 is 
pointing to 8 , next pointer of 8 is pointing
to 10 and so on.And next pointer of 12 is
pointing to -1 as there is no inorder successor 
of 12.
Example 2:

Input:
           1
      /   \
     2     3
Output: 2->1 1->3 3->-1 



class Solution
{
public:
    Node*prev=NULL;
    void populateNext(Node *root)
    {
        //code here
        if(root==NULL)
        return;
        
        populateNext(root->left);
        if(prev!=NULL)
        prev->next=root;
        prev=root;
        
        populateNext(root->right);
        
        
    }
};