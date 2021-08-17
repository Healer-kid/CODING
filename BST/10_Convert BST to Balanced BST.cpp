Convert a normal BST to Balanced BST
Difficulty Level : Medium
Last Updated : 02 Jul, 2021
Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
Examples : 

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 
 


ALGORITHM:
----------------

1) Traverse the tree using inorder traversal and store the elements in a vector
2)find the middle element and make it as the root node
3) now for the root->left,search the left half and find the mid elment in that half
4) now for the root->right,search the right half and find the mid element in that half.


void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
    if (root==NULL)
        return;
 
    
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
 

Node* buildTreeUtil(vector<Node*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
   
    int mid = (start + end)/2;
    Node *root = nodes[mid];
 
   
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}
 

Node* buildTree(Node* root)
{
   
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
 
    
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}