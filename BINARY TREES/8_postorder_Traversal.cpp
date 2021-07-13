LRN


Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5


Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19
Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11


RECURSIVE:

void postorder(Node* root)
{
   
    if (root == nullptr) {
        return;
    }
 
   
     postorder(root->left);
     postorder(root->right);
     cout << root->data << " ";
}
-----------------------------------------------------------

ITERATIVE:
USING 2 STACKS

1.in the second stack ,the order will be NRL (reverse of post order traversal)

void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    stack<Node *> s1, s2;
    
    s1.push(root);
    Node* node;
 
    
    while (!s1.empty()) {
        
        node = s1.top();
        s1.pop();
        s2.push(node);
 
       
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
   
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}


--------------------------------------------------------

USING ONLY ONE STACK



 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        stack<TreeNode*> s;
        if(root == NULL)
            return out;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            if(temp!=NULL)
            {
                out.push_back(temp->val);
                s.push(temp->left);
                s.push(temp->right);
            }
        }
        reverse(out.begin(),out.end());
        return out;
    } 
