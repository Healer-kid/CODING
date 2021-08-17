Check for BST 
Easy Accuracy: 21.58% Submissions: 100k+ Points: 2
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:

Input:
    2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node 
with key lesser than the root node’s key and 
the right subtree of root node contains node 
with key greater than the root node’s key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).






void inrder(Node*root,vector<int> &v){
    if(root==NULL)
    return ;
    inrder(root->left,v);
    v.push_back(root->data);
    inrder(root->right,v);
    return;
    
}

bool isBST(Node* root) {
    // Your code here
    vector<int> v;
   inrder(root,v); 
   for(int i=1;i<v.size();i++)
    {
        if(v[i]>v[i-1])
        continue;
        else
        return false;
        
    }  
    return true;
}









--------------------------------
METHOD-1
-------------
NOTE: MIN=0,MAX=1001 THE RANGE OF VALUES TAKEN FROM CONSTRAINTS


bool checkBST(Node *root,int min,int max)
{
    if(!root)
        return true;    
    if(root->data>min && root->data<max)
        return (checkBST(root->left,min,root->data) && checkBST(root->right,root->data,max));

    return false;
}

bool isBST(Node* root) {
   
    if(!root)
        return true;
    if(checkBST(root->left,0,root->data) && checkBST(root->right,root->data,1001))
        return true;
    return false;
}