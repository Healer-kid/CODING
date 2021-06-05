UTUBE LINK:https://www.youtube.com/watch?v=KtrAWsfyBaA

Searching in an array where adjacent differ by at most k
Difficulty Level : Easy
A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.
Examples: 
 

Input : arr[] = {4, 5, 6, 7, 6}
           k = 1
           x = 6
Output : 2
The first index of 6 is 2.

Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5





METHOD-1
USING LINEAR SEARCH
TIME:O(N)



METHOD-2
OPTIMISED SOLN
TIME:O(N)  //BUT WITH LESS COMPARISON

The difference between all adjacent elements is at most k. The idea is to start comparing from the leftmost element and find the difference between the current array element and x. Let this difference be ‘diff’. From the given property of the array, we always know that x must be at least ‘diff/k’ away, so instead of searching one by one, we jump ‘diff/k’. 


EG)


 5 6 7 9 10 11
K=2
X=11

we know that the diff bw the adjacent element is 2 (so the adj of 5 can be 7 or 6 )
similarly adj of 6 can be 7 or 8 

STEP 1:
	11-5 ==> 6/2 ==> 3
STEP 2:
	search in the 3rd index,if element not found repeat step1
	(5 7 9 11) if the array had been similar to this one,then we'd have gotten the right answer
	
	11-9 ==>2/2 ==> 1
STEP 3:
	now we got 10,so repeat step 1
	11-10 ==> 1/2 ==>0
	so now we know we cant be in the same index ,therefore we need to take atleast one step
STEP 4:

	now we got 11 ,so return the answer which is 5


we have done only 4 comparisons by virtue of this soln ,had it been the normal linear search,it would have been 6 comparisons
	




static int search(int arr[], int n,
                            int x, int k)
    {
         
        			// Traverse the given array starting
        			// from leftmost element
        int i = 0;
         
        while (i < n) {
             
            			// If x is found at index i
            if (arr[i] == x)
                return i;
 
           			// Jump the difference between
            			// current array element and x
            			// divided by k We use max here
            			// to make sure that i moves
            			// at-least one step ahead.
            i = i + Math.max(1, Math.abs(arr[i]
                                      - x) / k);
        }
 
        System.out.println("number is " +
                                "not present!");
        return -1;
    }