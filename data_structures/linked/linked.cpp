/* Nina Hudak
 * Lab4: Working with linked lists
 * Due Date
 */

#include <iostream>

using namespace std;

typedef char ItemType;

//Define a struct type named NodeType that includes an ItemType and
//pointer (to a NodeType) field
struct NodeType
{
    ItemType value;
    NodeType *next;
};

//Define a struct type named NodeType that includes an ItemType and
//pointer (to an IntNodeType) field
struct IntNodeType
{
    int value;
    IntNodeType *next;
};

//Display a linked list of NodeType
//@head is address of the first node
void DisplayLinkedList (NodeType *head);

//Display a linked list of IntNodeType
//@head is address of first node
void DisplayLinkedList(IntNodeType * head);

//Create a new node to store the given value, and make this
//new node the first of the linked list
//@head is address of the firs tnode, will be updated by @value
void InsertAtFront (NodeType * & head, ItemType num);

//Insert a new node before a node (of a given value)
//@param head: pointer pointing to the first node in the linked list
//@param num: the value to be inserted
//@param beforeThis: the value to be inserted before
//pre: list is initialized and beforeThis exists in the list
//post: a node with value num is inserted in the list before the node containing
//      beforeThis
void InsertInMiddle(NodeType * & head, ItemType num, ItemType beforethis);

//Create a new node with the given value, and append it to the linked list
//given by the head pointer
//@param head: pointer pointing to the first node, NULL if the list is empty
//@param num: the int number to be saved in the node
//@return nothing
void AppendInTheEnd (NodeType * & head, ItemType num);

//Delete (deallocate) all nodes in the linked list given by the head pointer
//post: all nodes in the linked list are deleted. Head set to NULL
void ClearLinkedList (NodeType * & head);
void ClearLinkedList (IntNodeType * & head);

//Search for given value in the linked list pointed to by firstNodePtr
//@param firstNodePtr: pointer to the head of the list
//@param value: what value are we looking for
//@return the address of the node that stores the matching value.
//        if no match, return NULL
NodeType * Search (NodeType * firstNodePtr, ItemType num);

//Search for given value in the linked list pointed to by firstNodePtr,
//return the matching node's address, and set its previous node's address in
//prevNode parameter
//post: if the value is found, the node's address will be returned, and
//      prevNode will point to the node before. If not, return NULL, prevNode
//      is NULL
//return: same as Search
NodeType * Search (NodeType * firstNodePtr, ItemType num, NodeType * & prevNode);

//Delete the node storing the given value from the linked list
//1. Find the value in the list (i.e. find the pointer that points to the node)
//   and also remembers the address of its previous node
//2. If the node to be removed is not in the header, skip it in the list
//   (assign its next node's address to its prev node's next)
//   otherwise set header to its next node's address
//3. Delete the node (to free up heap storage)
//@param firstPtr: if the value is stored in the head, then firstPtr will
//                 be updated
//@return true if the value is removed, false if the value not found
bool Delete (NodeType * & firstPtr, ItemType num);

//Create a linked list to store the values in array a
//@param a: the array of int values
//@param size: length of array
//@return the address of the first node
NodeType * InitList (ItemType a[], int size);

//Split the given list into two with equal length. If the list length is
//odd, the first list gets one element more than the second one
//@param head: points to the first node of the linked list
//@param firstHalf: upon return, points to the first node of first split list
//@param secondHalf: upon return, points to the first node of second half
void Split (NodeType * head, NodeType * & firstHalf, NodeType * &secondHalf);

//Merge two list into two
//@param lis1: points to the first list
//@param list2: points to the second list
//pre: list1 must be initialized
//@return the address of the first node of the merged linked list
//list1 element -> list2 elements
NodeType * Merge (NodeType * list1, NodeType * list2);

//Returns number of nodes in the linked list
//@param head: pointer pointing to the first node, NULL if the linked list is empty
//pre: head points to the first node in the list
//post: return number of nodes in the list
int NumberOfNodes (NodeType * & head);
int NumberOfNodes (IntNodeType * & head);

//Insert an integer value into the linked list by value
//@param head: address of the first node in the linked list
//@param value: int value to be inserted into the linked list
//pre: the linked list is sorted
//post: new node created and inserted into the list, and the linked list is still sorted
void SortedInsert(IntNodeType * & head, int num);

//Create a new linked list containing values from 2 existing lists
//@param list1: pointer pointing to first value of linked list number 1
//@param list2: pointer pointing to first value of linked list number 2
//pre: 2 separate linked lists are initialized
//post:
IntNodeType * UnionList(IntNodeType * list1, IntNodeType * list2);

int main()
{
    NodeType * head = NULL; //first node in unsorted list
    IntNodeType * inthead = NULL; //first node in sorted list
    IntNodeType * intlist1 = NULL, * intlist2 = NULL; //sorted lists for union function
    char op;
    int intvalue;
    ItemType value, beforeThis;
    ItemType newValue;
    ItemType values[9] = {'a', '2', 'd', '4', '5', 'f', 'z', '9', 'f'};
    NodeType * list;
    NodeType * p;

    cout << "\n*********Menu*********" << endl;
    cout << "d: delete a value from the unsorted list\n";
    cout << "a: append a value to the end of the list\n";
    cout << "i: insert a value to the beginning of the list\n";
    cout << "m: insert a value before an existing value\n";
    cout << "l: lookup a value and modify it in the unsorted list\n";
    cout << "c: break a list into two, merge back so that second\n"
         << "   half becomes first half\n";
    cout << "s: show the content of the unsorted list\n";
    cout << "n: create a list from the array\n";
    cout << "u: union two lists\n";
    cout << "o: insert a value into an ordered list\n";
    cout << "v: return the length of the ordered list\n";
    cout << "q: to exit\n";
    cout << "*********Menu*********" << endl;

    do
    {
        cout << "What do you want to do? ";
        cin >> op;

        switch(op)
        {
            case 'd':
                cout << "What value do you want to remove: ";
                cin >> value;

                cout << "Before deleting:\n";
                DisplayLinkedList(head);

                if(Delete(head, value)) //if value in list, delete node
                {
                    cout << "After deleting:\n";
                    DisplayLinkedList(head);
                }
                else //if value not in list, error
                    cout << "Value not in the list" << endl;
                break;
            case 'a': //Append value to the end
                cout << "What value do you want to append to the list? ";
                cin >> value;

                cout << "Before appending:\n";
                DisplayLinkedList(head);

                //append a new node to the end of the list to store this new value
                if(head==NULL) //if list is NULL, insert in front
                    InsertAtFront(head, value);
                else
                    AppendInTheEnd(head, value);
                cout << "After appending:\n";
                DisplayLinkedList(head);

                break;
            case 'i': //Insert value to beginning
                cout << "What value do you want to insert to beginning? ";
                cin >> value;

                cout << "Before inserting:\n";
                DisplayLinkedList(head);

                //insert a new node to the front of the list to store this new value
                InsertAtFront(head, value);

                cout << "After inserting:\n";
                DisplayLinkedList(head);

                break;
            case 'l': //Look up and modify value
                cout << "What value do you want to look up? ";
                cin >> value;

                //Search for value
                p = Search(head, value);

                //if p is NULL then the value wasnt found -- error
                if(p==NULL)
                {
                    cout << "Value not found" << endl;
                    break;
                }

                cout << "What new value do you want to assign to the node? ";
                cin >> newValue;

                cout << "Before modifying:" << endl;
                DisplayLinkedList(head);

                //Modify the node's value
                p->value = newValue;

                cout << "After modifying:" << endl;
                DisplayLinkedList(head);
                break;
            case 's': //Show list
                cout << "Displaying the current list: " << endl;
                DisplayLinkedList(head);
                break;
            case 'n': //Create new list from array
                cout << "Create a list from an array\n";

                list = InitList(values, 9);
                
                //Display the newly created list
                DisplayLinkedList(list);

                //Destroy the list...
                ClearLinkedList(list);
                break;
            case 'c': //Cut list in half and put it back together in reverse order
                NodeType *list1, *list2;

                if(head != NULL)
                {
                    cout << "Cut the list into half in the middle\n";

                    //Split list in half
                    Split(head, list1, list2);

                    //Display both lists using the DisplayLinkedList() function
                    cout << "Displaying first half: " << endl;
                    DisplayLinkedList(list1);

                    cout << "Displaying second half: " << endl;
                    DisplayLinkedList(list2);

                    //Merge the two lists back, the second sublist goes first
                    head = Merge(list2, list1);
                
                    //Display the merged list
                    //I display list2 to show that the lists were actually linked together
                    //and list2 is changed
                    //However, merge only works for if list2 isn't NULL because the 
                    //function signature that was given to us had no reference variables
                    //Thus, if list2 is NULL, just display head.
                    cout << "Displaying merged list: " << endl;
                    if(list2 != NULL)
                        DisplayLinkedList(list2);
                    else
                        DisplayLinkedList(head);
                }
                else
                    cout << "List has no values yet" << endl;

                break;
            case 'm': //Insert a value before a given value
                cout << "What value do you want to insert in the middle? ";
                cin >> value;
                cout << "Where to insert, before which value? ";
                cin >> beforeThis;

                //Search for the value beforeThis to make sure it exists in list
                p = Search(head, beforeThis);

                if(/*head!=NULL &&*/ p!=NULL) //if beforeThis is in list
                {
                    //Display list before inserting
                    cout << "Before inserting:" << endl;
                    DisplayLinkedList(head);

                    //Insert value
                    InsertInMiddle(head, value, beforeThis);

                    //Display list after inserting
                    cout << "After inserting:" << endl;
                    DisplayLinkedList(head);
                }
                else  //if beforeThis not in list, error
                    cout << "Value does not exist" << endl;
                break;
            case 'u': //Union two lists
                IntNodeType * u;

                do //Create list1
                {
                    cout << "Enter an integer to insert in list1 or 0 to stop: ";
                    cin >> intvalue;
                    if(intvalue != 0)
                        SortedInsert(intlist1, intvalue);
                }   while(intvalue != 0);
                do //Create list2
                {
                    cout << "Enter an integer to insert in list2 or 0 to stop: ";
                    cin >> intvalue;
                    if(intvalue != 0)
                        SortedInsert(intlist2, intvalue);
                }   while(intvalue != 0);

                u = UnionList(intlist1, intlist2); //Union list1 and list2

                //Display each list and the union list
                cout << "List1:" << endl;
                DisplayLinkedList(intlist1);
                cout << "List2:" << endl;
                DisplayLinkedList(intlist2);
                cout << "Union:" << endl;
                DisplayLinkedList(u);

                //Destroy lists
                ClearLinkedList(intlist1);
                ClearLinkedList(intlist2);
                ClearLinkedList(u);
                break;

            case 'o': //Sorted Insert
                cout << "What integer do you want to insert into sorted list? ";
                cin >> intvalue;

                //Display list before insert
                cout << "Before Inserting:" << endl;
                DisplayLinkedList(inthead);

                //Insert
                SortedInsert(inthead, intvalue);

                //Display after insert
                cout << "After Inserting:" << endl;
                DisplayLinkedList(inthead);
                break;
            case 'v': //return length of list
                cout << "The ordered linked list has " << NumberOfNodes(inthead) << " nodes\n";
                break;
            case 'q': //exit
                cout << "Exiting..." << endl;

                //Call the DeleteLinkedList() function to deallocate
                //all memory...
                ClearLinkedList(head);
                ClearLinkedList(inthead);
                break;
            default:
                cout << "Unknown request\n";
        }
    }   while (op != 'q');

    return 0;
}

//Display a linked list of NodeType
void DisplayLinkedList(NodeType * head)
{
    NodeType * p;
    
    p = head;   //Initializes pointer p to point to the first node in list

    cout << "Displaying linked list: " << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    while (p != NULL)
    {
        cout << " Node at " << p << endl;
        cout << "        value:  " << p->value << endl;
        cout << "        next:   " << p->next << endl;
        p = p->next; //update p to point to next node in linked list...
    }
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

//Display a linked list of IntNodeType
void DisplayLinkedList(IntNodeType * head)
{
    IntNodeType * p;
    
    p = head;   //Initializes pointer p to point to the first node in list

    cout << "Displaying linked list: " << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    while (p != NULL)
    {
        cout << " Node at " << p << endl;
        cout << "        value:  " << p->value << endl;
        cout << "        next:   " << p->next << endl;
        p = p->next; //update p to point to next node in linked list...
    }
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}


//Create a new node to store the given value, and make this new node the
//first of the linked list
void InsertAtFront(NodeType * & head, ItemType num)
{
    NodeType * p;

    p = new NodeType; //Create new node

    p->value = num; //Initialize new node
    p->next = head; //Node is now first node

    head = p; //head now points to new first node
}

//Insert value into list before a given value
void InsertInMiddle(NodeType * & head, ItemType num, ItemType beforethis)
{
    NodeType * ptr; //ptr pointing to beforethis
    NodeType * prev; //ptr pointing to the node before beforeThis

    ptr = Search(head, beforethis, prev); //Search for beforethis
   
    if(ptr->value == head->value) //if beforethis is the first node, insert in front
        InsertAtFront(head, num);
    else //...otherwise
    {
        NodeType * temp = new NodeType; //create new node
        temp->value = num; //Initialize node
        prev->next = temp; //update prev pointer to point to new node
        temp->next = ptr; //new node points to node storing beforethis
    }
}

//Create a new node with the given value, and append it to the linked list
//given by the head pointer
void AppendInTheEnd(NodeType * & head, ItemType num)
{
    NodeType * p = head;

    while(p->next != NULL) //make p point to last node
        p = p->next;
    
    p->next = new NodeType; //old last node points to a new last node
    p = p->next; //update p to point to new last node

    p->value = num; //Initialize new node
    p->next = NULL;
}

//Search for given value in the list pointed to by firstNodePtr
NodeType * Search (NodeType * firstNodePtr, ItemType num)
{
    NodeType * p;

    p = firstNodePtr;
    while(p!=NULL)
    {
        if(p->value == num)
            return p;
        p = p->next; //update p with the current node's next field
    }
    return p;
}

//Search for given value in the list pointed to by firstNodePtr
NodeType * Search (NodeType * firstNodePtr, ItemType num, NodeType * & prevNode)
{
    NodeType * p = firstNodePtr; //p points to first node in list
    prevNode = NULL; //r points to node before p, right now NULL

    while(p != NULL)
    {
        if(p->value == num) //if p is pointing to the value we're searching for...
        {
            //set prevNode reference variable to r and return p
            return p;
        }
        prevNode = p; //if we havent found a match yet, update pointers
        p = p->next;
    }
    prevNode = NULL; //if we make it to this point, num isn't in the list. Pointers are NULL
    return p;
}

//Delete the node storing the given value from the linked list
bool Delete(NodeType * & firstPtr, ItemType num)
{
    NodeType * prev, * cur;

    cur = Search(firstPtr, num, prev);
   
    if(cur == NULL)
        return false;
    else
    {
        //remove cur node from the linked list
        if(prev != NULL)
        {
            //not the first one
            prev->next = cur->next; //bypass cur node
        }
        else //cur is the first node
            firstPtr = cur->next; //update the head pointer

        delete cur; //deallocate the node itself
        return true;
    }
}

//Delete all nodes in the list (Deallocate the memory)
void ClearLinkedList(NodeType * & head)
{
    NodeType * p = head;

    while(p!=NULL)
    {
        NodeType * temp = p->next; //point to node after first node
        delete p; //delete first node
        p = temp; //point to new first node
    }
}

//Delete all nodes in list of IntNodeType
void ClearLinkedList(IntNodeType * & head)
{
    IntNodeType * p = head;

    while(p!=NULL)
    {
        IntNodeType * temp = p->next;
        delete p;
        p = temp;
    }
}


//Create a linked list to store the values in array a
NodeType * InitList (ItemType a[], int size)
{
    NodeType * ptr;
    NodeType * head = new NodeType;

    head->value = a[size-1]; //Initialize head to last value in array
    head->next = NULL;

    for(int i=size-2; i>=0; i--) //work from end of array up
    {
        ptr = new NodeType; //create new node
        ptr->value = a[i]; //initialize
        ptr->next = head; //node points to head
        head = ptr; //update head to point to new node
    }
    return head;
}

//Split the given list into two with equal length. If the list length is
//odd, the first list gets one element more than the second one
void Split (NodeType * head, NodeType * & firstHalf, NodeType * &secondHalf)
{
    int tot_length, length1, length2;
    firstHalf = NULL;
    secondHalf = NULL;
    NodeType * ptr = head;

    tot_length = NumberOfNodes(ptr); //get total length

    if(tot_length%2 == 0) //if total length is divisible by 2, length1 = length2
        length1 = tot_length/2;
    else //otherwise, length1 has 1 more node than length2
        length1 = (tot_length/2) + 1;
    
    length2 = tot_length/2;

    firstHalf = new NodeType; //Initialize first pointer of firsthalf
    firstHalf->value = ptr->value;
    firstHalf->next = NULL;

    for(int i=1; i<length1; i++) //put length1 elements of list in first half
    {
        ptr = ptr->next;
        AppendInTheEnd(firstHalf, ptr->value);
    }

    ptr = ptr->next;

    if(ptr != NULL) //for case where list only had 1 element
    {
        secondHalf = new NodeType; //initialize first pointer of secondhalf
        secondHalf->value = ptr->value;
        secondHalf->next = NULL;
    }

    for(int i=1; i<length2; i++) //put length2 elements in second half
    {
        ptr = ptr->next;
        AppendInTheEnd(secondHalf, ptr->value);
    }
}

//Merge two list into two
NodeType * Merge (NodeType * list1, NodeType * list2)
{
    NodeType * p = list1;

    if(p!=NULL) //if list1 isnt null
    {
        while(p->next != NULL) //Get to end of list
            p = p->next;
        p->next = list2; //make last node of list1 point to first node of list2
    }
    else
        list1 = list2;
    
    return list1;
}

//Returns number of nodes in NodeType linked list
int NumberOfNodes (NodeType * & head)
{
    NodeType * ptr = head;
    int length;

    if(ptr == NULL)
        length = 0;
    else
    {
        length = 1;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            if(ptr != NULL)
                length++;
        }
    }
    return length;
}


//Returns number of nodes in IntNodeType linked list
int NumberOfNodes (IntNodeType * & head)
{
    IntNodeType * ptr = head;
    int length;

    if(ptr == NULL)
        length = 0;
    else
    {
        length = 1;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            if(ptr != NULL)
                length++;
        }
    }

    return length;
}

//Insert an integer value into the linked list by value
void SortedInsert(IntNodeType * & head, int num)
{
    IntNodeType *p, *prev;
    if(head == NULL) //if list is null, initialize new node
    {
        head = new IntNodeType;
        head->value = num;
        head->next = NULL;
    }
    else if(num <= head->value) //if num is smaller than head, put new node at front
    {
        p = new IntNodeType;
        p->value = num;
        p->next = head;
        head = p;
    }
    else
    {
        p = head;
        prev = NULL;
    
        while(p != NULL && p->value <= num) //Look for value that num is smaller than
        {
            prev = p;
            p = p->next;
        }
        
        prev->next = new IntNodeType; //insert new node
        prev = prev->next;
        prev->value = num;

        if(p == NULL) //if p is null then num is largest in list and goes at end
            prev->next = NULL;
        else //otherwise, point at next node
            prev->next = p;
    }
}

//Create a new linked list containing values from 2 existing lists
IntNodeType * UnionList(IntNodeType * list1, IntNodeType * list2)
{
    IntNodeType * head = new IntNodeType;
    IntNodeType * p = list1;
    IntNodeType * tail;

    head->value = p->value; //initialize head value
    head->next = NULL;

    tail = head;

    if(p != NULL)
    {
        while(p->next != NULL) //copy list1 into new list
        {
            p = p->next;
            tail->next = new IntNodeType;
            tail = tail->next;
            tail->value = p->value;
            tail->next = NULL;
        }
    }

    p = list2;

    if(p != NULL)
    {
        while(p != NULL) //copy list2 into new list
        {
            tail->next = new IntNodeType;
            tail = tail->next;
            tail->value = p->value;
            tail->next = NULL;

            p = p->next;
        }
    }

    return head;
}

