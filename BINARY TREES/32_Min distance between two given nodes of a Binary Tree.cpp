Min distance between two given nodes of a Binary Tree 
Medium Accuracy: 45.05% Submissions: 42945 Points: 4
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 



Node*lCA(Node*root,int a, int b){
    if(root==NULL)
    return NULL;
    if(root->data==a||root->data==b)
    return root;;
    Node*l=lCA(root->left,a,b);
    Node*r=lCA(root->right,a,b);
    if(l&&r)
    return root;
    return l?l:r;
    
    
} 
int dist(Node*root,int val,int dis){
    if(root==NULL)
    return 0;
    if(root->data==val)
    return dis;
    return max(dist(root->left,val,dis+1),dist(root->right,val,dis+1));
    
}
int findDist(Node* root, int a, int b) {
    // Your code here
    Node*lca=lCA(root,a,b);
    int i=dist(lca,a,0);
    int j=dist(lca,b,0);
    return i+j;
    
}