Move all negative numbers to beginning and positive to end with constant extra space

METHOD 1
steps:
1)j will keep track of the positive numbers and it will be always less than i
2)unless j finds a positive number,j and i will point to the same index



int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }


METHOD 2
TWO POINTER APPROACH
algo
1)left=0,right-n-1
2)if left is +ve and right is -ve,then swap
3)if left is -ve and right is +ve,then move both pointers
4)if left is -ve and right is also -ve ,then increment left
5)if left iss +ve and right is +ve ,then decrement right




while(left<right){
if(a[left]>0 && a[right]<0)
swap(a[left++],a[right--])

else if(a[left] <0 && a[right]>0)
	{
		left++;
		right--;
	}
else if(a[left]<0 && a[right]<0)
	left++;
else
	right--;	


} 