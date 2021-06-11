Find pivot element in a sorted and rotated array
PIVOT --> SMALLEST ELEMENT

Solution should be O(log N) in time and O(1) in space.
USING BINARY SEARCH:
TIME:O(LOGN)



	int low=0,high=n-1;
	while(low<high)  //why it is not '<=' ? cause we need atleast two elements to find a pivot
	{		//if an array which has only one element,then it has no pivot element

		int mid=(low+high)/2;

		if(arr[mid]<arr[high])
			high=mid;
		else
			low=mid+1;	
						//5 6 7 8 0 1 2 3 4


	}
return arr[high];

}