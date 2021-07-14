Top View of Binary Tree 
Medium Accuracy: 32.3% Submissions: 81771 Points: 4
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100



void topView(struct Node *root)
{
    //Your code here
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push(make_pair(root,0));
    while(!q.empty()){
        Node*temp=q.front().first;
        hd=q.front().second;
        if(mp.find(hd)==mp.end())
        mp[hd]=temp->data;
        q.pop();
        if(temp->left)
        q.push(make_pair(temp->left,hd-1));
        if(temp->right)
        q.push(make_pair(temp->right,hd+1));
        
        
    }
    for(auto i:mp)
    cout<<i.second<<" ";
    
    
    
    
    
}


