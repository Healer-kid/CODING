anagram
a word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp.

Print Anagrams Together 

Medium Accuracy: 59.05% Submissions: 10018 Points: 4
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array.
Look at the sample case for clarification.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output: 
no on
is
Explanation:
There are 2 groups of
anagrams "no", "on" make group 1.
"is" makes group 2. 




USING HASHMAP

Time Complexity: O(n * m(log m)),  where m is the length of a word.
A single traversal through the array is needed.
Space Complexity: O(n). 
There are n words in a string. The map requires O(n) space to store the strings.

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    
    
    unordered_map <string, vector<string>> mp;

 	for(auto x : string_list) {
		string temp = x;
		sort(x.begin(), x.end());
		mp[x].push_back(temp);
	}
	vector<vector<string>> v;
		for(auto x : mp) {
		v.push_back(x.second);
		}
	return v;
}

