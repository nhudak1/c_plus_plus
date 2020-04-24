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

//Display a linked list of NodeType
//@head is address of the first node
void DisplayLinkedList (NodeType *head);

//Create a new node to store the given value, and make this
//new node the first of the linked list
//@head is address of the firs tnode, will be updated by @value
void InsertAtFront (NodeType * & head, ItemType value);

//Create a new node with the given value, and append it to the linked list
//given by the head pointer
//@param head: pointer pointing to the first node, NULL if the list is empty
//@param num: the int number to be saved in the node
//@return nothing
void AppendInTheEnd (NodeType * & head, ItemType num);

//Delete (deallocate) all nodes in the linked list given by the head pointer
//post: all nodes in the linked list are deleted. Head set to NULL
void ClearLinkedList (NodeType * & head);

//Search for given value in the linked list pointed to by firstNodePtr
//@param firstNodePtr: pointer to the head of the list
//@param value: what value are we looking for
//@return the address of the node that stores the matching value.
//        if no match, return NULL
NodeType * Search (NodeType * firstNodePtr, ItemType value);

//Search for given value in the linked list pointed to by firstNodePtr,
//return the matching node's address, and set its previous node's address in
//prevNode parameter
//post: if the value is found, the node's address will be returned, and
//      prevNode will point to the node before. If not, return NULL, prevNode
//      is NULL
//return: same as Search
NodeType * Search (NodeType * firstNodePtr, ItemType value, NodeType * & prevNode);

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
bool Delete (NodeType * & firstPtr, ItemType value);

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
//@return the address of the first node of the merged linked list
//list1 element -> list2 elements
NodeType * Merge (NodeType * list1, NodeType * list2);

int main()
{
    NodeType * head = NULL; //stores the address of the first node
                            //the above is an empty list
    char op;
    ItemType value, beforeThis;
    ItemType newValue;
    ItemType values[9] = {'a', '2', 'd', '4', '5', 'f', 'z', '9', 'f'};
    NodeType * list;

    do
    {
        cout << "*********Menu*********" << endl;
        cout << "What do you want to do: " << endl;

        cout << "d: delete a value from the list\n";
        cout << "a: append a value to the end of the list\n";
        cout << "i: insert a value to the beginning of the list\n";
        cout << "m: insert a value before an existing value\n";
        cout << "l: lookup a value and modify it in the list\n";
        cout << "c: break a list into two, merge back so that second\n"
             << "   half becomes first half\n";
        cout << "s: show the content of the list\n";
        cout << "q: to exit\n";
        cout << "*********Menu*********" << endl;

        cin >> op;

        switch(op)
        {
            case 'd':
                cout << "What value do you want to remove: ";
                cin >> value;

                cout << "Before deleting:\n";
                DisplayLinkedList(head);

                if(Delete(head, value))
                {
                    cout << "After deleting:\n";
                    DisplayLinkedList(head);
                }
                else
                    cout << "Value not in the list" << value << endl;
                break;
            case 'a':
                cout << "What value do you want to append to the list\n";
                cin >> value;

                cout << "Before appending:\n";
                DisplayLinkedList(head);

                //Todo: write a fucntion to append a new node to the end of
                //the list to store this new value

                break;
            case 'i':
                cout << "What value do you want to insert to beginning\n";
                cin >> value;

                cout << "Before inserting:\n";
                DisplayLinkedList(head);

                //Todo: write a function to insert a new node ot the end
                //of the list to store this new value, and call the funct
                //from here...
                InsertAtFront(head, value);

                cout << "After inserting:\n";
                DisplayLinkedList(head);

                break;
            case 'l':
                cout << "What value do you want to look up?";
                cin >> value;

                //Todo... call the search() function

                cout << "What new value do you want to assign to the node?";
                cin >> newValue;

                //Todo: modify the node's value field to the newValue
                break;
            case 's':
                cout << "Displaying the current list: " << endl;
                DisplayLinkedList(head);
                break;
            case 'n':
                cout << "Create a list from an array\n";

                list = InitList(values, 9);
                
                //Display the newly created list
                DisplayLinkedList(list);

                //Todo: destroy the list...
                ClearLinkedList(list);
                break;
            case 'c':
                //Extra credit parts
                cout << "Cut the list into half in the middle\n";

                //Todo by you: calling your function that breaks a list
                //into two

                //Display both lists using the DisplayLinkedList() function

                //Merge the two lists back, the second sublist goes first
                
                //Display the merged list
                break;
            case 'm':
                cout << "What value do you want to insert in the middle?\n";
                cin >> value;
                cout << "Where to insert, before which value?" << endl;
                cin >> beforeThis;

                //Todo by you
                break;
            case 'q':
                cout << "Exiting..." << endl;

                //Call the DeleteLinkedList() function to deallocate
                //all memory...
                ClearLinkedList(head);
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

    cout << "Displaying the list: " << endl;
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
void InsertAtFront(NodeType * & head, ItemType value)
{
    NodeType * p;

    p = new NodeType;

    p->value = value;
    p->next = head;

    head = p;
}

//Create a new node with the given value, and append it to the linked list
//given by the head pointer
void AppendInTheEnd(NodeType * & head, ItemType num)
{
    //Todo by you...
}

//Search for given value in the list pointed to by firstNodePtr
NodeType * Search (NodeType * firstNodePtr, ItemType value)
{
    NodeType * p;

    p = firstNodePtr;
    while(p!=NULL)
    {
        if(p->value == value)
            return p;
        p = p->next; //update p with the current node's next field
    }
    return p;
}

//Search for given value in the list pointed to by firstNodePtr
NodeType * Search (NodeType * firstNodePtr, ItemType value, NodeType * & prevNode)
{
    //Todo by you
}

//Delete the node storing the given value from the linked list
bool Delete(NodeType * & firstPtr, ItemType value)
{
    NodeType * prev, * cur;

    cur = Search(firstPtr, value, prev);
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
    //Todo by you...
}

NodeType * InitList (ItemType a[], int size)
{
    //Todo by you
}
