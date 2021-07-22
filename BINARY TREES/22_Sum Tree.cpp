Sum Tree 
Medium Accuracy: 33.33% Submissions: 87932 Points: 4
Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return 0.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

 

Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The sum of left subtree and right subtree
is 1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

Example 2:

Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum
tree. For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.


class Solution
{
    public:
    int sum(Node*root){
    if(root==NULL)
    return 0;
    if(root)
    return root->data+sum(root->left)+sum(root->right);
    
}

bool isSumTree(Node* root)
{
     // Your code here
     if(root==NULL)
     return 1;
     if(root->left==NULL&&root->right==NULL)
     return 0;
     int l=sum(root->left);
     int r=sum(root->right);
     int total=l+r;
     if(total==root->data )
     return true;
     else
     return false;
    
    
    
}
};

