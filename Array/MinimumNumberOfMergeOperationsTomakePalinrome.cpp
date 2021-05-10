MINIMUM NUMBER OF MERGE OPERATION REQUIRED TO MAKE AN ARRAY PALINDROME


i=0,j=n-1,op=0;
while(i<=j)
{
	if(a[i]==a[j])
	{
		i++;
		j--;
	}else if(a[i]>a[j])
	{
		a[j-1]=a[j-1]+a[j];
		op++;
		j--;
	}else{

	a[i+1]=a[i]+a[i+1];
		op++;
		i++;
	}


}
return op;