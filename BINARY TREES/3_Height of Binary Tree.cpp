Height of Binary Tree 
Medium Accuracy: 65.76% Submissions: 100k+ Points: 4
Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   


int height(Node* node)
{
   // Your code here
   if(!node)
   return 0;
   if(node)
   return 1+max(height(node->left),height(node->right));
    
}