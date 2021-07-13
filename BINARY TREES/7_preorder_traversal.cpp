NLR


void preorder(Node* root)
{
   
    if (root == nullptr) {
        return;
    }
   
    cout << root->data << " ";
 
    preorder(root->left);
    
    preorder(root->right);
}

----------------------------------------------

ITERATIVE:

vector preorderTraversal(TreeNode* root) {

    stack<TreeNode*> mystack;
    vector<int> ans;
    
    if(root==NULL)
        return ans;
    
    mystack.push(root);
    
    while(!mystack.empty()){
        TreeNode* curr = mystack.top();
        mystack.pop();
        ans.push_back(curr->val);
      
        
        if(curr->right)
        mystack.push(curr->right);
        
        if(curr->left)
        mystack.push(curr->left);
    }
    
    return ans;
}