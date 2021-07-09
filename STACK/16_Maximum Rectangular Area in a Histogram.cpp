Maximum Rectangular Area in a Histogram 
Medium Accuracy: 47.42% Submissions: 28318 Points: 4
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.




int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int>left(n);
        stack<int>s;
        
        for(int i = 0 ; i < n ; i++){
            if(s.empty()){
                left[i] = 0 ;
            }else{
                while(!s.empty() and heights[s.top()] >= heights[i])
                    s.pop();
                left[i] = s.empty()? 0 : s.top()+1;
            }
            s.push(i); 
        }
        
        while(!s.empty())
            s.pop();
        
        vector<int>right(n);
        for(int i = n-1 ; i >= 0 ; i--){
            if(s.empty()){
                right[i] = n-1 ;
            }else{
                while(!s.empty() and heights[s.top()]>=heights[i])
                    s.pop();
                right[i] = s.empty()? n-1 : s.top()-1;
            }
            s.push(i);
        }
        
        int maxArea = 0 ;
        for(int i = 0 ; i < n ; i++){
            int currArea = heights[i] * (right[i] - left[i] + 1);
            maxArea = max(currArea,maxArea);
        }
        return maxArea ;
    }