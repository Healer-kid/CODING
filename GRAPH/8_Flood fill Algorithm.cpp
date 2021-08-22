Flood fill Algorithm 
Medium Accuracy: 65.5% Submissions: 12174 Points: 4
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
 





USING DFS
-------------


 void floodfill(int m,int n,int x,int y,int newColor, int oldColor,vector<vector<int>>& image){
        
       
       if(x>=0 and x<m and y>=0 and y<n and image[x][y]==oldColor and image[x][y]!=newColor){
        image[x][y]=newColor;
       
     	floodfill(m,n,x+1,y,newColor,oldColor,image);
     	floodfill(m,n,x-1,y,newColor,oldColor,image);  
        floodfill(m,n,x,y+1,newColor,oldColor,image);  
        floodfill(m,n,x,y-1,newColor,oldColor,image); 
        
        
       }
    }



    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // Code here 
        int m=image.size();
        int n=image[0].size();
        int oldColor=image[sr][sc];
        floodfill(m,n,sr,sc,newColor,oldColor,image);
        return image;
    }
};


----------------
NOTE:
---------------
 if(image[sr][sc] == newColor)
{
return image
}
this condition is necessary because otherwise there will be a stack overflow exception because we will repeatdely revisit the same pixel again and again. 
So, if our pixel is already newcolor we should ignore that and return because if we don't it will create a self loop.


--------------------------
USING BFS
-------------------

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int m=image.size(),n=image[0].size();  //using BFS
        queue<pair<int,int>> q;
        
        int val=image[sr][sc];
        
      q.push({sr,sc});
        while(!q.empty()){
            
            int x=q.front().first;
            int y=q.front().second;
            image[x][y]=newColor;
            q.pop();
        if(x>0 and image[x-1][y] == val and image[x-1][y]!=newColor)
        { image[x-1][y]=newColor; 				//we need to change the color here itself 
       								 //Common neighbours were getting pushed multiple times into 
       								 //the queue causing infinite loop.
        q.push({x-1,y});
            
        }
        if(y>0 and image[x][y-1] == val and image[x][y-1]!=newColor)
        {image[x][y-1]=newColor;q.push({x,y-1});
            
        }
        if(x<m-1 and image[x+1][y] == val and image[x+1][y]!=newColor)
        {image[x+1][y]=newColor; q.push({x+1,y});
            
        }
        if(y<n-1 and image[x][y+1] == val and image[x][y+1]!=newColor )
        {image[x][y+1]=newColor;q.push({x,y+1});
            
        }
            
            
            
            
            
            
        }
        
        
        return image;
        
        
    }
};