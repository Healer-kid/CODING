Minimum swap required to convert binary tree to binary search tree
Given the array representation of Complete Binary Tree i.e,
 if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
 The task is to find the minimum number of swap required to convert it into Binary Search Tree.

Examples:  

Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
Output : 3
Binary tree of the given array:


Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.


So, minimum 3 swaps are required.


Input : arr[] = { 1, 2, 3 }
Output : 1
Binary tree of the given array:

After swapping node 1 with node 2.
So, only 1 swap required.










LOGIC:
1)Find the inorder traversal and store it in a vector (since the inorder traversal of a binary search tree will be in 
sorted order)
2)so we will compare this unarranged array with a sorted one,and find the minimum swaps

void inorder(int a[], std::vector<int> &v,int n, int index)
{
	// if index is greater or equal to vector size
	if(index >= n)
		return;

	inorder(a, v, n, 2 * index + 1); //instead of root->left ,we use 2i+1 (since we are accessing array not a real tree)
	v.push_back(a[index]);
	inorder(a, v, n, 2 * index + 2);//intead of root->right,we use 2i+2
}

int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> v(nums.size());
	    for(int i=0;i<nums.size();i++)
	    {
	        v[i]={nums[i],i};
	        
	        
	    }
	    sort(v.begin(),v.end());
	    
	    int c=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        if(v[i].second==i)
	        continue;
	        else{
	           c++;
	           swap(v[i],v[v[i].second]);
	           i--;
	           
	        }
	        
	        
	    }
	    
	    return c; 
	}
};
