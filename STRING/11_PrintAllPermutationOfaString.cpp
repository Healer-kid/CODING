Write a program to print all permutations of a given string

A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation. 

Below are the permutations of string ABC. 
ABC ACB BAC BCA CBA CAB

METHOD-1

TIME COMPLEXITY:O(N!*N)
WHERE  n =no of traversals to get a single  string and for n! number of strings,it is o(n*n!)


void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}



METHOD-2

TIME:
O(NLOGN)
USED :

1)Next permutation gives lexicographically next greater value.
2)If we sort a string using stl sort,Input : bbccdefbbaa ,Output : aabbbbccdef



LOGIC:
1)first sort the string and then use next permutation to find the permutations



  vector<string>find_permutation(string S)
        {
            vector<string>res;
            // sort the string in lexicographically order
            sort(S.begin(), S.end());
            do
            {
                // keep adding while there is next permutation
                res.push_back(S);
            }while(next_permutation(S.begin(), S.end()));
            return res;
        }


METHOD-3
----------------

 void fun(vector<string> &ans,int freq[],string S,string &temp ){
	        
	        if(temp.size()==S.size())
	        {
	            ans.push_back(temp);
	            return;
	        }
	        for(int i=0;i<S.size();i++){
	            
	            if(!freq[i]){
	                
	                temp+=S[i];
	                freq[i]=1;
	                fun(ans,freq,S,temp);
	                freq[i]=0;
	                temp.pop_back();
	                
	                
	                
	            }
	            
	            
	        }
	        
	        
	    }
	
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int freq[S.size()]={0};
		    vector<string> ans;
		    string temp="";
		    sort(S.begin(),S.end());
		    fun(ans,freq,S,temp);
		    return ans;
		    
		    
		}
};

