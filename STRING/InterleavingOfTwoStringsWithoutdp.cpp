Interleaved Strings 

Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of A and B else returns false. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
Example 2:

Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.


WRONG ANSWER------------------------------

/*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        if(C.length()!=A.length()+B.length())
        return false;
        
        int i=0,j=0,k=0;
        while(k!=C.length())
        {
            if(i<A.length() && A[i]==C[k])
            i++;
            else if(j<B.length() && B[j]==C[k])
            j++;
            else
            return false;
            
            k++;
            
        }
        
       if(i<A.length() || j<B.length()) 
        return false;
        
        return true;
        
        
        
        
        
    }

};


Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
aab axy aaxaby

Its Correct output is:
1

And Your Code's output is:
0





CORRECT ANSWER----------------------------------


METHOD-2
USING RECURSION


 bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        if(!A.length()&&!B.length()&&!C.length())// Base Case: If all strings are empty
        return true;
        if(!C.length())// If C is empty and any of the
                       // two strings is not empty
        return false;
        bool x=(A.length()&&C[0]==A[0] && isInterleave(A.substr(1),B,C.substr(1)));
        bool y=(B.length()&&C[0]==B[0] && isInterleave(A,B.substr(1),C.substr(1)));
return x||y; 	// If any of the above mentioned
    		// two possibilities is true,
    		// then return true, otherwise false
     
        
          
        
        
    }