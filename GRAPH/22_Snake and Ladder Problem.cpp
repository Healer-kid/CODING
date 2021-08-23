Snake and Ladder Problem 
Medium Accuracy: 40.98% Submissions: 8311 Points: 4
Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).

You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder. The board looks like the following.


                                   

Example 1:

Input:
N = 8
arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 
       17, 4, 19, 7, 27, 1, 21, 9}
Output: 3
Explanation:
The given board is the board shown
in the figure. For the above board 
output will be 3. 
a) For 1st throw get a 2. 
b) For 2nd throw get a 6.
c) For 3rd throw get a 2.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minThrow() which takes N and arr as input parameters and returns the minimum number of throws required to reach the end of the game.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)




class Solution{
public:
    int minThrow(int N, int arr[]){
    
        
    int mat[31];
        for(int i=0;i<30;i++)
        {
            mat[i]=-1;
            
        }
        for(int i=0;i<2*N;i=i+2){
            
            mat[arr[i]-1]=arr[i+1]-1;
            
            
        }
        
        queue<int> q;
        int count=0;
        q.push(0);
        vector<int> vis(30,0);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++){
             
               int v=q.front();  
               q.pop(); 
               if(v==29)
               return count;
               
               vis[v]=1;
               for(int i=v+1;i<=v+6 and i<30;i++)
                {
                   if(!vis[i]) 
                    {
                        vis[i]=1;
                        if(mat[i]==-1)
                        q.push(i);
                        else
                        q.push(mat[i]);
                        
                        
                    }
                    
                }
                
                
            }
           count++;
        }
        
        
       return -1; 
        
        
        
    }
};
