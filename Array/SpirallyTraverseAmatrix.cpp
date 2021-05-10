Spirally traversing a matrix 
Medium Accuracy: 48.39% Submissions: 32036 Points: 4
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10






vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> v;
       int firstcol=0,firstrow=0,lastrow=r-1,lastcol=c-1;
       while(firstcol<=lastcol && k<=lastrow){
           
           for(int i=firstcol;i<=lastcol;i++)
            {
                v.push_back(matrix[firstrow][i]);
                
            }           
           firstrow++;
           for(int i=firstrow;i<=lastrow;i++){
               v.push_back(matrix[i][lastcol]);
           }
           lastcol--;
           if(firstrow<=lastrow){
           for(int i=lastcol;i>=l;i--){
               v.push_back(matrix[lastrow][i]);
               
               
           }
           lastrow--;
           }
           if(firstcol<=lastcol){
           for(int i=lastrow;i>=firstrow;i--){
               v.push_back(matrix[i][firstcol]);
               
           }
           firstcol++;
           }
       }
        
        
        return v;
        
        
    }
};