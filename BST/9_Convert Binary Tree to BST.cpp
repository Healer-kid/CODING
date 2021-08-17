ALGORITHM :-
1) traverse the binary tree in inorder fashion and store the values in an array A
2) sort the array A
3) traverse the binary tree(inorder) and the array A simultaneously
4)replace values in the nodes of binary tree with the values in the array as u traverse the tree and
also keep incrementing the index of the array



class Solution{
  public:
  vector<int> v;
  void inorder(Node*root){
      if(root==NULL)
      return ;
      inorder(root->left);
      v.push_back(root->data);
      inorder(root->right);
      
      
      
  }
  void check(Node* root,int &i){
      
      if(root==NULL)
      return ;
      
      check(root->left,i);
      root->data=v[i++];
      check(root->right,i);
      
      
  }
  
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        
        inorder(root);
        sort(v.begin(),v.end());
        int i=0;
        check(root,i);
        return root;
        
    }
};