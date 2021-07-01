Smallest factorial number 

Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).



class Solution
{
    public:
    
    
    int count(int i) {
        int c = 0;
            while(i) {
                c += i/5;
                i /= 5;
            }
    return c;
    }


int solve(int n,int l,int h) {


    if(l>h) return INT_MAX;
    int mid = (l+h)/2;
    int c = count(mid);
    if(c < n) return solve(n,mid+1,h);
    else return min(mid,solve(n,l,mid-1));

}
        int findNum(int n)
        {
                
        int h = 5 * n;
        int l = 1;
        int ans = solve(n,l,h);
        return ans;

        }
}