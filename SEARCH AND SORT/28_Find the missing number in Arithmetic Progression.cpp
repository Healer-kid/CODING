Find the missing number in Arithmetic Progression

Given an array that represents elements of arithmetic progression in order. One element is missing in the progression, find the missing number. 
Examples: 
 

Input: arr[]  = {2, 4, 8, 10, 12, 14}
Output: 6

Input: arr[]  = {1, 6, 11, 16, 21, 31};
Output: 26
 

TIME:O(LOGN)
SPACE:O(1)





public:int findMissingUtil(int arr[], int low,
                           int high, int diff)
{
    // There must be two elements to find the missing
    if (high <= low)
        return INT_MAX;
 
    
    int mid = low + (high - low) / 2;
 
    if (arr[mid + 1] - arr[mid] != diff)
        return (arr[mid] + diff);
 
   
    if (mid > 0 && arr[mid] - arr[mid - 1] != diff)
        return (arr[mid - 1] + diff);
 
   						 // If the elements till mid follow AP, then recur
   						 // for right half
   

    if (arr[mid] == arr[0] + mid * diff)	//WHY MID AND NOT MID-1?
        return findMissingUtil(arr, mid + 1,
                               high, diff);
 
    						// Else recur for left half
    return findMissingUtil(arr, low, mid - 1, diff);
}


-------------------------------------------------------------------------------------


GFG PRACTICE QUESTION

Arithmetic Number 

Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference of an arithmetic sequence and an integer 'B'. you need to tell whether 'B' exists in the arithmetic sequence or not.

Example 1:

Input: A = 1, B = 3, C = 2
Output: 1
Explaination: 3 is the second term of the 
sequence starting with 1 and having a common 
difference 2.
Example 2:

Input: A = 1, B = 2, C = 3
Output: 0
Explaination: 2 is not present in the sequence.
Your Task:


 int inSequence(int A, int B, int C){
       
        
        if (!C) return A == B ;


	int res = (B - A) / C ;
	return (B - A) % C == 0 and res >= 0;    //why 0 and not 1? Ans: 10 10 42 (check out this testcase) sometimes A and B can be one and the same
        
        
    }
};




















