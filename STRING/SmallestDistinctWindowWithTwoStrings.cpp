Smallest window in a string containing all the characters of another string 

Given two strings S and P. Find the smallest window in the S consisting of all the characters of P.

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.

In case there are multiple such windows of same length, return the one with the least starting index. Return "-1" in case ther


METHOD-1
SIMILAR TO SMALLEST DISTINCT WINDOW BUT WITH TWO STRINGS

LOGIC:
1.First check if the length of the string is less than the length of the given pattern, if yes then “no such window can exist “.
2.Store the occurrence of characters of the given pattern in a hash_pat[].
3.we will be using two pointer technique basically
4.Start matching the characters of pattern with the characters of string i.e. increment count if a character matches.
5.Check if (count == length of pattern ) this means a window is found.
6.If such a window found, try to minimize it by removing extra characters from the beginning of the current window.
7.delete one character from first and again find this deleted key at right, once found apply step 5 
8.Update min_length.
9.Print the minimum length window.




public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
	vector<int> pat(256,0);
	vector<int> text(256,0);
	int count=0,start=0,winlen=0,minl=INT_MAX,flag=0;
	string temp="";
    if(s.length()<p.length())
        return "-1";
      for(int i=0;i<p.length();i++)
        {
            
           pat[p[i]]++; 
            
        }
       
        for(int j=0;j<s.length();j++)
        {
            
            text[s[j]]++;
            if(text[s[j]]<=pat[s[j]])
            count++;
            
            
            if(count==p.length())
            {
                 flag=1;
                while(text[s[start]]>pat[s[start]]||pat[s[start]]==0 )
                {
                    if(text[s[start]]>pat[s[start]])
                    text[s[start]]--;
                    
                    start++;
                }
                
                winlen=j-start+1;
                if(minl>winlen)
                {
                    minl=winlen;
                    temp=s.substr(start,minl);
                   
                    
                }              
                
            }           
                      
            
        }
        
        
        if(flag)
        
       return temp; 
        
       else
           return "-1";
        
        
        
    }
};