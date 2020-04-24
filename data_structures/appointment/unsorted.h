/* Nina Hudak
 * Header file for class UnsortedType: unsorted.h
 */


#ifndef UNSORTED_H
#define UNSORTED_H

#include "appointment.h"

const int INIT_SIZE = 10;

class UnsortedType
{
    public:
        //Constructor
        UnsortedType();

        //Constructor
        //Params: len becomes the initial value of arr_size
        //Pre: len > 0
        //Post: UnsortedType is declared with initial size of len
        UnsortedType(int len);

        //Destructor
        ~UnsortedType();

        //Returns the list to the empty state
        //Post: list is empty
        void MakeEmpty();

        //Determines whether list is full
        //Pre: list has been initialized
        //Post: function value = (list is full)
        bool IsFull() const;

        //Determines the number of elements in the list
        //Pre: list has been initialized
        //Post: function value = number of elements in the list
        int GetLength() const;

        //Retrieves list element whose key matches item's key (if present)
        //Params: a is key, found is if a is found in list
        //Pre: list has been initialized, key member of item is initialized
        //Post: if theres an element whose key matches a's key,
        //      then found = true and element is returned. Otherwise,
        //      found = false and a is returned. List is unchanged
        Appointment GetItem(Appointment a, bool &found);

        //Adds item to list
        //Params: a is Appointment to be added to list
        //Pre: list has been initialized and is not full. a is not in list
        //Post: a is in the list
        void PutItem(Appointment a);

        //Deletes the element whose key matches a's key
        //Params: a is Appointment to be deleted
        //Pre: list been initialized and key member of a is initialized
        //     One and only one element in list has a key matching a's key
        //Post: no element in list has a key matching a's key
        void DeleteItem(Appointment a);

        //Initializes current position for an iteration through the list
        //Pre: list has been initialized
        //Post: current position is prior to list
        void ResetList();

        //Gets next element in list
        //Pre: List has been initialized and has not been changed since
        //     last call. current position is defined. element at current
        //     position is not last in list
        //Post: current position is updated to next position. item is a
        //      copy of element at current position
        Appointment GetNextItem();

        //Overload [] operator to be used on an UnsortedType object
        //Params: index is the index of the element to be accessed
        //Pre: 0 <= index <= length. UnsortedType is initialized for 0 to length
        //Post: element at index is returned
        Appointment &operator [] (int index);

    private:
        int length, arr_size, currentPos;
        Appointment *info;
};

#endif

