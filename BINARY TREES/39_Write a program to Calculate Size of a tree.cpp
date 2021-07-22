Write a program to Calculate Size of a tree | Recursion
Difficulty Level : Easy
Last Updated : 02 Jul, 2021
Size of a tree is the number of elements present in the tree. 
 
SIZE==> NO.OF NODES


int size(node* node)
{
    if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}