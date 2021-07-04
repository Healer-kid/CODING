Diameter of Binary Tree 
Easy Accuracy: 50.01% Submissions: 100k+ Points: 2
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4






int height(Node*node){
    if(node==NULL)return 0;
    
    return max(height(node->left),height(node->right))+1;
    
    
}
int diameter(Node* node) {
if(node==NULL)
return 0;
int lh=height(node->left);
int rh=height(node->right);
int ld=diameter(node->left);
int rd=diameter(node->right);

return max(lh+rh+1,max(ld,rd));    
    
    
    
}
