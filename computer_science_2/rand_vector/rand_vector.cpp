/* Nina Hudak
 * HW 7: Declare a 2D vector with random rows between
 * [3, 5] and random ints in each row from [0, 10].
 * Use print_vector to print v.
 * March 14, 2019
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

unsigned long int seed;

double random(unsigned long int &seed);

void initialize_vector(vector<vector<int>> &v);

void print_vector(vector<vector<int>> &v);

int main()
{
    vector<vector<int>> v;
    initialize_vector(v);
    print_vector(v);

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

void initialize_vector(vector<vector<int>> &v)
{
    for(int i=0; i < int(3 + 3*random(seed)); ++i)
    {
        vector<int> temp;
        for(int j=0; j < int(1 + 10*random(seed)); ++j)
            temp.push_back(int(11*random(seed)));
        v.push_back(temp);
    }
}

void print_vector(vector<vector<int>> &v)
{
    cout << endl;

    for(int i=0; i<v.size(); ++i)
    {
        for(int j=0; j<v[i].size(); ++j)
            cout << setw(4) << v[i][j];
        cout << endl;
    }

    cout << endl;
}
