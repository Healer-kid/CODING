Boundary Traversal of binary tree 
Medium Accuracy: 26.78% Submissions: 92672 Points: 4
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3
Explanation:


Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22





void printleft(Node*root){
    if(root==NULL)
    return;
   // cout<<root->data<<" ";
    if(root->left){
    cout<<root->data<<" ";
    printleft(root->left);
    
    }else if(root->right){
     cout<<root->data<<" ";
     printleft(root->right);
        
    } 
    
    
}
void printright(Node*root){
    if(root==NULL)
    return;
    if(root->right){
    printright(root->right);
    cout<<root->data<<" ";
    }else if(root->left){
        
        printright(root->left);
        cout<<root->data<<" ";
        
    }
    
    
}
void leaf(Node*root){
    if(root==NULL)
    return;
    leaf(root->left);
    if(!root->left && !root->right)
    cout<<root->data<<" ";
    
    leaf(root->right);
    
    
}



void printBoundary(Node *root)
{
 
 if(root==NULL)
 return;
 cout<<root->data<<" ";
 printleft(root->left);
 leaf(root->left);
 leaf(root->right);
 printright(root->right);
 
 
 
 
 
 
 
 }

