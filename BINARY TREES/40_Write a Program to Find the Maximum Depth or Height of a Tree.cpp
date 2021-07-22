HEIGHT/DEPTH OF A TREE

int height(Node* node)
{
   // Your code here
   if(!node)
   return 0;
   if(node)
   return 1+max(height(node->left),height(node->right));
    
}