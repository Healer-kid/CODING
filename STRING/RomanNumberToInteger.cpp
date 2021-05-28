Roman Number to Integer 

Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5

Example 2:

Input:
s = III 
Output: 3


LOGIC:
1.if the previous number is less than this number ,then they both together contribute to a single number 
say IX =9  (so ,here u need to subtract the first number from the second, 10-1 = 9)
say XV =10+5 //but here you can add 10 and then 5 ,so 15




int value(char c){
    
    if(c=='I')
    return 1;
    if(c=='V')
    return 5;
    if(c=='X')
    return 10;
    if(c=='L')
    return 50;
    if(c=='C')
    return 100;
    if(c=='D')
    return 500;
    if(c=='M')
    return 1000;
    else
    return -1;
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int res=0;
	    int n=str.length();
	    for(int i=0;i<n;i++){
	        
	        if(i+1<n){
	            
	            int s1=value(str[i]);
	            int s2=value(str[i+1]);
	            if(s1>=s2)
	            res=res+s1;
	            else{
	            res=res+s2-s1;
	            i++; //the reason why we increment here is because we dont need to calculate for 
			 //the number which has already calculated eg) IX ,it can be calculated 	
		         //once,you dont need to run the loop twice as it has 2 numbers,instead you 
			 //can break the loop using this i++
	            }
	            
	        }
	        else
	        {
	           int s1=value(str[i]);
	            res=res+s1;
	            
	        }
	        
	        
	        
	        
	    }
	    
	    
	    cout<<res<<"\n";
	    
	    
	    
	}
	return 0;
}