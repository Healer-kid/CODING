Reverse Level Order Traversal 
Easy Accuracy: 47.34% Submissions: 50697 Points: 2
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

void reversePrint(Node *root)
{
    //Your code here
     queue<Node*> q;
     stack<int> s;
   q.push(root);
   while(!q.empty()){
       
       
       
       Node*temp=q.front();
       q.pop();
       s.push(temp->data);
       if(temp->right)
       q.push(temp->right);
       if(temp->left)
       q.push(temp->left);
       
       
       }
       
   while(!s.empty())    
   {
       cout<<s.top()<<" ";
       s.pop();
       
   }
  
    
}