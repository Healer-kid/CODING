LINK:https://www.youtube.com/watch?v=vHKXT0cSI54

Stack Permutations (Check if an array is stack permutation of other)
Difficulty Level : Medium
Last Updated : 25 Oct, 2019
A stack permutation is a permutation of objects in the given input queue which is done by transferring elements from input queue 
to the output queue with the help of a stack and the built-in push and pop functions.



Examples:

Input : First array: 1, 2, 3  
        Second array: 2, 1, 3
Output : Yes
Procedure:
push 1 from input to stack
push 2 from input to stack
pop 2 from stack to output
pop 1 from stack to output
push 3 from input to stack
pop 3 from stack to output


Input : First array: 1, 2, 3  
        Second array: 3, 1, 2
Output : Not Possible  




#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(int arr1[],int arr2[],int n)
{
    stack<int> s;
    int i=0;
    for(int j=0;j<n;j++)
    {
        s.push(arr1[j]);
        while(!s.empty() && s.top()==arr2[i])
        {
            s.pop();
            ++i;
        }
        
    }
    return i==n;
    
}


int main() {
	
	int arr1[]={1,2,3,4,5};
	int arr2[]={4,5,3,2,1};
	int n=5;
	if(check(arr1,arr2,n))
	cout<<"true";
	else
	cout<<"false";
	
	
	return 0;
}