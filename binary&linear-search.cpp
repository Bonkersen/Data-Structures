#include<iostream>
using namespace std;
int main()
{
	int n,i,k;
	cout<<"\nEnter the array size:";
	cin>>n;
	int arr[n];
	int arrl=sizeof(arr[n])/sizeof(int);
	cout<<"\nEnter elements of array in ascending order:";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nArray:[";
	for(i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<" ";
	}
    cout<<"]\n";
	cout<<"\nEnter value to search:";
	cin>>k;
	cout<<"\nBinary search:\n";
	int low,high,middle;
	low=0;
	high=n-1;
	middle=(low+high)/2;
	while(low<=high)
	{
		if(arr[middle]<k)
		{
			low=middle+1;
		}
		else if(arr[middle]==k)
		{
			cout<<"\nPos of "<<arr[middle]<<" is "<<middle+1<<"\n";
			break;
		}
		else
		{
			high=middle-1;
		}
		middle=(low+high)/2;
	}
	cout<<"\nLinear search:\n";
	for(i=0;i<n;i++)
	{
		if(arr[i]==k)
		{
			cout<<"\nPos of "<<arr[i]<<" is "<<i+1<<"\n";
			break;
		}
	}
}