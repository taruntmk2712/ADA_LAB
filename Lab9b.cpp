#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r < l) 
        return -1; 
  
    int mid = l + (r - l) / 2; 
    if (arr[mid] == x) 
        return mid; 
  
    
    if (arr[mid] > x) 
        return binarySearch(arr, l, mid - 1, x); 
  
    
    return binarySearch(arr, mid + 1, r, x); 
} 
  

int countOccurrences(int arr[], int n, int x) 
{ 
    int ind = binarySearch(arr, 0, n - 1, x); 
  
     
    if (ind == -1) 
        return 0; 
  
    
    int count = 1; 
    int left = ind - 1; 
    while (left >= 0 && arr[left] == x) 
        count++, left--; 
  
    int right = ind + 1; 
    while (right < n && arr[right] == x) 
        count++, right++; 
  
    return count; 
} 
  
void findFirstAndLast(int arr[], int n, int x) 
{ 
    int first = -1, last = -1; 
    for (int i=0; i<n; i++) 
    { 
        if (x != arr[i]) 
            continue; 
        if (first == -1) 
            first = i; 
        last = i; 
    } 
    if (first != -1) 
        cout << "First Occurrence = " << first << " Last Occurrence = " << last; 
    else
        cout << "Not Found"; 
} 
int main()
{
    int i, n, offset, x, index, arr[100];
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter elements in array: "<<endl;
    for (i = 0; i < n; i++)
    {
	    cin>>arr[i];
    }
    cout<<"Enter search item: "<<endl;
    cin>>x;
    findFirstAndLast(arr, n, x);
    cout <<" count = "<<countOccurrences(arr, n, x)<<endl;
    return 0;
}
/*
OUTPUT:
Enter size of array: 
5
Enter elements in array: 
1 1 2 3 4
Enter search item: 
5
First Occurrence = -1    Last Occurrence = -1  count = 0
*/