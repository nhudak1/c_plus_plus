/* Nina Hudak
 * TreeType class implementation file: tree.cpp
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <assert.h>
#include <climits>
#include <cmath>
#include "tree.h"

using namespace std;

struct TreeNode
{
    ItemType info;
    TreeNode *left;
    TreeNode *right;
};


//Constructor
TreeType::TreeType()
{
    root = NULL;
}

void RecBalance(TreeNode *&tree, ItemType items[], int min, int max);

//Initialize the BST with items given in the array
//Does this by calling recursive function RecBalance()
//@param len: length of the array
//       items[]: array of items to initialize the tree with
//       min: the minimum index of the range of items[] being used
//       max: the maximum index of the range of items[] being used
//@pre: array must be sorted
//@post: a balanced array will be created
void TreeType::MakeBalanced(ItemType items[], int len)
{
    RecBalance(root, items, 0, len-1);
}

//Recursive function that creates a balanced tree from an array
//@param tree: tree node
//       items[]: array of items to initialize tree with
//       min: min index of the array to be used
//       max: max index of the array to be used
//@pre: array must be sorted
//@post: a balanced array will be created
void RecBalance(TreeNode *&tree, ItemType items[], int min, int max)
{
    int middle; //middle index of array
    
    if(min>max) //if mix exceeds max, we're done
        return;

    middle = (max+min)/2;
    
    if(tree == NULL)  
        tree = new TreeNode;
    tree->info = items[middle]; //Assign current node to be the middle element
    RecBalance(tree->left, items, min, middle-1); //give elements before middle to left
    RecBalance(tree->right, items, middle+1, max); //give elements after middle to right
    
}

//Returns true if there is no room for another item on the free store
//        false otherwise
bool TreeType::IsFull() const
{
    TreeNode *location;
    try
    {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

//Returns true if the tree is empty; false otherwise
bool TreeType::IsEmpty() const
{
    return root == NULL;
}

int CountNodes(TreeNode *tree);

//Calls recursive function CountNodes to count the nodes in the tree
int TreeType::GetLength() const
{
    return CountNodes(root);
}

//Return the height of the tree
int TreeType::Height() const
{
    return (GetHeightSubTree(root));
}

//Post: returns the number of nodes in the tree
int CountNodes(TreeNode *tree)
{
    if(tree == NULL)
        return 0;
    else
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode *tree, ItemType &item, bool &found);

//Calls recursive function Retrieve to search the tree for item
ItemType TreeType::GetItem(ItemType item, bool &found) const
{
    Retrieve(root, item, found);
    return item;
}

//Recursively searches tree for item
//Post: If there's an element someItem whose key matches item's, then
//      found is true and item is set to a copy of someItem;
//      otherwise found is false and item is unchanged
void Retrieve(TreeNode *tree, ItemType &item, bool &found)
{
    if(tree == NULL)
        found = false;  //item is not found
    else if(item < tree->info)
        Retrieve(tree->left, item, found);  //Search left subtree
    else if(item > tree->info)
        Retrieve(tree->right, item, found); //Search right subtree
    else
    {
        item = tree->info;                  //item is found
        found = true;
    }
}

void Insert(TreeNode *&tree, ItemType item);

//Calls recursive function Insert to insert item into tree
void TreeType::PutItem(ItemType item)
{
    Insert(root, item);
}

//Inserts item into tree
//Post: item is in tree; search property is maintained
void Insert(TreeNode *&tree, ItemType item)
{
    if(tree==NULL)  //Insertion place is found
    {
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if(item < tree->info)
        Insert(tree->left, item);   //Insert in left subtree
    else
        Insert(tree->right, item);  //Insert in right subtree
}

void DeleteNode(TreeNode *&tree);

void Delete(TreeNode *&tree, ItemType item);

//Calls recursive function Delete to delete item from tree
void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}

//Deletes item from tree
//Post: item is not in the tree
void Delete(TreeNode *&tree, ItemType item)
{
    if(item < tree->info)
        Delete(tree->left, item); //look in left subtree
    else if(item > tree->info)
        Delete(tree->right, item); //look in right subtree
    else
        DeleteNode(tree);   //Node found, call DeleteNode
}

void GetPredecessor(TreeNode *tree, ItemType &data);

void GetSuccessor(TreeNode *tree, ItemType &data);

//Deletes the node pointed to by tree
//Post: the user's data in the node pointed to by tree is no longer in
//      the tree. If tree is a leaf node or has only non-NULL child pointer
//      the node pointed to by tree is deleted. Otherwise, the user's data is
//      replaced by its logical successor and the successor's node is
//      deleted
//      CHECK THIS FUNCTION
void DeleteNode(TreeNode *&tree)
{
    ItemType data;
    TreeNode *tempPtr;

    tempPtr = tree;
    if(tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        GetSuccessor(tree->right, data); //get smallest value in right tree
        tree->info = data;
        Delete(tree->right, data); //Delete successor node
    }
}

//Sets data to the info member of the right-most node in the tree
void GetPredecessor(TreeNode *tree, ItemType &data)
{
    while(tree->right != NULL)
        tree = tree->right;
    data = tree->info;
}

//Sets data to the info member of the left-most node in the tree
void GetSuccessor(TreeNode *tree, ItemType &data)
{
    while(tree->left != NULL)
        tree = tree->left;
    data = tree->info;
}

//Prints info member of items in tree in sorted order on outFile
void PrintTree(TreeNode *tree, std::ofstream &outFile)
{
    if(tree != NULL)
    {
        PrintTree(tree->left, outFile); //Print left subtree
        outFile << tree->info;
        PrintTree(tree->right, outFile); //Print right subtree
    }
}

//Calls recursive function Print to print items in the tree
void TreeType::Print(std::ofstream &outFile) const
{
    PrintTree(root, outFile);
}

void Destroy(TreeNode *&tree);

//Calls recursive function Destroy to destroy the tree
TreeType::~TreeType()
{
    Destroy(root);
}

//Post: tree is empty, nodes have been deallocated
void Destroy(TreeNode *&tree)
{
    if(tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

void TreeType::MakeEmpty()
{
    Destroy(root);
    root = NULL;
}

void CopyTree(TreeNode *&copy, const TreeNode *originalTree);

//Calls recursive function CopyTree to copy originalTree into root
TreeType::TreeType(const TreeType &originalTree)
{
    CopyTree(root, originalTree.root);
}

//Calls recursive function CopyTree to copy originalTree into root
void TreeType::operator = (const TreeType &originalTree)
{
    {
        if(&originalTree == this)
            return; //ignore assigning self to self
        Destroy(root);
        CopyTree(root, originalTree.root);
    }
}

//Post: copy is the root of a tree that is a duplicate of originalTree
void CopyTree(TreeNode *&copy, const TreeNode *originalTree)
{
    if(originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

//Function prototypes for auxiliary functions

//Enqueues tree items in preorder
void PreOrder(TreeNode*, QueType&);

//Enqueues tree items in inorder
void InOrder(TreeNode*, QueType&);

//Enqueues tree items in postorder
void PostOrder(TreeNode*, QueType&);

//Calls function to create a queue of the tree elements in the
//desired order
void TreeType::ResetTree(OrderType order)
{
    switch(order)
    {
        case PRE_ORDER:
            PreOrder(root, preQue);
            break;
        case IN_ORDER:
            InOrder(root, inQue);
            break;
        case POST_ORDER:
            PostOrder(root, postQue);
            break;
    }
}

//Post: preQue contains the tree items in preorder
void PreOrder(TreeNode* tree, QueType& preQue)
{
    if(tree != NULL)
    {
        preQue.Enqueue(tree->info);
        PreOrder(tree->left, preQue);
        PreOrder(tree->right, preQue);
    }
}

//Post: inQue contains the tree items in inorder
void InOrder(TreeNode* tree, QueType& inQue)
{
    if(tree != NULL)
    {
        InOrder(tree->left, inQue);
        inQue.Enqueue(tree->info);
        InOrder(tree->right, inQue);
    }
}

//Post: postQue contains the tree items in postorder
void PostOrder(TreeNode* tree, QueType& postQue)
{
    if(tree != NULL)
    {
        PostOrder(tree->left, postQue);
        PostOrder(tree->right, postQue);
        postQue.Enqueue(tree->info);
    }
}

//Returns the next item in the desired order
//Post: For the desired order, item is the next item in the queue.
//      If item is the last one in the queue, finished is true;
//      otherwise finished is false
ItemType TreeType::GetNextItem(OrderType order, bool &finished)
{
    finished = false;
    ItemType item;

    switch(order)
    {
        case PRE_ORDER:
            preQue.Dequeue(item);
            if(preQue.IsEmpty())
                finished = true;
            break;
        case IN_ORDER:
            inQue.Dequeue(item);
            if(inQue.IsEmpty())
                finished = true;
            break;
        case POST_ORDER:
            postQue.Dequeue(item);
            if(postQue.IsEmpty())
                finished = true;
            break;
    }
    return item;
}

//Return the height of the tree given by the rootNode
//height of a tree is defined to be the deepest level of the tree
int TreeType::GetHeightSubTree(TreeNode *subTreeRoot)
{
    if(subTreeRoot == NULL)
        return 0;
    else
    {
        int left = GetHeightSubTree (subTreeRoot->left);
        int right = GetHeightSubTree (subTreeRoot->right);
        if(left<=right)
            return right+1;
        else
            return left+1;
    }
}


//-----------------------------
//Pretty Print
//Store the nodes at the depth-level of the tree (given at root) in the vector of vals
//@pre: root != NULL, depth >= 0
void TreeType::getLine(TreeNode *subTreeRoot, int depth, vector<char> &vals)
{
    assert(subTreeRoot != NULL && depth >= 0);

    if(depth == 0) //base case
        vals.push_back(subTreeRoot->info);
    else    //General case
    {
        if(subTreeRoot->left != NULL)
            getLine(subTreeRoot->left, depth-1, vals);
        else //EZ if (depth-1<=0)
        {
            int cnt = 1;
            for(int i=0; i<depth-1; i++)
                cnt*=2;
            for(int i=0; i<cnt; i++)
                vals.push_back('#');
        }

        if(subTreeRoot->right != NULL)
            getLine(subTreeRoot->right, depth-1, vals);
        else //if(depth-1<=0)
        {
            int cnt = 1;
            for(int i=0; i<depth-1; i++)
                cnt*=2;
            for(int i=0; i<cnt; i++)
                vals.push_back('#');
        }
    }
}

void TreeType::printRow(TreeNode *p, int height, int depth)
{
    vector<char> vec;

    getLine(p, depth, vec);

    cout << setw((height-depth)*2); //scale setw with depth
    bool toggle = true; //start with left
    if (vec.size() > 1)
    {
        for (int i=0; i<vec.size(); i++)
        {
            if(vec[i] != ' ') 
            {
                if (toggle)
                    cout << "/" << "   ";
                else
                    cout << "\\" << "   "; //this will display
            }
            toggle = !toggle;
        }
        cout << endl;
        cout << setw((height-depth)*2);
    }
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] != ' ')
            cout << vec[i] << "   ";
    }
    cout << endl;
}

void TreeType::SimplePrintRow(TreeNode *p, int height, int depth)
{
    vector<char> vec;

    getLine(p, depth, vec);

    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] != ' ')
            cout << vec[i];
        else
        {
            assert(false);
            cout << "# ";
        }
    }
    cout << endl;
}

void TreeType::PrettyPrint() const
{
    int height = GetHeightSubTree(root); //*2
    for(int i=0; i<=height; i++)
        printRow(root, height, i);
}

void TreeType::SimplePrettyPrint() const
{
    int height = GetHeightSubTree(root); //*2
    for(int i=0; i<=height; i++)
        SimplePrintRow(root, height, i);
}

//End of pretty print -----------------------------------------



bool FullTree(TreeNode *tree);

//Test whether tree is full or not. A full binary tree is one where
//every node in the tree has 0 or 2 children
//Does this by calling recursive function FullTree()
//@return: true if the tree is a full tree, false otherwise
bool TreeType::IsFullTree()
{
    return FullTree(root);
}

//Recursive function that searches tree to determine if tree is full
//@return: true if the tree is a full tree, false otherwise
bool FullTree(TreeNode *tree)
{
    if(tree == NULL) //Empty node base case
        return true;
    else if(tree->left == NULL && tree->right == NULL) //Leaf base case -- could be full
        return true;
    else if(tree->left != NULL && tree->right != NULL) //2 children -- keep searching
        return FullTree(tree->left) && FullTree(tree->right); //search left and right
    else //one child -- not a full tree
        return false;
}

bool BST(TreeNode *tree, int min, int max);

//Test if tree is a binary search tree (everything to left is smaller
//and everything to the right is bigger)
//Do this by calling recursive function BST()
//@return: true if the tree is a BST, false otherwise
bool TreeType::IsBST()
{
    return BST(root, INT_MIN, INT_MAX);
}

//Recursive function that determines if tree is a binary search tree
//@param: tree is the current node of the tree
//        min is the current minimum of the acceptable range for the next value
//        max is the current maximum of the acceptable range for the next value
//@return: true if the tree is a BST, false otherwise
bool BST(TreeNode *tree, int min, int max)
{
    //Base case -- if the current node is null, then we made it to the end
    //of a path with no errors. return true
    if(tree == NULL)
        return true;

    //if value outside of acceptable range, then it's not a binary search tree
    if(tree->info < min || tree->info > max)
        return false;

    //Smaller case:
    //If the tree isn't null or it isn't incorrect, keep searching
    //Search left branch: new max value is current node value bc everything
    //                    to the left must be smaller than the current value
    //Search right branch: new min value is current node value bc everything
    //                     to the right must be larger than the current value
    return BST(tree->left, min, tree->info) && BST(tree->right, tree->info, max);
}


int NodesAtLevelRec(TreeNode *tree, QueType &q, int curLevel, int goalLevel);

//Function returns the number of nodes in the given level through recursive function
//NodesAtLevelRec()
//@param: itemArray[0...] stores the items values
//        level is the current level of the tree
//@pre: level >= 0 
//@return: number of nodes in given level
int TreeType::GetNodesAtLevel(ItemType *&itemArray, int level)
{
    //length of row can be at most 2^level
    int curLevel = 0, index=0, length = pow(2, level);
    ItemType item;
    QueType q; //Queue that will store items from the tree row
    itemArray = new ItemType[length];
    int nodes = NodesAtLevelRec(root, q, curLevel, level);
    while(!q.IsEmpty()) //Put values of q into an array
    {
        q.Dequeue(item);
        itemArray[index] = item;
        index++;
    }
    return nodes;
}

//Recursive function that returns number of nodes in a level of a tree and fills an array
//with those values
//@param: tree is the current TreeNode
//        q stores the items in the level of the tree
//        curLevel is the current level being searched
//        goalLevel is the level we want to analyze
//@pre: goalLevel >= 0
//@post: q will store the values of the given level of the tree
//@return: number of nodes in the given level of the tree
int NodesAtLevelRec(TreeNode *tree, QueType &q, int curLevel, int goalLevel)
{
    //if tree is null before we reach desired level, return 0
    if(tree == NULL)
        return 0;
    //if we reach the desired level, add item to q and return 1 to count the node
    if(curLevel == goalLevel)
    {
        q.Enqueue(tree->info);
        return 1;
    }
    //if we curLevel != goalLevel and the tree is not null, then we need to keep going
    //Search left node and right node
    //Increment curLevel each time
    return NodesAtLevelRec(tree->left, q, curLevel+1, goalLevel)
        + NodesAtLevelRec(tree->right, q, curLevel+1, goalLevel);
}

void PrintAncestorsRec(TreeNode *tree, ItemType value);

//Display the items stored in the parent of the node, the granparent, and so on starting from
//root (ancestor of all nodes), ... all the way to the parent of the node
//Calls recursive function PrintAncestorsRec()
void TreeType::PrintAncestors(ItemType value)
{
    PrintAncestorsRec(root, value);
}

//Recursive function that prints out all ancestors of a given value
//@param: tree is a current TreeNode of a tree
//        value is the value whose ancestors we want to print
//@pre: value exists in the tree
//@post: the root all the way to the parent are printed. The actual value is not printed
void PrintAncestorsRec(TreeNode *tree, ItemType value)
{
    //if tree is empty
    if(tree == NULL)
        return;

    if(tree->info == value) //If we reach the value, just print an endl
        std::cout << "\n";
    if(tree->info < value) //if tree->info too small, print it and go to right branch
    {
        std::cout << tree->info << " ";
        PrintAncestorsRec(tree->right, value);
    }
    if(tree->info > value) //if tree->info too big, print it and go to left branch
    {
        std::cout << tree->info << " ";
        PrintAncestorsRec(tree->left, value);
    }
}

void GetSmallestRec(TreeNode *tree, ItemType &smallest);

//Gets the smallest item stored in the tree
//@pre: tree must have at least 1 value
//@post: smallest is initialized to the smallest value in the tree
//Calls recursive function GetSmallestRec()
void TreeType::GetSmallest(ItemType &smallest) const
{
    GetSmallestRec(root, smallest);
}

//Recursive function that finds smallest item stored in tree
//@params: tree is a TreeNode of the tree
//         smallest is a reference variable that will hold the smallest value
//@pre: tree must have at least 1 value
//@post: smallest will be initialized to smallest value in the tree
void GetSmallestRec(TreeNode *tree, ItemType &smallest)
{
    if(tree != NULL)
    {
        smallest = tree->info;
        GetSmallestRec(tree->left, smallest);
    }
}






