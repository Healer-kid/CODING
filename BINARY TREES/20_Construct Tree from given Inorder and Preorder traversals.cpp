Construct Tree from given Inorder and Preorder traversals

Let us consider the below traversals:
Inorder sequence: D B E A F C 
Preorder sequence: A B D E C F


In a Preorder sequence, the leftmost element is the root of the tree. So we know ‘A’ is the root for given sequences. By searching ‘A’ in the Inorder sequence, we can find out all elements on the left side of ‘A’ is in the left subtree, and elements on right in the right subtree. So we know the below structure now. 

                 A
               /   \
             /       \
           D B E     F C
We recursively follow the above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F



INORDER ---> WILL GIVE YOU WHICH WILL BE ON RIGHT AND WHICH WILL BE ON LEFT
PREORDER---> WILL TELL YOU THE ROOT NODE AT EACH LEVEL












METHOD-1

using a separate search function will make the whole code as o(n2)


CODE:

node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    
    node* tNode = newNode(pre[preIndex++]);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
   
    int inIndex = search(in, inStrt, inEnd, tNode->data);
 
  
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}

int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}




------------------------------------------------------------------------










METHOD-2
STORING THE INORDER VALUES AND INDICES IN A MAP WILL SAVE THE TIME OF SEARCHING

struct Node* buildTree(char in[], char pre[], int inStrt,
                       int inEnd, unordered_map<char, int>& mp)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
   
    char curr = pre[preIndex++];
    struct Node* tNode = newNode(curr);
 
   
    if (inStrt == inEnd)
        return tNode;
 
  
    int inIndex = mp[curr];
 
   
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
 
    return tNode;
}
 

struct Node* buldTreeWrap(char in[], char pre[], int len)
{
    
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    return buildTree(in, pre, 0, len - 1, mp);
}
 



 