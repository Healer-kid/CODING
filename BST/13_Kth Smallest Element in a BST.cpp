Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

-----------------------------------



  void solve(TreeNode * root,int K,int &c,int &ans)
  {
      if(root==NULL)
      return;
      solve(root->left,K,c,ans);
      c++;
      if(c==K)
      {
          ans=root->val;
          return;
          
      }
      solve(root->right,K,c,ans);
      
  }
    int kthSmallest(TreeNode* root, int K) {
        
        int ans=-1,c=0;
        solve(root,K,c,ans);
        return ans;
        
        
        
        
    }