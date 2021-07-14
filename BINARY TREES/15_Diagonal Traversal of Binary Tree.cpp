Diagonal Traversal of Binary Tree 
Medium Accuracy: 49.87% Submissions: 25129 Points: 4
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4








vector<int> diagonal(Node *root)
{

    queue<Node*> q;
    vector<int> v;
    
    q.push(root);
    while(!q.empty())
    {
    Node*temp=q.front();
    while(temp){
    v.push_back(temp->data);
    if(temp->left)
    q.push(temp->left);
    
    temp=temp->right;
    
    }
    q.pop();
    }

return v;

   // your code here
}