
Longest Palindromic Substring

Given a string, find the longest substring which is palindrome. 
For Example: 
 

Input: Given string :"forgeeksskeegfor", 
Output: "geeksskeeg".

Input: Given string :"Geeks", 
Output: "ee".



METHOD-1

BRUTE FORCE APPROACH

TIME:O(N^3)
LOGIC:
i and j will be the start and end of a particular string and the inner most loop will check 
for palindrome



int n = str.size();
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1, start = 0;
 
    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int flag = 1;
 
            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;
 
            // Palindrome
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
 
    // return length of LPS
    return maxLength;
}

METHOD-2
USING DYNAMIC PROGRAMMING
TIME:O(N^2)
SPACE:O(N^2)

LOGIC:
The idea is to check whether the two chars are same ,if so the chars bw them should be a palindrome


int n=str.length();
	    int dp[n][n];
	    for(int i=0;i<n;i++)
	    dp[i][i]=1;
	    int right=0,left=0;
	    for(int len=2;len<=n;len++){
	        
	        for(int i=0;i<n-len+1;i++){
	            
	            int j=i+len-1;
	            if(str[i]==str[j] && (j-i<2||dp[i+1][j-1]==1))
	                dp[i][j]=1;
	            else
	            dp[i][j]=0;
	            if(dp[i][j]==1){
	                
	                if(j-i>right-left){
	                    left=i;
	                    right=j;
	                    
	                }
	                	                
	                
	                
	            }
	                
	                     
	            
	            
	        }
	        
	        
	        
	    }



METHOD-3

TIME:O(N^2)
SPACE:O(1)



The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.

To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes, i.e. fix i (index) as center and two indices as i1 = i+1 and i2 = i-1

Compare i1 and i2 if equal then decrease i2 and increase i1 and find the maximum length. 
Use a similar technique to find the even length palindrome.

Take two indices i1 = i and i2 = i-1 and compare characters at i1 and i2 and find the maximum length till all pair of compared characters are equal and store the maximum length.
Print the maximum length.



int maxLength = 1;
 
    int start = 0;
    int len = strlen(str);
 
    int low, high;
 
   			 // One by one consider every
    			// character as center point of
    			// even and length palindromes
    for (int i = 1; i < len; ++i) {
        			// Find the longest even length palindrome
        			// with center points as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        			// Find the longest odd length
        			// palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            if (high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
 
    return maxLength;
}
 










