Left View of Binary Tree 
Easy Accuracy: 37.86% Submissions: 100k+ Points: 2
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3



void rights(Node*root,int level,int *maxl){
   if(root==NULL)
   return;
   
    if(root)
        if(level>*maxl){
           *maxl=level;
       cout<< root->data<<" ";
        
        }
    if(root->left)
    rights(root->left,level+1,maxl);
    
    if(root->right)
    rights(root->right,level+1,maxl);
    
    
    
    
}

void leftView(Node *root)
{
   // Your Code here
   if(root==NULL)
   return;
   int maxl=-1;
   rights(root,0,&maxl);
  
   
   
   
}


