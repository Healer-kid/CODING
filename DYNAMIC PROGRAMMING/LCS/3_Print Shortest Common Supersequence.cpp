Printing Shortest Common Supersequence

Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.
Examples: 
 

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y


--------------------------------------------
------------------>create LCS table then start with this//

 string str;
 
   
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
       
        if (X[i - 1] == Y[j - 1])
        {
           
            str.push_back(X[i - 1]);
 
            i--, j--;
        }
 
       
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            
            str.push_back(Y[j - 1]);
 
          
            j--;
        }
        else
        {
           
            str.push_back(X[i - 1]);
 
           
            i--;
        }
    }
 
    while (i > 0)
    {
        str.push_back(X[i - 1]);
        i--;
    }
 
    
    while (j > 0)
    {
        str.push_back(Y[j - 1]);
        j--;
    }
 
   
    reverse(str.begin(), str.end());
    return str;
}