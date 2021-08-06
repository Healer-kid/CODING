Word Break 

Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 


Example 1:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".

‹Example 2:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as 
"i like samsung" or "i like sam sung".
 
TIME:O(S^2)
WHERE S=S.LENGTH()
SPACE:O(N)



LOGIC:

1.use a hashmap or set to store the dictionary of words
2.use i and j ,j-->start of a particular word and i-->marks the end of a particular word
3.make sure dp[j] is true ,which means you have found the previous word and now searching for the next word



	     int n;
	    cin>>n;
	    unordered_set<string> dict;
	    for(int i=0;i<n;i++){
	        string str;
	        cin>>str;
	        dict.insert(str);
	        
	    }													i like
	    string s;
	    cin>>s;
	    vector<int> dp(s.length()+1,0);
	    dp[0]=1;
	    for(int i=1;i<=s.length();i++){
	        for(int j=i-1;j>=0;j-- ){
	            
	            if(dp[j]){
	                
	                string word=s.substr(j,i-j);
	                if(dict.find(word)!=dict.end()){
	                    dp[i]=1;
	                    break;
	                }
	                
	            }
	            
	            
	            
	            
	        }
	        
	        
	    }
	    
	    cout<<dp[s.length()]<<"\n";
	}
	