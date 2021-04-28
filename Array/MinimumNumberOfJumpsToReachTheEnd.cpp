Minimum number of jumps 
Medium Accuracy: 32.96% Submissions: 59868 Points: 4
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Example 1:

Input:
N=11 
arr=1 3 5 8 9 2 6 7 6 8 9 
Output: 3 

Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last.



IDEA:
1)check i is in range of j (i.e) with j ,can I be reached?
	j+arr[j]>=i  //if greater,then can be reached




METHOD-1
USING DP	 TIME:O(N^2)



int minJumps(int arr[], int n){
    // Your code here
    if(arr[0]==0||n==0)
    return -1;
    int jumps[n];
    jumps[0]=0;
  for(int i=1;i<n;i++)
    {  jumps[i]=INT_MAX;
         
        for(int j=0;j<i;j++)
        if(j+arr[j]>=i && jumps[j]!=INT_MAX){
            jumps[i]=min(jumps[i],jumps[j]+1);
            break;
    }
    }
    if(jumps[n-1]!=INT_MAX)
    return jumps[n-1];
    else
    return -1;
}
















METHOD -2 
youtube link:https://www.youtube.com/watch?v=vBdo7wtwlXs
TIME: O(N)
INTUITION:ladders and stairs
1)keep storing the ladders if it is bigger than the current ladder
2)whenever the ladder ends/no more stairs in the current ladder,u have to take another ladder,so it is a jump
you will increase the jumps
3) NOTE: if the stairs becomes 0 and the current ladder is in the same size of index(no bigger ladder is found),then you cant reach further 
eg)
2 1 0 3 
here,you cant reach further,so -1

 public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==0 || arr[0]==0)
        return -1;
        int ladder=arr[0];
        int stairs=arr[0];
        int jump=1;
        for(int i=1;i<n;i++ ){
            if(i==n-1)
            return jump;
            
            if(arr[i]+i>ladder)
            ladder=arr[i]+i;
            
            stairs--;
            if(stairs==0)
            
            {
                if(i==ladder)
                return -1;
                jump++;
                stairs=ladder-i;
                
            }
            
            
            
            
        }
        
        
      return jump;  
        
    }
};

