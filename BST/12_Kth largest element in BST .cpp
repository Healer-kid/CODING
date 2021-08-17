Kth largest element in BST 
Easy Accuracy: 42.26% Submissions: 46586 Points: 2
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

-----------------------------------------


  public:
    void solve(Node * root,int K,int &c,int &ans)
  {
      if(root==NULL)
      return;
      solve(root->right,K,c,ans);
      c++;
      if(c==K)
      {
          ans=root->data;
          return;
          
      }
      solve(root->left,K,c,ans);
      
  }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int ans=-1;
        int c=0;
        solve(root,K,c,ans);
        return ans;
        
    }