Median in a row-wise sorted Matrix 

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

METHOD-1
USING SORTING AND AN AUXILLARY ARRAY
TIME:O(R*C LOG(R*C)),SPACE:O(R*C)

 int median(vector<vector<int>> &matrix, int r, int c){
        // code here     
        vector<int> v;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            v.push_back(matrix[i][j]);
            
        }
        
        sort(v.begin(),v.end());
        int n=v.size();
     
     return v[n/2]; //since always odd
    }





METHOD-2
USING BINARY SEARCH
TIME:O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 

LOGIC:
1.find the range of the matrix,that is find the min and max element
2.the average of the minimum and maximum gives us the assumed middle/median element
3.check whether there exists half of the elements less than the assumed middle element
if so,then the assumed is the real median
4.Else,if the count is less, the assumed element is not the perfect fit,so increment the median
  and check
5.if the count is greater,then make it as the bound ,that is we will narrow down our search 
less than previous assumed median

6.even if the count is equal,still we will search for the element,cause that is an assumed median ,we need to make sure that exists in the current array
 





int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
       
        if (m[i][0] < min)
            min = m[i][0];
  
        
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
  
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
  
        // Find count of elements smaller than or equal to mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}