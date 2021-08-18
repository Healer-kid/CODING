Job Sequencing Problem 
Medium Accuracy: 48.94% Submissions: 38692 Points: 4
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).




class Solution 
{
    public:
    static int sortbysec(pair<int,int> a,pair<int,int> b){
        
      
        return a.second>b.second;
        
      
        
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            int a=arr[i].dead,b=arr[i].profit;
            v.push_back(make_pair(a,b));
            
            
    }
    
    
    sort(v.begin(),v.end(),sortbysec);
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    
    int count=0,profit=0;
    for(int i=0;i<n;i++){
        
        for(int j=min(n,v[i].first)-1;j>=0;j--){
            
            if(dp[j]!=-1){
                count++;
                profit+=v[i].second;
                dp[j]=-1;
                break;
            }
            
        }
        
    }
    
    
    vector<int> s;
    s.push_back(count);
    s.push_back(profit);
    return s;
        
    } 
};
