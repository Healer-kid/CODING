Find the number of islands 
Medium Accuracy: 38.66% Submissions: 81369 Points: 4
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 

class Solution
{
    public:
    void dfs(int i,int j,vector<vector<char>>& grid,int n,int m)
    {
        grid[i][j]='0';
        
        for(int a=-1;a<=1;a++){
            
            for(int b=-1;b<=1;b++){
                
                
                if(i+a>=0 and i+a<n and j+b>=0 and j+b<m and grid[i+a][j+b]=='1')
                dfs(i+a,j+b,grid,n,m);
                
            }
            
            
        }
        
        
        
        
        
    }
    
    
    
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
       int count=0;
        for(int i=0;i<grid.size();i++){
            
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'){
                    
                    dfs(i,j,grid,n,m);
                    count++;
                }
                
                
            }
            
            
        }
       return count; 
        
    }
};
