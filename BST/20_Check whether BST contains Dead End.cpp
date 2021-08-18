Check whether BST contains Dead End 
Easy Accuracy: 46.96% Submissions: 18338 Points: 2
Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9.  





bool check(Node* root,int min,int max){
    if(root==NULL)
    return false;
   if(min==max)return true;
    return check(root->left,min,root->data-1)or check(root->right,root->data+1,max);
    
}

bool isDeadEnd(Node *root)
{
    //Your code here
    return check(root,1,INT_MAX);
}