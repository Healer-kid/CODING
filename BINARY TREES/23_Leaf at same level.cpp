Leaf at same level 
Easy Accuracy: 49.76% Submissions: 27728 Points: 2
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.






int maxheight=-1;
  void solve(Node* root,int h,bool &ans)
  {
      if(root==NULL)
      return;
      if(ans==false)
      return;
      if(root->left==NULL && root->right==NULL)
      {
          if(maxheight==-1)
          maxheight=h;
          else{
              if(maxheight!=h)
              ans=false;
          }
          return;
      }
      
      
      solve(root->left,h+1,ans);
      solve(root->right,h+1,ans);
  }
  
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        bool ans=true;
        int h=0;
        solve(root,h,ans);
        return ans;
    }
};
