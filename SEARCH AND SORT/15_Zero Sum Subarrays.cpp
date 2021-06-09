Zero Sum Subarrays 

You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]



LOGIC:

1.we know that if we get a subarray of same sum (which has occured before)
there is a subarray of sum zero
2.using this we can find the zero subarray
3.NOTE: we need to store '0' as a key in the hashmap initially ,since if the subarray sum becomes zero,we will check for the same sum right
so we are including zero in the hashmap



CODE:


class Solution{
    public:
    
    ll findSubarray(vector<ll> arr, int n ) {
      
        ll sum = 0;
	unordered_map<int, int>mp;
	mp[0] = 1;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp += arr[i];
		if (mp.find(temp) != mp.end()) {
			sum += mp[temp];
			mp[temp]++;
		}
		else {
			mp[temp]++;
		}
	}
	return sum;
    }
};