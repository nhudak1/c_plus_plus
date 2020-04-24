/* Nina Hudak
 * HW 8 Part 3: Overload operator << so that a vector
 * can be printed by using cout << v << endl
 * March 25, 2019
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 20;
unsigned long int seed;

struct Node
{
    int integer;
    double value;
};

double random(unsigned long int &seed);

void initialize_vector(vector<Node> &v);

ostream &operator << (ostream &out, vector<Node> &v);

void output_vector(ostream &out, vector<Node> &v);

int main()
{
    vector<Node> v;
    initialize_vector(v);
    cout << v << endl;

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

void initialize_vector(vector<Node> &v)
{
    for(int i=0; i<SIZE; ++i)
    {
        Node temp;
        temp.integer = int(11*random(seed));
        temp.value = 10*random(seed);

        v.push_back(temp);
    }
}

ostream &operator << (ostream &out, vector<Node> &v)
{
    output_vector(out, v);
    return out;
}

void output_vector(ostream &out, vector<Node> &v)
{
    cout << setprecision(3) << fixed << showpoint;
    for(int i=0; i<SIZE; ++i)
    {
        cout << setw(2) << v[i].integer << " - ";
        cout << setw(3) << v[i].value << endl;
    }
}
