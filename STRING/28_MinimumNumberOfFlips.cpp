Min Number of Flips 

Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

Example 1:

Input:
S = "001"	-->101  // -->010
Output: 1
Explanation: We can flip the 0th bit to 1
to have "101".
â€‹Example 2:

Input: 
S = "0001010111"
Output: 2
Explanation: We can flip the 1st and 8th bit
to have "0101010101".



LOGIC:
1.we know that the chars should be alternative,so with that being said we know how the string should look like
for example,if it starts with 0,then  --> 01010101010
	    if it starts with 1,then  --> 10101010101

2. so we ourself make two expected string one starting with 0 and the other with 1
3.we will use a counter which we can increment only if the character doesnt match with our expected char,so we do the same for the two strings
4.the minimum value of the counter of the two expected strings is the answer

----------------------------------------------------------------------



char flip(int ch)
{
    if(ch=='0')
    return '1';
    else
    return '0';
}

int checking(string S,char expected)

{
    int cnt=0;
    				// your code here
    for(int i=0;i<S.length();i++)
    {
        if(S[i]!=expected)
        cnt++;
        
        expected=flip(expected);
        
    }
    return cnt;
    
}
int minFlips (string S)
{
    int ans=0;
   ans= min(checking(S,'0'),checking(S,'1'));
    
    return ans;
}

----------------------------------------------------



int minFlips (string S)
{
    // your code here
    string s1="",s2="";
    int ans=0;
    char a='0',b='1';
    for(int i=0;i<S.length();i++)
    {
        s1+=a;
        s2+=b;
        swap(a,b);
        
    }
    int count1=0,count2=0,maxi;
    for(int i=0;i<S.length();i++){
        
        if(s1[i]!=S[i])
        count1++;
        if(s2[i]!=S[i])
        count2++;
        
    }
    maxi=min(count1,count2);
    return maxi;
}