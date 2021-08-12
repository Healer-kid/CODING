SUBSET SUM--> returns true if sum is present

NOTE
-----------
COUNT THE NUMBER OF SUBSET SUM EQUAL TO SUM,THEN IN PLACE OF OR USE '+'




bool solve1(vector<int> A,int sum,int n){

if(n==0 and sum==0)
return true;

if(sum==0)
return true;

if(n==0 and sum!=0)
return false;

if(A[n-1]>sum)
return solve1(A,sum,n-1);

return solve1(A,sum,n-1) or solve1(A,sum-A[n-1],n-1);



}



----------------------------
MEMOIZATION
---------------



int dp[102][100002];
bool solve1(vector<int> A,int sum,int n){

if(n==0 and sum==0)
return 1;

if(sum==0)
return 1;

if(n==0 and sum!=0)
return 0;

if(dp[n][sum]!=-1)
return dp[n][sum];

if(A[n-1]>sum)
return dp[n][sum]=solve1(A,sum,n-1);

return dp[n][sum]=solve1(A,sum,n-1) or solve1(A,sum-A[n-1],n-1);



}

-----------------------------

TABULATION
---------------------

int Solution::solve(vector<int> &A, int B) {

int n=A.size();
int dp[n+1][B+1];    
        for(int i=0;i<n+1;i++){
            for(int j=0;j<B+1;j++){
                    if(i==0 and j==0)
                    dp[i][j]=1;
                    else if(j==0)
                    dp[i][j]=1;
                    else if(i==0)
                    dp[i][j]=0;
                    else if(A[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                    else{

                        dp[i][j]=(dp[i-1][j] or dp[i-1][j-A[i-1]]);
                    }


            }


        }

return dp[n][B];

}

