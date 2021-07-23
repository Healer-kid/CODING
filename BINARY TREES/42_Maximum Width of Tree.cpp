Maximum Width of Tree 
Easy Accuracy: 50.0% Submissions: 35919 Points: 2
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2



LOGIC:
DO level order traversal and maintain a count value 

int getMaxWidth(Node* root)
{
    int count;
    int result=0;
   // Your code here
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       count=q.size();
       result=max(result,count);
       while(count--){
       Node*temp=q.front();
       q.pop();
       if(temp->left)
       q.push(temp->left);
       if(temp->right)
       q.push(temp->right);
       
       
       }
       
       
   }
   return result;
   
     
   
   
}

