
Median of BST 
Easy Accuracy: 43.23% Submissions: 20012 Points: 2
Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.

Example 2:

Input:
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.
 


-----------------------------------



int sizefun(Node* root){
    if(root==NULL)
    return 0;
    
    return 1+sizefun(root->left)+sizefun(root->right);
    
}
void inOrder(Node* root,int &prev, int &curr,int &i,int n)
{
if(!root) return;
inOrder(root->left,prev,curr,i,n);
i++;
if(i<=n)
{
prev=curr;
curr=root->data;
}
inOrder(root->right,prev,curr,i,n);
}


float findMedian(struct Node *root)
{
      //Code here
      
      int size=sizefun(root);
    
     int prev=0,i=0;
     int curr=0;
    int n=size/2 + 1;
   inOrder(root,prev,curr,i,n);
   if(size&1) return curr;

return (prev + curr)/2.0;
     
      
      
}