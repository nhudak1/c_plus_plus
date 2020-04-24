/* Nina Hudak
 * Test Driver
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cmath>

#include "tree.h"

using namespace std;

void sort(char arr[], int size);

int main()
{
    char command;   //operation to be executed

    char item, ret, smallest;
    char words[26];
    char *row;
    string orderItem, str;
    TreeType tree;
    TreeType balanced;
    OrderType order;
    bool found;
    bool finished;
    int numCommands, count, level, num;

    do
    {
        cout << "Menu:\n";
        cout << "---------------------------------\n";
        cout << "A: PutItem\n";
        cout << "D: DeleteItem\n";
        cout << "S: GetItem\n";
        cout << "I: info, length, isFull, height...\n";
        cout << "P: PrintTree\n";
        cout << "Q: SimplePrintTree\n";
        cout << "R: (Iterator) ResetTree, GetNextItem\n";
        cout << "C: MakeEmpty\n";
        cout << "B: Build tree from array\n";
        cout << "G: GetNodesAtLevel\n";
        cout << "N: PrintAncestors\n";
        cout << "M: GetSmallest\n";
        cout << "O: Create a balanced BST from an array\n";
        cout << "E: Quit\n";
        cout << "---------------------------------\n";
        
        cout << "\nChoose what to do: ";
        cin >> command;

        switch(command)
        {
            case 'B': //Build tree from array
                cout << "Enter a string of chars to build a tree: ";
                cin >> str;

                tree.MakeEmpty();
                for(int i=0; i<str.length(); i++)
                {
                    ret = tree.GetItem(str[i], found);
                    if(!found)
                        tree.PutItem(str[i]);
                }
                break;
            case 'A': //Add item to tree
                cout << "Enter a char to insert: ";
                cin >> item;

                item = tree.GetItem(item, found);
                if(found)
                    cout << item << " already in list." << endl;
                else 
                {
                    tree.PutItem(item);
                    cout << item;
                    cout << " is inserted" << endl;
                }
                break;
            case 'D': //Delete item from tree
                cout << "Enter a char to delete: ";
                cin >> item;
                tree.DeleteItem(item);
                cout << item;
                cout << " is deleted" << endl;
                break;
            case 'S':
                cout << "Enter a char to search: ";
                cin >> item;

                item = tree.GetItem(item, found);
                if(found)
                    cout << item << " found in list." << endl;
                else
                    cout << item << " not in list." << endl;
                break;
            case 'I': //Information about tree
                cout << "Number of nodes is " << tree.GetLength() << endl;
                cout << "Height of tree is " << tree.Height() << endl;

                if(tree.IsEmpty())
                    cout << "Tree is empty." << endl;
                else
                    cout << "Tree is not empty." << endl;
                if(tree.IsFull())
                    cout << "Tree is full." << endl;
                else
                    cout << "Tree is not full." << endl;
                if(tree.IsFullTree())   //Testing IsFullTree()
                    cout << "Tree is a full tree (each node has 0 or 2 children\n";
                else
                    cout << "Tree is not a full tree - a node has 1 child\n";
                if(tree.IsBST())    //Testing IsBST()
                    cout << "Tree is binary search tree" << endl;
                else
                    cout << "Tree is not binary search tree" << endl;
                break;
            case 'P': //Pretty Print
                tree.PrettyPrint();
                cout << endl;
                break;
            case 'Q': //Simple Pretty Print
                tree.SimplePrettyPrint();
                cout << endl;
                break;
            case 'R': //Iterators
                do
                {
                    cout << "Traversal order (preorder, inorder, or postorder): ";
                    cin >> orderItem;
                }   while(orderItem!="preorder" && orderItem!="inorder" && orderItem!="postorder");
                if(orderItem == "preorder")
                    order = PRE_ORDER;
                else if(orderItem == "inorder")
                    order = IN_ORDER;
                else
                    order = POST_ORDER;

                cout << "Traversing nodes in the given order: ";
                tree.ResetTree(order);
                do
                {
                    item = tree.GetNextItem(order, finished);
                    cout << item << " ";
                }   while(!finished);
                cout << endl;
                break;
            case 'C': //Make Empty
                tree.MakeEmpty();
                cout << "Tree has been made empty" << endl;
                break;
            case 'G': //GetNodesAtLevel
                do //Do while loop to prompt user for a level > 0
                {
                    cout << "Which level would you like to look at starting at 0?: ";
                    cin >> level;
                    if(level < 0)
                        cout << "Level must be greater than or equal to zero\n";
                }   while(level < 0);

                num = tree.GetNodesAtLevel(row, level); //Invoke GetNodesAtLevel

                cout << "At level " << level << ", there are " << num << " nodes.\n";
                cout << "Items in row: ";
                for(int i=0; i<num; i++)
                    cout << row[i] << " ";
                cout << endl;
                delete[] row; //Deallocate memory
                break;
            case 'N': //Print Ancestors
                do  //Do while loop to prompt user for item that exists in tree
                {
                    cout << "Enter a value in the tree: ";
                    cin >> item;
                    ret = tree.GetItem(item, found);
                    if(!found)
                        cout << "Item is not in tree" << endl;
                }   while(!found);

                cout << "Ancestors of " << item << ": "; //Output ancestors
                tree.PrintAncestors(item);
                break;
            case 'M': //Smallest value in tree
                cout << "The smallest value in the tree is: ";
                tree.GetSmallest(smallest);
                cout << smallest << endl;
                break;
            case 'O': //Build balanced tree from an array
                cout << "Enter a string: ";
                cin >> str;
                count = 0;
                do //put string into array
                {
                    words[count] = str[count];
                    count++;
                }   while(str[count] != '\0');

                sort(words, count); //sort array

                balanced.MakeBalanced(words, count); //make a balanced tree from array
                
                cout << "Balanced tree: " << endl; //Print tree
                balanced.PrettyPrint();

                balanced.MakeEmpty();
                break;
            case 'E':
                cout << "Ok, Exiting\n";
                break;
            default:
                cout << "Command not recognized" << endl;
        }
    }   while(command != 'E');

}

//Function sorts an array
//@params arr: array to be sorted
//        size: size of array
//@post: array is sorted
void sort(char arr[], int size)
{
    char temp;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
