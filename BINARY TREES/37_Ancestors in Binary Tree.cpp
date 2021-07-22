





Ancestors in Binary Tree 
Easy Accuracy: 39.92% Submissions: 26321 Points: 2
Given a Binary Tree and a target key, you need to find all the ancestors of the given target key.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Example 1:

Input:
        1
      /   \
     2     3
target = 2
Output: 1

Example 2:

Input:
         1
       /   \
      2     3
    /  \   /  \
   4    5 6    8
  /
 7
target = 7
Output: 4 2 1
 









------------------------------------
class Solution{
  public:
    bool AncestorsUtil(struct Node *root, int target,vector<int> &nodes)
    {
        if (root == NULL)
    	    return false;
        if (root->data == target)
    	    return true;
        if ( AncestorsUtil(root->left, target,nodes) ||AncestorsUtil(root->right, target,nodes) )
        {
    	    nodes.push_back(root->data);
    	    return true;
        }
        return false;
    }
    
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> nodes;
        AncestorsUtil(root,target,nodes);
        return nodes;
    }

};