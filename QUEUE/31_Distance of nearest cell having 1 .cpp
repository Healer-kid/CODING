Distance of nearest cell having 1 

Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
 



3 8
0 1 0 0 1 1 1 1
0 0 1 0 1 1 0 1
1 0 0 0 1 0 0 0

Its Correct output is:
1 0 1 1 0 0 0 0
1 1 0 1 0 0 1 0
0 1 1 1 0 1 2 1


vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row=grid.size();
	    int col=grid[0].size();
	    queue<pair<int,int>> q;
	    vector<vector<int>> ans(row,vector<int>(col,INT_MAX));
	    
	    for(int i=0;i<row;i++)
	    for(int j=0;j<col;j++)
	    {
	        
	       if(grid[i][j]==1)
	        {
	            q.push({i,j});
	            ans[i][j]=0;
	        }
	    }
	    
	    while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                int x = q.front().first ;
                int y = q.front().second ;
                q.pop();
                if(x>0 and ans[x-1][y] > ans[x][y]+1 ){ans[x-1][y] = ans[x][y]+1  ;  q.push({x-1,y});};
                if(y>0 and ans[x][y-1] >ans[x][y]+1 ){ans[x][y-1] = ans[x][y]+1  ;  q.push({x,y-1});};
                if(x<row-1 and ans[x+1][y] >ans[x][y]+1 ){ans[x+1][y] = ans[x][y]+1  ;  q.push({x+1,y});};
                if(y<col-1 and ans[x][y+1] >ans[x][y]+1 ){ans[x][y+1] = ans[x][y]+1  ;  q.push({x,y+1});};
            }
	    }
	    
	    
	    
	    
	    return ans;
	    
	    
	    
	    
	    
	    
	    
	    
	}

