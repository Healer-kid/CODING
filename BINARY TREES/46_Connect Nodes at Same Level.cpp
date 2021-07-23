Connect Nodes at Same Level 
Medium Accuracy: 45.67% Submissions: 63847 Points: 4
Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

 

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL
Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
         10 ----------> NULL
       /     \
     20 ------> 30 -------> NULL
  /    \
 40 ----> 60 ----------> NULL




void connect(Node *p)
{
   // Your Code Here
   queue<Node*> q;
   q.push(p);
   q.push(NULL);
   while(!q.empty()){
      Node*temp=q.front();
      q.pop();
      if(temp!=NULL){
          temp->nextRight=q.front();
          if(temp->left)
          q.push(temp->left);
          if(temp->right)
          q.push(temp->right);
          
          
          
          
      }else if(!q.empty()){
          q.push(NULL);
          
      }
       
       
       
       
   }
   
    
   
   
   
   
}

