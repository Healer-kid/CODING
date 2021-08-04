A Program to check if strings are rotations of each other or not

Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)


METHOD:
TIME:O(N)
USING CONCATENATION OF THE STRING
LOGIC:

1.check if the length of str2 is smaller/larger than the str1,then return false if small/large
2.create a temp variable with 2 times of the str1
3.Now check for str2

bool areRotations(string str1, string str2)
{
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length())
        return false;
  
   string temp = str1 + str1; 
  return (temp.find(str2) != string::npos);
}
  