https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

RABIN KARP ALGORITHM
Rabin-Karp Algorithm for Pattern Searching

 
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.
Examples: 

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
pattern-searching

--> unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text,

--> if the hash values match then only it starts matching individual characters.

--> So Rabin Karp algorithm needs to calculate hash values for following strings.
1) Pattern itself. 
2) All the substrings of the text of length m. 



While calculating hash value ,we need to make it efficient by using a method similar to sliding window 

for eg)


This is simple mathematics, we compute decimal value of current window from previous window. 
For example pattern length is 3 and string is “23456” 
You compute the value of first window (which is “234”) as 234. 
How how will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.



WHAT IS HASHING HERE AND WHY WE USE IT?

Hashing is the transformation of a string of characters into a usually shorter fixed-length value or key that represents the original string. Hashing is used to index and retrieve items in a database because it is faster to find the item using the shorter hashed key than to find it using the original value.


If you were to look at the file as a computer looks at it, you would find that each byte contains not a letter but a number -- the number is the ASCII code corresponding to the character (see below). So on disk, the numbers for the file look like this:

 F   o   u   r     a   n   d      s   e   v   e   n
70 111 117 114 32 97 110 100 32 115 101 118 101 110



LOGIC:
1.calcualte the hash value for the first window both(pattern,text)
2.start calculating for the rest of the windows
3.make sure it lies as a positive value 



CODE:


// d is the number of characters in the input alphabet 
#define d 256 
  
/* pat -> pattern 
    txt -> text 
    q -> A prime number 
*/
void search(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 
  
   			 // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 
  
    		// Calculate the hash value of pattern and first 
    		// window of text 
    for (i = 0; i < M; i++) 
    { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 
  
    			// Slide the pattern over text one by one 
    for (i = 0; i <= N - M; i++) 
    { 
  
       			 // Check the hash values of current window of text 
        		// and pattern. If the hash values match then only 
        		// check for characters on by one 
        if ( p == t ) 
        { 
           			 /* Check for characters one by one */
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
  
            			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) 
                cout<<"Pattern found at index "<< i<<endl; 
        } 
  
        		// Calculate hash value for next window of text: Remove 
        		// leading digit, add trailing digit 
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
  
           		 // We might get negative value of t, converting it 
           		 // to positive 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 
  
/* Driver code */
int main() 
{ 
    char txt[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK";
        
      // A prime number 
    int q = 101; (CAN USE ANY NUMBER SAY 11 TOO)
      
      // Function Call
      search(pat, txt, q); 
    return 0; 
} 
  




