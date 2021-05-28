Rearrange characters in a string such that no two adjacent are same

LINK:https://www.youtube.com/watch?v=sSDAN_WwNwU

Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.
Examples: 
 

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible

TIME:O(N)
SPACE:O(26)
USING COUNT ARRAY

LOGIC:

1.create a count array which will have the frequency of the chars
2.we will start to place the chars in the even index and then once the even places got over,you
can start with the odd index,so this way you can prevent the adjacent position of the same chars
3.so first we will start with the char which has the maximum frequency (for this we will create a 
separate function,which will return the char with max frequency)
4.We need to make sure that we can create a valid string by this method,so we need to check whether
the char's frequency is less than half of the total string length,in this way only it is possible
to create our resultant string
i.e) ch>(n+1)/2  -->false (u can not create a valid string)

5.you dont need to call the max frequency function many times,once calling is enough




CODE:

char getMaxCountChar(const vector<int>& count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
 
    return ch;
}
 
string rearrangeString(string S)
{
 
    int n = S.size();
    if (!n)
        return "";
 
    vector<int> count(26, 0);
    for (auto ch : S)
        count[ch - 'a']++;
 
    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];
 
    // check if the result is possible or not
    if (maxCount > (n + 1) / 2)
        return "";
 
    string res(n,' ');  //declaring an empty string of size n
 
    int ind = 0;
    // filling the most frequently occuring char in the even
    // indices
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;
 
    // now filling the other Chars, first filling the even
    // positions and then the odd positions
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
}
 
// Driver program to test above function
int main()
{
    string str = "bbbaa";
    string res = rearrangeString(str);
    if (res == "")
        cout << "Not valid string" << endl;
    else
        cout << res << endl;
    return 0;
}