Recursively print all sentences that can be formed from list of word lists

Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion? 
Example: 

Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink 





The idea is based on a simple depth-first traversal.
--> We start from every word of the first list as the first word of an output sentence,
 then recur for the remaining lists.
-->we can observe that the code is very close to the DFS of graph.


LOGIC:

we will use a 1d array to strore the output of each line
for example)
	you
	have
	sleep

will be in the array for the first time ,then once we print that ,we have to recur back
with the array having

	you 
	have

now we will add eat here,so now it will look like

 	you
	have
	eat
similarly everything will get filled
HOW DO YOU KNOW THE SIZE OF THE OUTPUT 2D ARRAY?
	it might be the number of rows ,since it will pick one word from each row

CODE:


// C++ program to print all possible sentences from a list of word list
#include <iostream>
#include <string>
 
#define R 3
#define C 3
using namespace std;
 
// A recursive function to print all possible sentences that can be formed
// from a list of word list
void printUtil(string arr[R][C], int m, int n, string output[R])
{
    // Add current word to output array
    output[m] = arr[m][n];
 
    // If this is last word of current output sentence, then print
    // the output sentence
    if (m==R-1)
    {
        for (int i=0; i<R; i++)
           cout << output[i] << " ";
        cout << endl;
        return;
    }
 
    // Recur for next row
    for (int i=0; i<C; i++)
       if (arr[m+1][i] != "")
          printUtil(arr, m+1, i, output);
}
 
// A wrapper over printUtil()
void print(string arr[R][C])
{
   // Create an array to store sentence
   string output[R];
 
   // Consider all words for first row as starting points and
   // print all sentences
   for (int i=0; i<C; i++)
     if (arr[0][i] != "")
        printUtil(arr, 0, i, output);
}
 
// Driver program to test above functions
int main()
{
   string arr[R][C]  = {{"you", "we"},			//RAGGED ARRAY (ARRAY WITH DIFFERENT LENGTH)
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
 
   print(arr);
 
   return 0;
}