#include <math.h>
#include <iostream>
#include "FindSquare.cpp"
#include "FindLowest.cpp"
using namespace std;
int main()	
{   

//---------------------Part 1-----------------------------
    FindSquare f; //Class to find square
    int inputNumber; //number to find
    cout<<"Enter a number to look for square" <<endl;
    cin>>inputNumber;
  
    cout<<"Square of " << inputNumber<< f.square(inputNumber,0,inputNumber)<<endl;
//-------------------Part 2----------------------------------
    FindLowest l; //binary search function to find lowest missing number
    int input;
   
    // first array lowest should be 2
    int arr[6]={0,1,3,6,8,9};
    cout<<"Lowest Missing Number is: "<<l.lowest(arr,0,6,6)<<endl; 

    //second array lowest:0
    int  ar[4]={2,5,7,11};
    cout<<"Lowest Missing Number is: "<<l.lowest(ar,0,4,4)<<endl;
   
    //third array lowest:5
    int  a[5]={0,1,2,3,4};
    cout<<"Lowest Missing Number is: "<<l.lowest(a,0,5,5)<<endl;
   
    //third array lowest:0
    int b[1]={12};
    cout<<"Lowest Missing Number is: "<<l.lowest(b,0,1,1)<<endl;
         
};

