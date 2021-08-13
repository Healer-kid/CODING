CREATE THE LCS TABLE AND THEN USE IT 

int i = m, j = n;
   while (i > 0 && j > 0)
   {
      
      if (X[i-1] == Y[j-1])
      {
          s.push_back(X[i-1]);
          i--; j--;   
      }
  
     
      // go in the direction of larger value

      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }