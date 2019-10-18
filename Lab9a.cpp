#include<iostream>
#include<time.h>
using namespace std;

int findOffset(int *arr, int low, int high, int size)
{
    int mid;
    if (low <= high)
    {
        mid = low + ((high - low) / 2);
 
        if (arr[mid] > arr[mid+1])
            return mid;
        else if (arr[mid] > arr[size-1])
           		 return findOffset(arr, mid+1, high, size);
       	else
           		 return findOffset(arr, low, mid-1, size);
    }
 
    return -1;   
}
 
int binarySearch(int *arr, int low, int high, int item)
{
    int mid;
    if (low <= high)
    {
        mid = low + ((high - low) / 2);
 
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] > item)
           		 return binarySearch(arr, low, mid-1, item);
      	      else
          		  return binarySearch(arr, mid+1, high, item);
    }
    return -1;
}
 
int main()
{
    int i, size, offset, item, index, arr[100];
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    cout<<"Enter elements in array: "<<endl;
    for (i = 0; i < size; i++)
	cin>>arr[i];
    cout<<"Enter search item: "<<endl;
    cin>>item;
    offset = findOffset(arr, 0, size-1, size);
    if (offset == -1)
    {
    	index = binarySearch(arr, 0, size-1, item);
    	if(index != -1)
	        cout<<"Item found at index "<<index<< endl;
	    else
	        cout<<"Item not found"<<endl;
    }
    else
    {
    	index = binarySearch(arr, 0, offset, item);
    	if (index != -1)
		    cout<<"Item found at index"<<index<<endl;
	    else
	    {
            index = binarySearch(arr, offset+1, size-1, item);
	        if (index != -1)
	            cout<<"Item found at index: "<<index;
	        else
        	    cout<<"Item not found. "<<endl;
	    }
    }
    return 0;
}
/*
OUTPUT:
Enter size of array: 5
Enter elements in array: 9  10  6  7  8
Enter search item: 7
Item found at index: 3

Enter size of array: 4
Enter elements in array: 3  4  1  2
Enter search item: 5
Item not found
*/