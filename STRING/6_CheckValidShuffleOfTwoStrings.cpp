Check if a string is a valid shuffle of two other strings

EXAMPLE:

1XY2 is a valid shuffle of XY and 12
Y12X is not a valid shuffle of XY and 12

This is because Y12X has altered the order of string XY. Here, Y is used before X. Hence, to be a valid shuffle, the order of string should be maintained.

Note: The program gets confused if the initial letters of two strings match. For example, if ab12 and abb34 are two strings, then abbab1234 is a valid shuffle.

However, the program will treat the first two letters ab as part of the first string. Due to this, the third letter b doesn't match with both the third letter of the first string (1) and the first letter of the second string (a).

METHOD-1
ITERATIVE

// check if result string is valid shuffle of string first and second
  static boolean shuffleCheck(String first, String second, String result) {

    // check length of result is same as
    // sum of result of first and second
    if(first.length() + second.length() != result.length()) {
      return false;
    }
    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length()) {

      // check if first character of result matches with first character of first string
      if (i < first.length() && first.charAt(i) == result.charAt(k))
        i++;

      // check if first character of result matches the first character of second string
      else if (j < second.length() && second.charAt(j) == result.charAt(k))
        j++;

      // if the character doesn't match
      else {
        return false;
      }

      // access next character of result
      k++;
    }

    // after accessing all characters of result
    // if either first or second has some characters left
    if(i < first.length() || j < second.length()) {
      return false;
    }

    return true;
  }











METHOD-2
RECURSIVE
TIME:O(M+N)

bool isInterleaving(string X, string Y, string S)
{
    // return true if the end of all strings is reached
    if (!X.length() && !Y.length() && !S.length()) {
        return true;
    }
 
    // return false if the end of string `S` is reached,
    // but string `X` or `Y` is not empty
 
    if (!S.length()) {
        return false;
    }
 
    // if string `X` is not empty and its first character matches with the
    // first character of `S`, recur for the remaining substring
 
    if (X.length() && S[0] == X[0]) {
        return isInterleaving(X.substr(1), Y, S.substr(1));
    }
 
    // if string `Y` is not empty and its first character matches with the
    // first character of `S`, recur for the remaining substring
 
    if (Y.length() && S[0] == Y[0]) {
        return isInterleaving(X, Y.substr(1), S.substr(1));
    }
 
    return false;
}