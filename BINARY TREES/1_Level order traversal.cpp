Level order traversal 

Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.


Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N



void levelOrder(Node* node)
{
  //Your code here
  if(node==NULL)
  return;
  queue<Node *> q;
  q.push(node);
  while(!q.empty()){
      Node * node=q.front();
      cout<< node->data <<" ";
      q.pop();
      if(node->left!=NULL)
      q.push(node->left);
      if(node->right!=NULL)
      q.push(node->right);
      
      
      
      
      
  }
  
  
  
  
  
  
}