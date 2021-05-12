Row with max 1s 

Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).	




METHOD-1
BRUTE FORCE
TIME:O(M*N)




int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxi=0,ind=-1;
	    for(int i=0;i<arr.size();i++){
	        int count=0;
	        for(int j=0;j<arr[0].size();j++)
	        {
	            if(arr[i][j]==1)
	            count++;
	            
	            
	            
	        }
	       if(count>maxi){
	        maxi=count;
	        ind=i;
	       }
	    }
	    
	    
	    
	    
	    
	    return ind;
	
}




METHOD-2
TIME:O(MLOGN)

LOGIC:
USING BINARY SEARCH ,FIND THE FIRST INDEX WHERE 1 OCCURS IN THE CURRENT ROW
then,find the difference bw the column length and the returned index,it will give the count of 1s in the current array

int first(bool arr[], int low, int high)
{
    if(high >= low)
    {
        
        int mid = low + (high - low)/2;
     
        // Check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
     
        
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);
         
      
        else
            return first(arr, low, (mid -1));
    }
    return -1;
}
 

int rowWithMax1s(bool mat[R][C])
{
    int max_row_index = 0, max = -1;
 
    
    int i, index;
    for (i = 0; i < R; i++)
    {
        index = first (mat[i], 0, C-1);
        if (index != -1 && C-index > max)
        {
            max = C - index;
            max_row_index = i;
        }
    }
 
    return max_row_index;
}


METHOD-3
TIME:O(MLOGN)

OPTIMISED APPROACH OF THE ABOVE METHOD
LOGIC:
instead of finding the count of 1s for all rows,its better if we find count only for those arrays which has maximum ones than the previous maximum

int rowWithMax1s(bool mat[R][C])
{
    int i, index;
 
    
    int max_row_index = 0;
    int max = first(mat[0], 0, C - 1);
 
    for (i = 1; i < R; i++)
    {
        
        if (max != -1 && mat[i][C - max - 1] == 1)
        {
            // Note the optimization here also
            index = first (mat[i], 0, C - max);
 
            if (index != -1 && C - index > max)
            {
                max = C - index;
                max_row_index = i;
            }
        }
        else
        {
            max = first(mat[i], 0, C - 1);
        }
    }
    return max_row_index;
}
    

METHOD-4

TIME:O(M+N)

LOGIC:
Step1: Get the index of first (or leftmost) 1 in the first row.
Step2: Do following for every row after the first row 
…IF the element on left of previous leftmost 1 is 0, ignore this row. 
…ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.

int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int max_row_index = 0;
 
    
    int j = first(mat[0], 0, C-1);
    if (j == -1) // if 1 is not present in first row
      j = C - 1;
 
    for (int i = 1; i < R; i++)
    {
        // Move left until a 0 is found
        while (j >= 0 && mat[i][j] == 1)
        {
           j = j-1;  // Update the index of leftmost 1 seen so far
           max_row_index = i;  // Update max_row_index
        }
    }
    return max_row_index;
}

