Split the binary string into substrings with equal number of 0s and 1s

Given a binary string str of length N, the task is to find the maximum count of substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.

Example:

Input: str = “0100110101”
Output: 4
The required substrings are “01”, “0011”, “01” and “01”.

Input: str = “0111100010”
Output: 3


TIME:O(N)
LOGIC:
1)use two variable to keep track of the no of zeros and no of ones and increment the count if they both are equal at any instance.
2) if the no of zeros and the no of ones are not equal in the given string then return -1

int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            cnt++;
        }
    }
  
    // It is not possible to
    // split the string
    if (count0 != count1) {
        return -1;
    }
  
    return cnt;








