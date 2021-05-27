LINK:https://www.youtube.com/watch?v=ZYeVllg0D7E

Count of number of given string in 2D character array
Difficulty Level : Medium
Last Updated : 14 Apr, 2021
Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array such that individual characters can be present left to right, right to left, top to down or down to top.

Examples: 

Input : a ={
            {D,D,D,G,D,D},
            {B,B,D,E,B,S},
            {B,S,K,E,B,K},
            {D,D,D,D,D,E},
            {D,D,D,D,D,E},
            {D,D,D,D,D,G}
           }
        str= "GEEKS"
Output :2

Input : a = {
            {B,B,M,B,B,B},
            {C,B,A,B,B,B},
            {I,B,G,B,B,B},
            {G,B,I,B,B,B},
            {A,B,C,B,B,B},
            {M,C,I,G,A,M}
            }
        str= "MAGIC"

Output :4
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
We have discussed simpler problem to find if a word exists or not in a matrix.
To count all occurrences, we follow simple brute force approach. Traverse through each character of the matrix and taking each character as start of the string to be found, try to search in all the possible directions. Whenever, a word is found, increase the count, and after traversing the matrix what ever will be the value of count will be number of times string exists in character matrix.

Algorithm : 
1- Traverse matrix character by character and take one character as string start 
2- For each character find the string in all the four directions recursively 
3- If a string found, we increase the count 
4- When we are done with one character as start, we repeat the same process for the next character 
5- Calculate the sum of count for each character 
6- Final count will be the answer





solve(int i,int j,char ch[6][6],int size,int idx)
{
	int found=0;
	if(i>=0 and j>=0 and i<6 and j<6 and s[idx]==ch[i][j])
	{
		int temp=ch[i][j];
		idx+=1;
		ch[i][j]=0;	//making it 0 so it wont be included in the same string

		if(idx==size)   //1 pattern found
		found=1
		else
		{
			found+=solve(i+1,j,ch,size,idx); //move down
			found+=solve(i-1,j,ch,size,idx); //move top
			found+=solve(i,j+1,ch,size,idx); //move right
			found+=solve(i,j-1,ch,size,idx); //move left
							
		

		}

		ch[i][j]=temp;//backtrack ,replacing the zero with the char which it had before

	}
return found;

}

main(){

ans=0;
int size=5;//geeks
for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
		ans+=solve(i,j,s,ch,size,0)


return ans;


}





