LINK:https://www.youtube.com/watch?v=YgC-IXiMrRM


Largest BST 
Medium Accuracy: 30.88% Submissions: 43805 Points: 4
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8



NOTE:::::::::
------------
Doing inorder traversal and finding the longest increasing subarray 
is not working why ?

ANSWER:
Longest increasing subarray in inorder might be fromed from two 
or more subtree thus it will not be a correct ans 
---------------------------------------------------


METHOD-1  -->O(N^2) SOLN
----------------
Simple recursive C++ solution -->

bool isBST(Node* root,int min,int max){
if(!root) return true;
if(root->data<=min || root->data>=max) return false;
return (isBST(root->left,min,root->data) && isBST(root->right,root->data,max));
}
int size(Node* root){
if(!root) return 0;
return size(root->left)+1+size(root->right);
}
int largestBst(Node *root)
{
if(isBST(root,INT_MIN,INT_MAX)) return size(root);
return max(largestBst(root->left),largestBst(root->right));
}

--------------------------
METHOD-2
------------

class Solution{
    public:
    
    struct info{
int size;
int maxi;
int mini;
int ans;
bool isBST;
};
info largestbst(Node *root)
{ if(!root){return {0,INT_MIN,INT_MAX,0,true};}
if(!root->left && !root->right){return{1,root->data,root->data,1,true};}
info left = largestbst(root->left);
info right = largestbst(root->right);
info curr;
curr.size = 1 + right.size + left.size;
if(left.isBST && right.isBST && left.maxi<root->data && right.mini>root->data){
curr.mini = min(left.mini,root->data);
curr.maxi = max(right.maxi,root->data);
curr.ans=curr.size;
curr.isBST=true;
return curr;
}
curr.ans=max(left.ans,right.ans);
curr.isBST=false;
return curr;
}
int largestBst(Node *root){
return largestbst(root).ans;
}
};



