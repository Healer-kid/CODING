Minimum characters to be added at front to make string palindrome


Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
Examples: 
 

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.
 

METHOD-1
NAIVE APPROACH
TIME:O(N^2)

LOGIC:
we will check for palindrome by deleting each character from the end of the string
since we have to add the character to the front,we will delete it from the end



#include<bits/stdc++.h>
using namespace std;
int ispalindrome(string s)
{
   int left=0,right=s.length()-1;
    while(left<right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
            
        }else
        return 0;
        
    }
    return 1;
}

int main(){
    
    string str;
    cin>>str;
    int flag=0,count=0;
    while(str.length()>0)
    {
        if(ispalindrome(str))
        {
            flag=1;
            break;
        }
        else{
            count++;
            str.erase(str.begin()+str.length()-1);
            
        }
        
        
    }
    if(flag)
    cout<<count;
    return 0;
}









METHOD-2
USING KMP ALGORITHM'S LPS ARRAY
TIME:O(N)

LOGIC:

1) we have to alter the string
similiar to this and we will calculate the lps array

2) the length of the original string minus the last value in the lps array is the answer

REFER NOTE FOR FURTHER DETAILS



For string = AACECAAAA
Concatenated String = AACECAAAA$AAAACECAA
LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 
                   0, 1, 2, 2, 2, 3, 4, 5, 6, 7}

CODE:


vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);
 
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
// Method returns minimum character to be added at
// front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
 
    // Get concatenation of string, special character
    // and reverse string
    string concat = str + "$" + revStr;
 
    //  Get LPS array of this concatenated string
    vector<int> lps = computeLPSArray(concat);
 
    // By subtracting last entry of lps vector from
    // string length, we will get our result
    return (str.length() - lps.back());
}
 
// Driver program to test above functions
int main()
{
    string str = "AACECAAAA";
    cout << getMinCharToAddedToMakeStringPalin(str);
    return 0;
}



 


