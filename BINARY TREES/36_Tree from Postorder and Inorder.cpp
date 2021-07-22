Tree from Postorder and Inorder 
Medium Accuracy: 49.98% Submissions: 21744 Points: 4
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3


-----------------------------------


int search(int arr[],int val,int start,int end){
    
   for(int i=start;i<=end;i++) 
    {
        if(arr[i]==val)
        return i;
    }

    
}
Node*binarytree(int in[],int post[],int instart,int inend,int *postorder){
    
    
    if(instart>inend)
    return NULL;
    
    Node*tnode=new Node(post[*postorder]);
    (*postorder)--;
    if(instart==inend)
    return tnode;
    int inindex=search(in,tnode->data,instart,inend);
    
    
    tnode->right=binarytree(in,post,inindex+1,inend,postorder);
    tnode->left=binarytree(in,post,instart,inindex-1,postorder);
    return tnode;
    
    
    
}





Node* buildTree(int in[],int post[], int n)
{
//add code here.
int postorder=n-1;
return binarytree(in,post,0,n-1,&postorder);




}
