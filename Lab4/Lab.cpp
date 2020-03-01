#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;
int QuickSelect(int[],int,int,int);
int QuickSelectLeast(int[], int, int, int,int);
int Partition(int[], int,int);
int aPartition(int arr[], int start, int end);


int main()
{	int n,k;
	cout<<"Enter positive integer n to generate n random integers"<<endl;
	cin >> n;
	srand (time(NULL));

	int *arr= new int[n];
	for (int i=0; i<n; i++)
	{
		int num= rand() %200 +(-100);
		arr[i]=num;
	}
	for (int j=0; j<n; j++)
		cout<<arr[j]<<", ";
	
	cout<<endl<<"Enter number k 1 to N to find k closest"<<endl;
	cin >>k;
	cout<<"Median number is: "<<endl; //debug
	int median=n/2;
	int median_num = QuickSelect(arr,median,0,n-1);
	cout<<median_num<<endl; //debug

	int diff[n];
	for (int i =0; i<n;i++)
	{
		diff[i]=arr[i]-median_num;
	}

	QuickSelectLeast(diff,k,0,n-1,median_num);
	cout<<endl;

	for(int i=0; i<n; i++)
		cout<<diff[i]<<" ";
	delete[] arr;
	
}



int QuickSelectLeast(int arr[], int k,int begin,int end,int median_num) //Find Max K elements
{
	int part= aPartition(arr,begin,end);
	if(begin==end)
		for(int i =begin; i < part+1; i++)
		{	if(arr[i]+median_num!=0)
				cout<<arr[i]+median_num<<" ";
		}
	else if(k==part)	
	{	for(int i =begin; i< k; i++)
		{	
			int num=arr[i]+median_num;
			cout<<num<<" ";
		
		}
		return k;
	}
	else if(k<part) 
		return QuickSelectLeast(arr,k,0,part-1,median_num);
	return QuickSelectLeast(arr,k,0,part+1,median_num); // if differcene is greater
						// then pointer is too low,
						// move partition pointer up 
						// one and repartition

}



int QuickSelect(int arr[], int k,int begin,int end)
{		
	int part= Partition(arr,begin,end);
	if(part==k)				//if only one 
		return (arr[part]);
	else if(part>k)				//if pivot index > k search left array
		return QuickSelect(arr,k,0,part-1);
	return QuickSelect(arr,k-part,part+1,end); //if pivot< index search right array adjust k value K-partition

}

int aPartition(int arr[], int start, int end)
{
	int pivot = arr[end]; //make last value the pivot
	int x=start; //start comparing elements from beginning to end

	for(int i =start; i <end;i++)
	{
		if(abs(arr[i])<=abs(pivot))
		{
			swap(arr[i],arr[x]);
			x++;
		}
	}
	swap(arr[index],arr[end]);

	return index;

}

int Partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int p_one=start;
	int p_two=end;

	for(int i=start; i<end; i++)
	{	if(arr[i]<pivot)
			p_one+=1;
		if(arr[i]>pivot)
			p_two-=1;
		if(arr[p_one]>pivot && arr[p_two]<pivot)
			swap(arr[p_one],arr[p_two]);
		if(p_two>p_one)
			break;
	}
	swap(arr[p_two+1],arr[end]);
	return p_two;
}
