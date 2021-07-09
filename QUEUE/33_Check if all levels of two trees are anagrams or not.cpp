Check if all levels of two trees are anagrams or not
Difficulty Level : Medium
Last Updated : 08 Nov, 2020
Given two binary trees, we have to check if each of their levels are anagrams of each other or not.

Example:


Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5
As we can clearly see all the levels of above two binary trees are anagrams of each other, hence return true.

We traverse both trees simultaneously level by level. We store each level both trees in vectors (or array). To check if two vectors are anagram or not, we sort both and then compare.

Time Complexity: O(nlogn), where n is the number of nodes.



bool areAnagrams(Node *root1, Node *root2)
{
    // Base Cases
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
  
   
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
  
    while (1)
    {
        
        int n1 = q1.size(), n2 = q2.size();
  
        if (n1 != n2)
            return false;
  
        // If level order traversal is over  
        if (n1 == 0)
            break;
  
       					 // Dequeue all Nodes of current level and
       					 // Enqueue all Nodes of next level
        vector<int> curr_level1, curr_level2;
        while (n1 > 0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
            n1--;
  
            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);
  
            curr_level1.push_back(node1->data);
            curr_level2.push_back(node2->data);
        }
  
       				 // Check if nodes of current levels are 
        			// anagrams or not.
        sort(curr_level1.begin(), curr_level1.end());
        sort(curr_level2.begin(), curr_level2.end());
       
	 if (curr_level1 != curr_level2)
            return false;
    }
  
    return true;
}