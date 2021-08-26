Isomorphic Strings 
LINK:https://www.youtube.com/watch?v=TsTuKNA2K2k

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different
charactersin aab and xxy, i.e a and b
with frequency 2and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output:
Explanation: There are two different
charactersin aab but there are three
different charactersin xyz. So there
won't be one to one mapping between
str1 and str2.

UNDERSTANDING THE QUESTION:

in all the occurence of a,it should be replaced by a single char and so on
eg)
			abaaba
			xyxxyx
replace a with x
replace b with y
they are isomorphic to each other



LOGIC:
1.use two array in which if  its the first occurence for both char ,then 
make them as map/match/pair
eg) 
			abaaba
			xyxxyx


	m1		m2
	
       a:x	       x:a
       b:y	       y:x
2) check whether the two chars have already matched ,else return false


TIME:O(str1.length())
SPACE:O(256)



 //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
      
       int m1[256]={0};
       int m2[256]={0};
        			//cant use char since you cant fill the empty space with a char
        			//but in int ,you can use zero
        if(str1.length()!=str2.length())
        return false;
        
        for(int i=0;i<str1.length();i++)
        {
            if(!m1[str1[i]] and !m2[str2[i]])
            {
                m1[str1[i]]=str2[i];		//only the hashed value (ascii)is stored and not the char
                m2[str2[i]]=str1[i];
            }else if(m1[str1[i]]!=(int)str2[i])//it works even without int conversion
            {
                return false;
                
            }
            
        }
        return true;
    }