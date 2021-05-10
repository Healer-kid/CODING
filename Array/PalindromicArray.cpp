Palindromic Array 
School Accuracy: 50.0% Submissions: 19528 Points: 0
Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer n denoting the size of the arrays. In the second line are N space separated values of the array A[].

Output:
For each test case in a new line print the required result.


Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    //which is a palindrome number.
A[1] = 222   //which is a palindrome number.
A[2] = 333   //which is a palindrome number.
A[3] = 444  //which is a palindrome number.
A[4] = 555  //which is a palindrome number.
As all numbers are palindrome so This will return 1.


CODE:

int flag=1;
    for(int i=0;i<n;i++){
        int temp=a[i];
        int rem=0,sum=0;
        while(temp){
            rem=temp%10;
            sum=sum*10+rem;
            temp=temp/10;
            
        }
        if(a[i]!=sum)
        {
            flag=0;
            break;
        }
        else{
            flag=1;
            
        }
        
        
        
        
        
        
    }
    return flag;

