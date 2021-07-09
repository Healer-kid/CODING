The Celebrity Problem 

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.


METHOD 1
USING O(N2) TIME



int getId(int M[MAX][MAX], int n)
{
    //Your code here
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++){
            if(M[i][j]==1 && M[j][i]==0)
            return j;
                
            
        }
    return -1;
    
    
}









METHOD -2
USING STACK	o(n) space and time
algo
-------
1)discard A ,if A knows B
2) discard B,if A does know B



class Solution {
    public:
    int knows(int A,int B,vector<vector<int>> &M ){
        return M[A][B];
    }
    
    
    int celebrity(vector<vector<int> >& M, int n) {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++)
        s.push(i);
        
       
    int count=0;
    while(count<n-1){
         int A=s.top();
        s.pop();
        int B=s.top();
        s.pop();
        
        
        if(knows(A,B,M) && !knows(B,A,M))
        s.push(B);
        else
        s.push(A);
        
        count++;
        
    }
        
        
        
        
        int celeb=s.top();
        for(int i=0;i<n;i++)    //CHECKING WAT IF NO CELEBRITY IS PRESENT
        {
            if(i!=celeb  &&  M[i][celeb]==0)
            celeb=-1;
            
        }
        
        return celeb;
        
        
        
    }
};
