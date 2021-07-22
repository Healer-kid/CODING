 Most Frequent Subtree Sum

Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

 

Example 1:

	 5
	/ \
       2  -3

Input: root = [5,2,-3]
Output: [2,-3,4]

Example 2:
	 5
	/ \
       2  -5
	

Input: root = [5,2,-5]
Output: [2]



--------------------------------


int findSubtreeSum(TreeNode* root, unordered_map<int,int> &map,int &maxFrequency){
        
       if(root == NULL)
           return 0;
        
        int left = findSubtreeSum(root->left,map,maxFrequency);
        int right = findSubtreeSum(root->right,map,maxFrequency);
        
        int currSubTreeSum = left + right + root->val;
        
        map[currSubTreeSum] += 1 ;
        
        if(map[currSubTreeSum]>maxFrequency)
            maxFrequency = map[currSubTreeSum];
        
        return currSubTreeSum;
        
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int>map;
        
        int maxFrequency = 0 ;
        
        findSubtreeSum(root,map,maxFrequency);
        
        vector<int>result;
        
        for(auto element : map)
            if(element.second == maxFrequency)
                result.push_back(element.first);
        
        return result;
    }
};