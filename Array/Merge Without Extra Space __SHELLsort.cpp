Merge Without Extra Space 

Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Example 2:

Input:
N = 2, M = 3
arr1[] = {10, 12}
arr2[] = {5, 18, 20}
Output: 5 10 12 18 20
Explanation: Since you can't use any
extra space, modify the given arrays
to form 
arr1[] = {5, 10}
arr2[] = {12, 18, 20}
 

METHOD- USING SHELL SORT
shell sort is a modification of insertion sort,where we will increment by one,here we will get to use gaps to increment
TIME:O(N^2)	-->USED ONLY FOR REDUCING SPACE //SO MERGE SORT IS PREFERRED OVER THIS FOR NORMAL SORTING SINCE ITS TIME COMPLEXITY IS O(NLOGN)



LOGIC:
1.everytime we will check ith element greater than i+gap'th element ,if yes we will swap else it will remain as it is
2.to calculate the gap
we will use (n+m)/2 for the first time.After that we will divide the gap by 2 every time
3.THREE CASES ARISE
	-->i as well as i+gap'th element is in the first array
	-->i is in the first array and i+gap'th is in the second array
	-->i as well as i+gap'th element is in the second array



CODE:


public:
	int nextGap(int gap) {
	    if (gap <= 1) return 0;
	    return (gap / 2) + (gap % 2);
	}
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i, j, gap = n + m;

	    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {		//TO USE ALL THE GAPS
	       

			

		 for (i = 0; i + gap < n; i++)				//TO CHECK ONLY FOR THE FIRST ARRAY (i as well as i+gap'th element is in the first array)
	            if (arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);


	        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)	// (i is in the first array and i+gap'th is in the second array)
	            if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);



	        if (j < m) {

	            for (j = 0; j + gap < m; j++)				//(i as well as i+gap'th element is in the second array)
	                if (arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
	        }
	    }
	}
};
