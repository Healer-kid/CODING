Nearly Sorted Algorithm 

Given an array of n elements, where each element is at most k away from its target position. The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K, denoting number of elements in array and at most k positions away from its target position respectively. Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N

Example:
Input:
2
3 3
2 1 3
6 3
2 6 3 12 56 8
Output:
1 2 3
2 3 6 8 12 56

METHOD-1
SORTING
TIME:O(NLOGN)


METHOD-2
USING MIN HEAP
TIME:O(NLOGK)
LOGIC:
1.elements must be atmost k place far from its place,so push upto k elements
into the pq,then the top element must have been sorted
2.repeat for all the elements ,everytime take the top element and add it to an array/vector



 priority_queue<int, vector<int>, greater<int> > pq;
       vector<int> v;
       vector<int>::iterator it;
       
       for(int i=0 ;i<n; i++){
           pq.push(arr[i]);
           
           if(pq.size() > k) {v.push_back(pq.top()); pq.pop();}
       }
       while(pq.size() > 0) {v.push_back(pq.top() ); pq.pop(); }