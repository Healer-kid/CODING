450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?

 

Example 1:



int findminfromright(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(root->right==nullptr){
                return root->left;
            }else if(root->left==nullptr){
                return root->right;
            }else{
			    //replace the root value by find the minimum val from right side 
                root->val=findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
   
};