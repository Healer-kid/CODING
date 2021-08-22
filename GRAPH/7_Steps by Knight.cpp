Steps by Knight 
Medium Accuracy: 50.11% Submissions: 27171 Points: 4
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

 


int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	   
	   int visited[N+1][N+1];
	   memset(visited,0,sizeof(visited));
	    int cx[8]={-2, -1, 1, 2, -2, -1, 1, 2};
	    int cy[8]={-1, -2, -2, -1, 1, 2, 2, 1};
	    
	    int dx=TargetPos[0]-1,dy=TargetPos[1]-1;
	    int h=KnightPos[0]-1,k=KnightPos[1]-1;
	    
	    
	    queue<pair<int,int>> q;
	   
	    q.push({h,k});
	    visited[h][k]=1;
	    
	    int steps=0;
	    while(!q.empty())
	    {
	        int siz=q.size();//NOTE ONLY THE LOOP SHOULD RUN THIS TIME
	       
	     for(int i=0;i<siz;i++){  
	         int x=q.front().first;
	         int y=q.front().second;
	         q.pop();
	         
	         if(x==dx and y==dy)
	         return steps;
	         
	        for(int i=0;i<8;i++)
	        {
	           int newx=x+cx[i];
	           int newy=y+cy[i];
	           if(newx>=0 and newy>=0 and newx<N and newy<N 
	           and visited[newx][newy]!=1)
	            visited[newx][newy]=1,q.push({newx,newy});
	            
	        }
	        
	        
	     }
	      steps++;
	        
	    }
	    
	    
	    return -1;
	    
	}
};