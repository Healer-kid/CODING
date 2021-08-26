Smallest distinct window 

Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"


METHOD-1
BRUTE FORCE
TIME:O(N^3)
SPACE:O(N)

LOGIC:

1.generate all the possible string with the help of 2 pointers say i and j
2.we will create a function which will return the  no of distinct chars in the current string 
3.now we will check if the current string's no. of  distinct char== no. of distinct char of the total string  && if the length of the current string is also less than the total length 
then we will update the answer


#define NO_OF_CHARS 256
 
// Find maximum distinct characters in any string
int max_distinct_char(string str, int n){
 
   
    int count[NO_OF_CHARS] = {0};
     
   
    for (int i = 0; i < n;  i++)
        count[str[i]]++;
     
    int max_distinct = 0;
    for (int i = 0; i < NO_OF_CHARS;  i++)
        if (count[i] != 0)     
            max_distinct++;    
     
    return max_distinct;
}
 
int smallesteSubstr_maxDistictChar(string str){
 
    int n = str.size();     
	string finsub="";
 
    // Find maximum distinct characters in any string
    int max_distinct = max_distinct_char(str, n);
    int minl = n;   // result
     
    // Brute force approach to find all substrings
    for (int i=0 ;i<n ;i++){
        for (int j=0; j<n; j++){

            string subs =  str.substr(i,j);
            int subs_lenght = subs.size();

            int sub_distinct_char = max_distinct_char(subs, subs_lenght);
             
           
            if (subs_lenght < minl && max_distinct == sub_distinct_char){
                minl = subs_lenght;
		finsub=subs;
            }
        }
    }
    return minl;
}





TIME:O(N)
SPACE:O(N)

LOGIC:

SIMILAR TO SLIDING WINDOW

1.first we will create a substring and then once it has all the distinct characters,we will start to 
remove them from the start if that char is present in the current window more than once

2.so every time ,we will check for the string which has all the distinct chars
i.e)
currentcount==distcount
then we will repeat the step 1




 string findSubString(string str)
    {
        // Your code goes here  
        int distcount=0,ans=str.length(),windowlen=0,finstart=0;
        vector<int> v(256,0);

        for(int i=0;i<str.length();i++)
        {
            if(v[str[i]]==0)
            {v[str[i]]=1;
                distcount++;
            }
        }


        int start=0,count=0;
        vector<int> currentcount(256,0);
        for(int i=0;i<str.length();i++)
        {
            currentcount[str[i]]++;
            
            if(currentcount[str[i]]==1)
            {
                
               count++;
            
            }
            
            if(count==distcount)
            {
                
                while(currentcount[str[start]]>1)
                {
                   
                    if(currentcount[str[start]]>1)
                     currentcount[str[start]]--;
                     start++;
                    
                }
                
                windowlen=i-start+1;
                
                if(ans>windowlen){
                ans=windowlen;
               finstart=start;
                
                }
                
            }
        }
               
        
        return str.substr(finstart,ans);
               
        
            }
};