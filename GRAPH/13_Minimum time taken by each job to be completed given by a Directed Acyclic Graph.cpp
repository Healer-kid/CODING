Minimum time taken by each job to be completed given by a Directed Acyclic Graph
Difficulty Level : Medium
Last Updated : 03 Jul, 2021
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

Examples:

Input: N = 10, E = 13, Below is the given graph:



Output: 1 1 2 2 2 3 4 5 2 6  
Explanation:
Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time. 
Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly, 
Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.



Input: N = 7, E = 7, Below is the given graph:



Output: 1 2 3 3 3 4 4  
Explanation:
Start the Job 1 at the beginning and complete it at 1st unit of time.
The job 2 can only be done after 1st Job is done. So, start it at 1st unit of time and complete it at 2nd unit of time.
Since, Job 3, 4, and 5 have the only dependency on 2nd Job. So, start these jobs at 2nd unit of time and complete these at 3rd unit of time.
The Job 6 can only be done after the 3rd and 4th Job is done. So, start it at 3rd unit of time and complete it at 4th unit of time.
The Job 7 can only be done after the 5th Job is done. So, start it at 3rd hour and complete it at 4th unit of time.



void addEdge(int u, int v)
{
    // Insert edge from u to v
    graph[u].push_back(v);
 
    indegree[v]++;
}
 

void printOrder(int n, int m)
{
    queue<int> q;
 
   
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            job[i] = 1;
        }
    }
 
   
    while (!q.empty()) {
 
     
        int cur = q.front();
       
        q.pop();
 
        for (int adj : graph[cur]) {
 
            indegree[adj]--;
 
            
            if (indegree[adj] == 0) {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }
 
}
 