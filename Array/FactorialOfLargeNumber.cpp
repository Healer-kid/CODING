Factorials of large numbers 

Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

FOR SMALL NUMBERS

 int fact=1;
	    for(int i=1;i<=n;i++){
	        fact=fact*i;
	    }
	    cout<<fact;
	

METHOD-2
USING ARRAY/VECTOR
LOGIC:
store the elements in vector
but store them as individual elements and reverse order,so that we can do normal multiplication


	while(t--){
	    
	    int n;
	    cin>>n;
	    vector<int> v;
	    v.push_back(1);
	    int carry=0;
	    for(int x=2;x<=n;x++){
	        carry=0;
	        for(int i=0;i<v.size();i++){
	            int mul=v[i]*x+carry;
	            v[i]=mul%10;
	            carry=mul/10;
	            
	        }
	       while(carry){
	           v.push_back(carry%10);
	           carry=carry/10;
	           
	           
	       }
	        
	        
	    }
	    for(int i=v.size()-1;i>=0;i--)
	    cout<<v[i];
	    cout<<"\n";
  