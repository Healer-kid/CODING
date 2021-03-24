
Find Union and Intersection of two unsorted arrays

Given two unsorted arrays that represent two sets (elements in every array are distinct), find union and intersection of two arrays.
For example, if the input arrays are: 
arr1[] = {7, 1, 5, 2, 3, 6} 
arr2[] = {3, 8, 6, 20, 7} 
Then your program should print Union as {1, 2, 3, 5, 6, 7, 8, 20} and Intersection as {3, 6, 7}. Note that the elements of union and intersection can be printed in any order.


METHOD 1
Hashing


int doUnion(int a[], int n, int b[], int m)  {
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    s.insert(a[i]);
    for(int i=0;i<m;i++)
    s.insert(b[i]);
    return s.size();					//size printed
    //code here
}

Intersection
METHOD 1
Hashing


set<int> hs;
    for (int i = 0; i < n1; i++)
        hs.insert(arr1[i]);
 
    for (int i = 0; i < n2; i++)			//if it is present,then print it
         if (hs.find(arr2[i]) != hs.end())
            cout << arr2[i] << " ";



Intersection
METHOD 2
sorting


sort(a, a + n);
sort(b, b + m);
void intersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            j++;
        }
        else if (b[j] > a[i]) {
            i++;
        }
        else {
             
            
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}


