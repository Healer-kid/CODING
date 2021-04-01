	

METHOD 1:
TIME O(N2) && SPACE O(1)

for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " \n" 
             << next << endl;
    }



METHOD 2:
USING STACK  O(N) SPACE AND TIME


	    for(int i=n-1;i>=0;i--){
	        
	        while(!s.empty() && s.top()<=a[i])
	        s.pop();
	        
	        if(s.empty())
	        arr[i]=-1;
	        else
	        arr[i]=s.top();
	        
	         s.push(a[i]);
	        
	    }
	   
	   
	      