/* Nina Hudak
 * QueType class header file: queue.h
 */

//#undef QUEUE_H
#ifndef QUEUE_H
#define QUEUE_H

#include <new>
#include <cstddef>

typedef char ItemType;
struct NodeType;

class FullQueue
{};

class EmptyQueue
{};

class QueType
{
    public:
        QueType(); //Constructor

        //Parameterized constructor
        QueType(int max);

        //Copy Constructor
        QueType(const QueType &anotherQue);

        //Class Destructor
        ~QueType();

        //Initializes the queue to an empty state
        //Post: queue is empty
        void MakeEmpty();

        //Determines whether the queue is empty
        //Post: Function value = (queue is empty)
        bool IsEmpty() const;

        //Determines whether the queue is full
        //Post: Function value = (queue is full)
        bool IsFull() const;

        //Adds newItem to the rear of the queue
        //Post: If (queue is full), FullQueue exception is thrown.
        //      Else, newItem is at rear of queue
        void Enqueue(ItemType newItem);

        //Removes front item from the queue and returns it in item
        //Post: If (queue is empty), EmptyQueue exception is thrown
        //      and item is undefined
        //      Else, front element has been removed from queue and
        //      item is a copy of removed element
        void Dequeue(ItemType &item);
    private:
        NodeType *front;
        NodeType *rear;
};

#endif

