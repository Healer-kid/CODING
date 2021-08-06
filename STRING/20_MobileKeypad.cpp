Convert a sentence into its equivalent mobile numeric keypad sequence

Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 
 

Mobile-keypad

Examples : 
 

Input : GEEKSFORGEEKS
Output : 4333355777733366677743333557777
For obtaining a number, we need to press a
number corresponding to that character for 
number of times equal to position of the 
character. For example, for character C, 
we press number 2 three times and accordingly.

Input : HELLO WORLD
Output : 4433555555666096667775553




LOGIC:


1.create an array of strings,where each string denotes a letter,say "2" denotes "A"
"22" denotes "B"

string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };


2.each time subtract the ascii value of 'A' from the corresponding letter,so we will get the index

eg) for G
ascii value of G =71
ascii value of A =65
 
	71-65 =6
the no in the 6th index will be used for G and so on

3.for space ,use '0'


CODE:

string printSequence(string arr[],
                       string input)
{
    string output = "";
 
    			// length of input string
    int n = input.length();
    for (int i=0; i<n; i++)
    {
        		// Checking for space
        if (input[i] == ' ')
            output = output + "0";
 
        else
        {
            		// Calculating index for each
            		// character
            int position = input[i]-'A';
            output = output + arr[position];
        }
    }
 
    // Output sequence
    return output;
}
 
// Driver function
int main()
{
    // storing the sequence in array
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
 
    string input = "GEEKSFORGEEKS";
    cout << printSequence(str, input);
    return 0;
}




 
