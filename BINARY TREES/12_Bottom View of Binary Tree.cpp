Bottom View of Binary Tree 
Medium Accuracy: 45.32% Submissions: 77043 Points: 4
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.




void bottomView(Node *root)
{
  map<int,int> mp;
  int hd=0;
  if(root==NULL)
  return;
  queue<pair<Node*,int>> q;
  q.push(make_pair(root,hd));
  while(!q.empty()){
      
      Node*temp=q.front().first;
      hd=q.front().second;
      q.pop();
      
      mp[hd]=temp->data;
      if(temp->left){
          q.push(make_pair(temp->left,hd-1));
          
      }
      if(temp->right){
          q.push(make_pair(temp->right,hd+1));
          
      }
      
      
      
      
  }
  for(auto i:mp)
  cout<<i.second<<" ";
  
}