Search a Word in a 2D Grid of characters
Difficulty Level : Medium
Last Updated : 23 Mar, 2021
Given a 2D grid of characters and a word, find all occurrences of the given word in the grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonal directions.
Example: 

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0
Explanation: 'GEEKS' can be found as prefix of
1st 2 rows and suffix of first row

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: pattern found at 0, 2
        pattern found at 0, 10
        pattern found at 2, 2
        pattern found at 2, 12
Explanation: EEE can be found in first row 
twice at index 2 and index 10
and in second row at 2 and 12

TIME: O(R*C)






LOGIC : SIMILAR TO COUNTING THE STRINGS IN A 2D ARRAY (WORD SEARCH) 

but we can use all the 8 directions unlike the 4 options in word search
The idea used here is simple, we check every cell. If cell has first character, then we one by one try all 8 directions from that cell for a match. Implementation is interesting though. We use two arrays x[] and y[] to find next move in all 8 directions. 
Below are implementation of the same:





bool search2D(vector<vector<char>> grid, int row, int col, string word, vector<int>x, vector<int>y)
{
int R = grid.size();
int C = grid[0].size();

if (grid[row][col] != word[0])
return false;

int len = word.size();


	for (int dir = 0; dir < 8; dir++)
	{

		int k, rd = row + x[dir], cd = col + y[dir];

		// First character is already checked, match remaining
		// characters
	for (k = 1; k < len; k++)
	{

	if (rd >= R || rd < 0 || cd >= C || cd < 0)
	break;


	if (grid[rd][cd] != word[k])
	break;

				// Moving in particular direction
	rd += x[dir], cd += y[dir];
	}

// If all character matched, then value of must
// be equal to length of word
if (k == len)
return true;
}
return false;
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    
	    int row = grid.size();
        int col = grid[0].size();
        vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
        vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };
        vector<vector<int>>ans;
        for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(search2D(grid, i, j, word, x, y)){
            ans.push_back({i, j});
            }
        }
        }
return ans;
	}