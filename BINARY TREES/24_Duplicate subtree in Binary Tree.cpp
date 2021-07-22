Duplicate subtree in Binary Tree 
Medium Accuracy: 44.66% Submissions: 21141 Points: 4
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.


Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.



 public:
   
    unordered_map<string,int> mp;
    string solve(Node* root){  
        if(root==NULL) //if empty return $
        return "$";
         string S="";
        if(root->left==NULL && root->right==NULL) //if leaf node return the string constructed
        {
            S+=to_string(root->data);
            return S;
        }
       
        S+=to_string(root->data);
        S+=solve(root->left);
        S+=solve(root->right);
        
        mp[S]++;
        return S;
        
    }
    
    int dupSub(Node *root) {
         // code here
         solve(root); //we do preorder traversal and find the string as well
         for(auto i:mp)
         {
             if(i.second>1)
             return true;
         }
         return false;
         
    }
};
