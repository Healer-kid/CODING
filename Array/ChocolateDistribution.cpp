Chocolate Distribution Problem 

Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum

QUESTION EXPLANATION:

(in short,find a subarray of size m ,such that the difference bw the min element of subarray and max element of subarray is minimum of all the other subarrays formed as such) 



Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.

Example 2:

Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between
maximum chocolates and minimum chocolates
is 4 - 2 = 2 by choosing following M packets :
{3, 2, 4}.

LOGIC:

1.Sort the given packets
2.Find the subarray of size m
3.find difference between last (maximum in case of sorted) and first (minimum in case of sorted) elements of subarray is minimum.
 
if (m == 0 || n == 0)
        return 0;
 
    sort(arr, arr + n);
 
    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;
 
  
    int min_diff = INT_MAX;
 
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}