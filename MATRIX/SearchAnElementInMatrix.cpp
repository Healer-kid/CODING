
Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false



bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(int i=0;i<matrix.size();i++)
       {   for(int j=0;j<matrix[0].size();j++)
               if(matrix[i][j]==target)
                    return true;
        
    }
 return false;   
}
    
};




METHOD-2
TIME:O(LOG M*N),SPACE:O(1)

Use binary search.
// treat the matrix as an array, just taking care of indices

if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
