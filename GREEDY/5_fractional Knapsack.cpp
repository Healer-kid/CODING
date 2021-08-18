Fractional Knapsack 
Medium Accuracy: 45.14% Submissions: 38570 Points: 4
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
-------------- 


double fractionalKnapsack(int W, Item arr[], int n)
    {
        
        vector<pair<double,int>> v;
        for(int i=0;i<n;i++){
            double x=arr[i].value*1.0/arr[i].weight*1.0;
            v.push_back(make_pair(x,i));
            
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        double wt=0,profit=0;
        for(int i=0;i<n;i++)
        {
            if(wt+arr[v[i].second].weight<W){
                profit+=arr[v[i].second].value;
                wt+=arr[v[i].second].weight;
                
            }
            else{
                
                double p=W-wt;
                profit+=p*v[i].first;
                break;
                
                
            }
            
        }
        return profit;
    }
        