/* Nina Hudak
 * Write a program that creates a structure node
 * with fields int, double, and char, then creates
 * a vector of 10 structures with random values 
 * in all fields, and prints the vector of structures.
 * You must use function v.at(i) while accessing
 * elements of vector v, instead of [] operator.
 * March 6, 2019
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int UPPER_LIMIT = 10;
unsigned long int seed;

struct Node
{
    int n;
    double val;
    char ch;
};

double random(unsigned long int &seed);

void get_vector(vector<Node> &v);

void print_values(vector<Node> &v);

int main()
{
    vector<Node> v;
    get_vector(v);
    print_values(v);

    return 0;
}

double random(unsigned long int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed)+INCREMENT)%MODULUS;
    return double(seed)/MODULUS;
}

void get_vector(vector<Node> &v)
{
    Node temp;

    for(int i=0; i<UPPER_LIMIT; ++i)
    {
        temp.n = int(10*random(seed));
        temp.val = 5*random(seed);
        temp.ch = char(97 + 25*random(seed));
        v.push_back(temp);
    }
}

void print_values(vector<Node> &v)
{
    cout << "\n\tVector of Nodes:\n\n";
    cout << setw(6) << "Node" << setw(10) << "Integer";
    cout << setw(7) << "Value" << setw(5) << "Ch\n";
    cout << setprecision(4) << fixed << showpoint;

    for(int i=0; i<UPPER_LIMIT; ++i)
    {
        cout << setw(4) << i+1;
        cout << setw(8) << v.at(i).n;
        cout << setw(11) << v.at(i).val;
        cout << setw(4) << v.at(i).ch << endl;
    }
}

