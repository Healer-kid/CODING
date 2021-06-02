
NOTE:
Since square roots undo squaring, negative numbers can't have square roots.

Sqrt(x)

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1   (X WILL BE INTEGER ONLY)


METHOD-1
TIME:O(SQRT(N))

int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
    return x;
 
    // Staring from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}

METHOD-2
USING BINARY SEARCH
	-->TWO WAYS
	1)using long long to avoid overflow
	2)use division instead of multiplication


Time Complexity: O(logn)
Space Complexity: O(1) 


USING LONG LONG

 int mySqrt(int x) {
      long long s=0, e=x/2, ans, mid; 
        if(x==0 || x==1)
            return x;
        while(s<=e){             
            mid=(s+e)/2;
               
            if(mid*mid<=x){             
                s=mid+1;       
                ans=mid;       
            }
            else e=mid-1;        
        }
        return ans;   

    }
};

USING DIVISION

class Solution {
public:
    int mySqrt(int x) {
       
        if(x==0 || x==1)
            return x;
        int low = 1, high = x/2,result = -1;
        while(low<=high){
            
            int mid = low+(high-low)/2;
            
            if(mid<=x/mid){
                
                result = mid;
                low = mid+1;
                
            }else{
                high = mid-1;
            }
        }
        return result;
    }  
};


NOTE:

INT CAN HOLD ONLY UPTO [-2147483648 to 2147483647]
SO IF YOU USE INT
it will fail for this test case
2147395599

CAUSE:
signed integer overflow: 536848899 * 536848899 cannot be represented in type 'int' (solution.cpp)






