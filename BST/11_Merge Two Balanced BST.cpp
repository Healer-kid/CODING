Merge Two Balanced Binary Search Trees
Difficulty Level : Medium
Last Updated : 20 Jul, 2021
You are given two balanced binary search trees e.g., AVL or Red-Black Tree. Write a function that merges the two given balanced BSTs into a balanced binary search tree. 
Let there be m elements in the first tree and n elements in the other tree. Your merge function should take O(m+n) time.



1) find the inorder traversal of both arrays and store em in 2 separate arrays
2) merge the two sorted arrays
3) now create a balanced binarysearch tree similar to the last problem(convert a bst to balanced bst)