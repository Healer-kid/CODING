COUNT THE NUMBER OF SUBSET WITH GIVEN DIFFERENCE

int countsubset(int s1,int a[],int n){
    
    if(n==0 and s1==0)
    return 1;
    else if(n==0)
    return 0;
    else if(s1==0)
    return 1;
    else if(s1<a[n-1])
    return countsubset(s1,a,n-1);
    else
    return countsubset(s1,a,n-1)+countsubset(s1-a[n-1],a,n-1);
    
    
    
    
}


int main() {
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   
   int diff;
   cin>>diff;
   
   int sum=accumulate(a,a+n,0);
   int s1=(sum+diff)/2;
   
   cout<<countsubset(s1,a,n);
   
   
   
}