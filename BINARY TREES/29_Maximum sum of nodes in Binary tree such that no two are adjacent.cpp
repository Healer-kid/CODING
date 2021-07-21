Maximum sum of nodes in Binary tree such that no two are adjacent
Difficulty Level : Hard
Last Updated : 01 Jul, 2021
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen node in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take any of its children in consideration and vice versa. 

refer the question from this link:https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/


unordered_map<Node*,int> dp;
int func(Node* root)
{

if(!root)
return 0;

if(dp[root])
return dp[root];

int inc=root->data;
if(root->left)
{
	inc+=func(root->left->left);
	inc+=func(root->left->right);

}
if(root->right)
{
	inc+=func(root->right->left);
	inc+=func(root->right->right);


}

int exc=func(root->left)+func(root->right);

dp[root]=max(inc,exc);
return dp[root];


}
