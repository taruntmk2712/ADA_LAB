#include <bits/stdc++.h>
using namespace std;
void swap(int *c,int *d)
{
	int temp1=*c;
	*c=*d;
	*d=temp1;
}
int partition(int a[],int low,int high)
{
	int pivot = a[low];
	int i=low+1;
	int j=high;
	while(1)
    {
        while(a[i]<=pivot && i<=high)
            i++;
        while(a[j]>pivot && j>=low)
            j--;
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
        else
        {
            a[low]=a[j];
            a[j]=pivot;
        }
    return j;
    }
}

void sort(int a[],int low,int high)
{
	if(low<high)
	{
		int par=partition(a,low,high);
		sort(a,low,par-1);
		sort(a,par+1,high);		
	}
}
int main()
{
	int a[10],i,j,start1,end1,n,k;
	clock_t start,end;
	cout<<"Enter no of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(i =0;i<n;i++)
		cin>>a[i];
    cout<<"Start:";
    cin>>start1;
    cout<<"End:";
    cin>>end1;
    cout<<"k(in range of start to end):";
    cin>>k;
	start = clock();
	sort(a,start1,end1);
	end = clock();
	cout<<a[k-1];
	float exe = float(end-start)/CLOCKS_PER_SEC;
	cout<<"\nExecution time:"<<exe;
	return 0;
}
/*OUTPUT:
Enter the size of an array: 6
Enter the elements of an array: 3 2 5 1 8 9
start: 1
end : 6
k: 4
Element at ‘k’th positon: 5
*/