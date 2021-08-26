Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.



METHOD-1
---------------------
DFS WITH PRUNING ------------->TIME LIMIT EXCEEDED
--------------------------
void dfs(vector<vector<int>>& graph, vector<vector<int>>& cost, int src, int dst, int k, int& mini, int dist) {
        if(k < 0) {
            return;
        }
        if(src == dst) {
            mini = min(mini, dist);
            return;
        }
        for(auto i: graph[src]) {
            if(dist + cost[src][i] < mini) {  // Pruning step
                dfs(graph, cost, i, dst, k-1, mini, dist+cost[src][i]);   
            }
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> graph(n), cost(n, vector<int>(n));
        for(auto i: flights) {
            graph[i[0]].push_back(i[1]);
            cost[i[0]][i[1]] = i[2];
        }
        int mini = INT_MAX;
        dfs(graph, cost, src, dst, K+1, mini, 0);
        return mini == INT_MAX ? -1 : mini;
    }
};








