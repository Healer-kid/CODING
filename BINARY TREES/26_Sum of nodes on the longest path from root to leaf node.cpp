Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) 

Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11






CODE:
public:
    void helper(Node*root,int &maxheight,int &maxsum,int height,int sum){
        if(root==NULL)
        return;
        
        sum+=root->data;
         if(maxheight<height)
        {
            maxheight=height;
            maxsum=sum;
        }
        else if(maxheight==height)
        {
            maxsum=max(sum,maxsum);
        }
        helper(root->left,maxheight,maxsum,height+1,sum);
        helper(root->right,maxheight,maxsum,height+1,sum);
        
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        
       int maxheight=-1;
       int maxsum=0;
       helper(root,maxheight,maxsum,0,0);
        return maxsum;
        
              
        
        
        
        
    }