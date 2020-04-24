/* Nina Hudak
 * HW 5: Write functions create_linked_structure and
 * delete_linked_structure to simplify lecture code
 * February 25, 2019
 */

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stddef.h>

using namespace std;

const int SIZE = 10;

struct Structure;

typedef Structure *structure_pointer;

struct Structure
{
    int f1;
    char f2;
    structure_pointer f3, f4;
};

structure_pointer get_structure(int n, char ch);

void print_structure(structure_pointer p);

void traverse_structure(structure_pointer p);

void create_linked_structure(structure_pointer p, structure_pointer q);

void delete_linked_structure(structure_pointer p, structure_pointer q);

int main()
{
    structure_pointer head, p, q;
    head = get_structure(1, 'a');
    q = head;
    create_linked_structure(p, q);
    traverse_structure(head);
    p = head;
    delete_linked_structure(p, q);
    return 0;
}

structure_pointer get_structure(int n, char ch)
{
    structure_pointer temp = new Structure;
    assert(temp != NULL);
    temp->f1 = n;
    temp->f2 = ch;
    temp->f3 = NULL;
    temp->f4 = NULL;
    return temp;
}

void print_structure(structure_pointer p)
{
    cout << endl;
    cout << "f1 = " << setw(2) << (*p).f1; 
    cout << " f2 = " << setw(2) << p->f2;
    cout << endl;
    return;
}

void traverse_structure(structure_pointer p)
{
    print_structure(p);
    if(p->f3 != NULL)
        traverse_structure(p->f3);
    return;
}

void create_linked_structure(structure_pointer p, structure_pointer q)
{
    for(int i=2; i<=SIZE; ++i)
    {
        p = get_structure(i, char('a'+i-1));
        q->f3 = p;
        q = q->f3;
    }
    cout << endl;
    cout << "Traversing the whole structure" << endl;
    return;
}

void delete_linked_structure(structure_pointer p, structure_pointer q)
{
    for(int i=1; i<SIZE; ++i)
    {
        q = p;
        p = p->f3;
        delete q;
    }
    cout << endl;
    return;
}
