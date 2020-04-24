/* Nina Hudak
 * Driver File
 * September 25, 2019
 */

#include <iostream>
#include "dollar_amount.h"

using namespace std;

const int INIT_SIZE = 10;

//Sort array in ascending order
//Params: a[] is an array of DollarAmount 
//size is the size of array a that is to be sorted
//Precondition: array must be filled from 0 to size-1
//Postcondition: a[0] <= a[1] <= ... <= a[size-1] 
void sort(DollarAmount a[], int size);

//Determine the median of an array
//Params: a[] is an array of DollarAmount
//size is size of array a
//Precondition: a must be sorted and filled from 0 to size-1
//Postcondition: the median of a is returned
DollarAmount getMedian(DollarAmount a[], int size);

int main()
{
    DollarAmount * arr = new DollarAmount[INIT_SIZE];
    DollarAmount * ptr = NULL;
    DollarAmount total, median;
    int arr_size = INIT_SIZE;
    int arr_len = 0; //Actual # of objects stored in it, also the index
                     //of next free slot in arr
    bool last_input = false, wrong_input;

    cout << endl;

    do
    {
        if (arr_len == arr_size)
        {
            //The array is full -- need to grow!

            //Allocate an array double the cur_size
            ptr = new DollarAmount[arr_size * 2];

            //Copy each element in arr into the new array that ptr points to
            for(int i=0; i<arr_size; i++)
                *(ptr + i) = arr[i];

            //Now we delete the current arr
            delete [] arr;
            arr = ptr;
            arr_size = arr_size * 2;
        }
        
        do
        {
            cout << "Enter the dollar amount (or enter 0 to quit): $";
            cin >> arr[arr_len];

            if(arr[arr_len].getDollar() > 9999 || arr[arr_len].getDollar() < 0
                    || arr[arr_len].getCent() > 99) //If input out of range
            {
                cout << "Wrong input. Try again\n";
                wrong_input = true;
            }
            else //If user enters valid input
                wrong_input = false;
        }   while(wrong_input);
    
        //If the last read dollar amount is 0.0, then it's the end
        if(arr[arr_len].getDollar() == 0 && arr[arr_len].getCent() == 0)
            last_input = true;
        else //Only increment arr_len for input that's not 0.0
            arr_len++;
    }   while(!last_input);

    //Call sort function to sort the array of DollarAmount
    sort(arr, arr_len);

    //A loop to calculate total DollarAmount
    for(int i=0; i<arr_len; i++)
        total = total + arr[i];

    //Call getMedian function to get the median expenditure
    median = getMedian(arr, arr_len);
    
    //Display the sorted array, total, and median
    cout << "Sorted list of expenditure:\n";
    for(int i=0; i<arr_len; i++)
        cout << arr[i] << endl;
    cout << "The total is " << total << ".\n";
    cout << "The median is " << median << ".\n";
    cout << "Bye!\n\n";

    return 0;
}

//Sorts a[] in ascending order
void sort(DollarAmount a[], int size)
{
    int i;
    int last = size-1; //Point to the index of last element in unsorted part of array

    for(int pass=0; pass<size; pass++)
    {
        //a[0]...a[last] is not sorted
        //Repeated bubble the largest element in this range to the end
        for(i=0; i<=last-1; i++)
        {
            if(a[i] > a[i+1])
            {
                //swap
                DollarAmount temp(a[i+1]);
                a[i+1].setAmount(a[i]);
                a[i].setAmount(temp);
            }
        }
        //At this point, the largest element in a[0...last] is stored in a[last]
        //Unsorted part is now a[0...last]
        last = last-1;
    }
}

//Returns median of a[]
DollarAmount getMedian(DollarAmount a[], int size)
{
    DollarAmount median;
    int median_index = (size) / 2;

    //If the user only entered sentinal value
    if(size == 0)
        median = a[0];
    //If there's an odd number of values then the median is in the array
    else if(size%2 == 1)
        median = a[median_index];
    //Otherwise, median needs to be the average between the two middle values
    else
        median = (a[median_index] + a[median_index - 1]) / 2;

    return median;
}
