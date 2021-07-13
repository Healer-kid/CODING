Right View of Binary Tree 
Easy Accuracy: 51.66% Submissions: 60386 Points: 2
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60


void rights(Node*root,int level,int *maxl){
   if(root==NULL)
   return;
   
    if(root)
        if(level>*maxl){
           *maxl=level;
       cout<< root->data<<" ";
        
        }
    if(root->right)
    rights(root->right,level+1,maxl);
    
    if(root->left)
    rights(root->left,level+1,maxl);
    
    
    
    
}

void rightView(Node *root)
{
   // Your Code here
   if(root==NULL)
   return;
   int maxl=-1;
   rights(root,0,&maxl);
  
   
   
   
   
   
}
