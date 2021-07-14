ZigZag Tree Traversal 

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 



void zizagtraversal(struct Node* root)
{
   
    if (!root)
        return;
 
    
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;
 
   
    currentlevel.push(root);
 
   
    bool lefttoright = true;
    while (!currentlevel.empty()) {
 
        
        struct Node* temp = currentlevel.top();
        currentlevel.pop();
 
        
        if (temp) {
 
            
            cout << temp->data << " ";
 
            
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}