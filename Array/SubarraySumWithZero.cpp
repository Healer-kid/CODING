






METHOD-1
TIME: O(N^2)
BRUTE FORCE:
find all the subarray and check for zero sum



int flag=0;
	for(int i=0;i<n;i++){
	    int sum=0;
	    for(int j=i;j<n;j++){
	        sum=sum+a[j];
	        if(sum==0){
	        flag=1;
	        break;
	        }
	    }
	    
	    
	}
	if(flag)
	cout<<"Yes"<<"\n";
	else
	cout<<"No"<<"\n";
	}



METHOD-2
TIME:o(N) ,SPACE:O(N)
USING HASHMAP

LOGIC:
if there is a subarray of sum=0,then the cummilative sum repeats somewhere

eg)
 4 3 -1 3 4 -6 2 3
 ---
  X=7
     ---------	
	0
---------------
	Y=7

sum repeats,so there is a subarray of zero sum!!!!


unordered_set<int> mp;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0||mp.find(sum)!=mp.end()||a[i]==0)
        return true;
        
        mp.insert(sum);
        
        
        
        
    }
    
    return false;
}




NOTE:
if asked to find subarray of given sum
then use  sum-k
eg)
 if(sum==0||mp.find(sum-k)!=mp.end())
where k--> given sum for subarray

