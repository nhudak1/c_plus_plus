/* Nina Hudak
 * Implementation file for class UnsortedType: unsorted.cpp
 */

#include <iostream>
#include "appointment.h"
#include "unsorted.h"
using namespace std;

//"Default" Constructor
UnsortedType::UnsortedType()
{
    info = new Appointment[INIT_SIZE]; //Dynamically allocate array
    arr_size = INIT_SIZE; //set size of array to default initial size
    length = 0;
    currentPos = -1;
}

//Constructor that takes in int determining length of UnsortedType
UnsortedType::UnsortedType(int len)
{
    info = new Appointment[len]; //Dynamically allocate array
    arr_size = len; //set size of array to len
    length = 0;
    currentPos = -1;
}

//Destructor
UnsortedType::~UnsortedType()
{
    delete [] info; //Delete array
}

//Returns whether UnsortedType is full
bool UnsortedType::IsFull() const
{
    //return whether length of filled indices == length of array
    return (length == arr_size);
}

//Returns length of UnsortedType
int UnsortedType::GetLength() const
{
    return length;
}

//Searches for an appointment with a given date and returns
//the appointment. found parameter is whether or not appointment
//is found
Appointment UnsortedType::GetItem(Appointment a, bool &found)
{
    int location = 0; //index counter
    bool moreToSearch = (location < length); //if more elements after location
    found = false;

    while(moreToSearch && !found)
    {
        switch(a.ComparedTo(info[location]))
        {
            //if a != element, go to next element
            case '<':
            case '>':
                location++;
                moreToSearch = (location < length);
                break;
            //if a == element, we found it!
            case '=':
                found = true;
                a = info[location];
                break;
        }
    }
    return a;
}

//Makes UnsortedType object "empty" by setting length to 0
void UnsortedType::MakeEmpty()
{
    length = 0;
}

//Inserts an Appointment into UnsortedType object
void UnsortedType::PutItem(Appointment a)
{
    //if the array is full...
    if((*this).IsFull())
    {
        //...need to grow array
        //Make new pointer that points to dynamically allocated array
        //that is double the size of the old array
        Appointment *ptr = new Appointment[arr_size * 2];

        //Copy old array into new array
        for(int i=0; i<arr_size; i++)
            *(ptr + i) = info[i];

        //Delete array
        delete [] info;

        //Now our private member points to new array and arr_size is updated
        info = ptr;
        arr_size = arr_size * 2;
    }
    info[length] = a; //add new element
    length++; //update length
}

//Deletes an Appointment from UnsortedType object
void UnsortedType::DeleteItem(Appointment a)
{
    int location = 0; //index counter

    //Look for a location where element == a
    while(a.ComparedTo(info[location]) != '=')
        location++;

    //When we find it, set that location equal to the last element in list
    info[location] = info[length-1];
    length--; //Update length
}

//Resets the current index
void UnsortedType::ResetList()
{
    currentPos = -1;
}

//Returns the next item in the UnsortedType object
Appointment UnsortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

//Overload the [] operator to be able to use in on UnsortedType object
Appointment &UnsortedType::operator [] (int index)
{
    return info[index];
}


