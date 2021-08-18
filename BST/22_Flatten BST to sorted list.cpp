Flatten BST to sorted list | Increasing order
Difficulty Level : Medium
Last Updated : 04 Aug, 2021
Given a binary search tree, the task is to flatten it to a sorted list. Precisely, the value of each node must be lesser than the values of all the nodes at its right, and its left node must be NULL after flattening. We must do it in O(H) extra space where ‘H’ is the height of BST.

Examples: 

Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
Output: 2 3 4 5 6 7 8
Input:
      1
       \
        2
         \
          3
           \
            4
             \
              5
Output: 1 2 3 4 5



void inorder(node* curr, node*& prev)
{
  
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
 

node* flatten(node* parent)
{
   
    node* dummy = new node(-1);
     node* prev = dummy;
 
   
    inorder(parent, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
 
   
    delete dummy;
    return ret;
}