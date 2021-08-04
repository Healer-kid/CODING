Write an efficient program to print all the duplicates and their counts in the input string 


unordered_map<char,int> mp;
for(int i=0;i<str.length();i++)
{
	mp[str[i]]++;	

}
for(auto i:mp)
{
	if(i.second>1)
	cout<<i.first;
}