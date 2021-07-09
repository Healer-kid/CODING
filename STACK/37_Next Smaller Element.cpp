Next Smaller Element
Difficulty Level : Medium
Last Updated : 24 May, 2021
Given an array, print the Next Smaller Element (NSE) for every element. The Smaller smaller Element for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider next smaller element as -1. 
Examples: 
a) For any array, rightmost element always has next smaller element as -1. 
b) For an array which is sorted in increasing order, all elements have next smaller element as -1. 
c) For the input array [4, 8, 5, 2, 25}, the next smaller elements for each element are as follows.

Element       NSE
   4      -->   2
   8      -->   5
   5      -->   2
   2      -->   -1
   25     -->   -1


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	   
	   int n;
	   cin>>n;
	   int a[n];
	   for(int i=0;i<n;i++)
	   cin>>a[i];
	   int arr[n];
	   stack<int> s;
	    for(int i=n-1;i>=0;i--){
	        
	        while(!s.empty() && s.top()>=a[i])
	        s.pop();
	        
	        if(s.empty())
	        arr[i]=-1;
	        else
	        arr[i]=s.top();
	        
	         s.push(a[i]);
	        
	    }
	    
	     for(int i=0;i<n;i++)
	   cout<<arr[i];
	   
	   
	   
return 0;
}