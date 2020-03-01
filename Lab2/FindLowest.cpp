#include <iostream>

using namespace std;
//Class FindLowest
//Recursive function to find the lowest missing number in a sorted array
//will compare number with index
//
//@param arr[]: array passed as parameter
//@param start: the starting index of the search
//@param range: the ending index of the search
//@param size:  size of the array
/////////////////////////////////////////////////////////////////

class FindLowest
{
   public:
	   int lowest(int arr[],int start,int range,int size)
	   {	
		
		int middle = floor((start+range)/2);
		if(start>size-1) 	//past last index return last+1
			return size;
		if(start==range)
			return middle;	//begining
		if(arr[middle]>middle)
			return lowest(arr,start,middle,size);
		if(middle==0 && arr[middle]==0) //array with only one entry
			return 1;
		return lowest(arr,middle+1,range,size); //if number 
							//equals index
							//search right
	   }
};
