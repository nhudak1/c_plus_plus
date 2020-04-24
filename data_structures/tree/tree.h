/* Nina Hudak
 * TreeType class header file: tree.h
 */

//#undef TREE_H
#ifndef TREE_H
#define TREE_H

#include <string>
#include <fstream>
#include <vector>
#include "queue.h"

using namespace std;

typedef char ItemType;
struct TreeNode;
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
    public:
        TreeType(); //Constructor
        ~TreeType(); //Destructor
        TreeType(const TreeType &originalTree); //Copy Constructor
        void operator = (const TreeType &originalTree); //Assignment operator

        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        int GetLength() const;
        int Height() const;

        ItemType GetItem(ItemType item, bool &found) const;
        void PutItem(ItemType item);
        void DeleteItem(ItemType item);
        void MakeBalanced(ItemType items[], int len);    //Function to make a balanced tree
                                                //Couldn't be a constructor in my program
                                                //because i'm using it in a switch statement
                                                //and objects cannot be declared in switches


        void ResetTree(OrderType order);
        ItemType GetNextItem(OrderType order, bool &finished);

        void Print(std::ofstream &outFile) const;
        void PrettyPrint() const;
        void SimplePrettyPrint() const;

        //New functions
        bool IsFullTree();
        bool IsBST();
        int GetNodesAtLevel(ItemType *&itemArray, int level);
        void PrintAncestors(ItemType value);
        void GetSmallest(ItemType &smallest) const;
    private:
        TreeNode *root;
        QueType preQue;
        QueType inQue;
        QueType postQue;

        static int GetHeightSubTree(TreeNode * subTreeRoot);

        static void getLine(TreeNode *root, int depth, vector<char> &vals);
        static void printRow(TreeNode *p, int height, int depth);
        static void SimplePrintRow(TreeNode *p, int height, int depth);
};

#endif

