
RECURSIVE 

void inorder(Node* root)
{
    
    if (root == nullptr) {
        return;
    }
     
    inorder(root->left);
     cout << root->data << " ";
  
    inorder(root->right);
}

---------------------------------------------------------
//     Iterative
public: 

    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }