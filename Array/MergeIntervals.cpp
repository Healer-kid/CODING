Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

TIME:O(NLOGN) ,SPACE:O(N2) 


Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

IDEA:
 --> we can merge two intervals iff the second interval starts before the first one ends
 -->so sort them according to the beigning array and then merge if the first interval's end time > second interval's start time,if so proceed with whether we have to choose the first interval's end time/second interval's end time.


vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            
            if(output.back()[1] >= intervals[i][0])
        output.back()[1] = max(output.back()[1] , intervals[i][1]);
            else output.push_back(intervals[i]); 
        }
        return output; 
    }
};