Minimum Swaps for Bracket Balancing 

LINK:https://www.youtube.com/watch?v=Ylz6mwghDrU

You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.

MEHTOD-1
TIME:O(N)
SPACE:O(N)

USING A VECTOR TO STORE THE INDICES OF THE OPEN BRACKETS


long swapCount(string s)
{
    // Keep track of '['
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);
 
    int count = 0; // To count number of encountered '['
    int p = 0;  // To track position of next '[' in pos
    long sum = 0; // To store result
 
    for (int i = 0; i < s.length(); ++i)
    {
        // Increment count and move p to next position
        if (s[i] == '[')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
            --count;
 
        // We have encountered an unbalanced part of string
        if (count < 0)
        {
            // Increment sum by number of swaps required
            // i.e. position of next '[' - current position
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;
 
            // Reset count to 1
            count = 1;
        }
    }
    return sum;
}





METHOD-2

WITHOUT A VECTOR
TIME:O(N)
SPACE:O(1)

int minimumNumberOfSwaps(string S){
        // code here 
        
       int swap=0;
       int open=0,close=0,fault=0;
       for(int i=0;i<S.length();i++)
       {
           if(S[i]==']')
           {
               close++;
               fault=close-open;
               
               
           }else{
               
               open++;
               if(fault>0)
               {
                   swap+=fault;
                   fault--;
                   
               }
               
           }
           
           
           
       }
      
       
       return swap;
    }
       

