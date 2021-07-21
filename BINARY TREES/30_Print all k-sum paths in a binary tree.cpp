LINK:https://www.youtube.com/watch?v=_Ng486jJu80

Print all k-sum paths in a binary tree

A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.
Examples: 
 

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

LOGIC:
1)traverse and add the data into a vector,once it reached a leaf node,start finding the sum using the vector
2) find sum from backwards and check if it is equal to k,if so print
3) now remove the leaf node from the vector
4) now check for the next path by repeating the same


------------------------------------------------------


void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
 
 

void printKPathUtil(Node *root, vector<int>& path,
                                           int k)
{
    
    if (!root)
        return;
 
    path.push_back(root->data);
 
   
    printKPathUtil(root->left, path, k);
 
    
    printKPathUtil(root->right, path, k);
 
    
    int f = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        f += path[j];
 
      
        if (f == k)
            printVector(path, j);
    }
 
    
    path.pop_back();
}
 

void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}