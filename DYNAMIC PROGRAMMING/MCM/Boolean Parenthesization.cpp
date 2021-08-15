Boolean Parenthesization 
Hard Accuracy: 49.75% Submissions: 19922 Points: 8
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.













int dp[205][205][2];
    int solve(string S,int i,int j,int istrue){
        
        if(i>j)
        return 0;
        if(i==j)
        {
            if(istrue==1)
            return S[i]=='T';
            else
            return S[i]=='F';
            
            
        }
        if(dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
        
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2){
            
            int lt,rt,lf,rf;
            if(dp[i][k-1][1]==-1){
              
              lt=solve(S,i,k-1,1);
              
            }else{   
             
              
              lt=dp[i][k-1][1];
            }
            
            
             if(dp[k+1][j][1]==-1){
              
             rt=solve(S,k+1,j,1);
              
              
            }else{   
             
            rt=dp[k+1][j][1];
            }
            
            
            
            if(dp[i][k-1][0]==-1){
               lf=solve(S,i,k-1,0);
             
            }else{   
             
             lf=dp[i][k-1][0];
              
            }
            
            
            
            if(dp[k+1][j][0]==-1){
                 rf=solve(S,k+1,j,0);
              
            
            }else{   
             
              rf=dp[k+1][j][0];
               
            }
            
           
            
            
            if(S[k]=='^')
            {
                
                if(istrue==1)
                ans+=lt*rf+lf*rt;
                else
                ans+=lt*rt+lf*rf;
                
                
                
            }
            else if(S[k]=='&')
            {
                if(istrue==1)
                ans+=lt*rt;
                else
                ans+=lf*rf+lt*rf+lf*rt;
                
                
                
            }else{
                
                if(istrue==1)
                ans+=lt*rt+lt*rf+lf*rt;
                else
                ans+=lf*rf;
                
                
                
            }
            dp[i][j][istrue] =ans%1003;
            
        }  
          
            
        
        
        
        return ans%1003;
        
        
    }



    int countWays(int N, string S){
        // code here
        int i=0,j=N-1;
        int istrue=1;
        memset(dp,-1,sizeof(dp));
       return solve(S,i,j,istrue)%1003;
        
        
        
    }
};