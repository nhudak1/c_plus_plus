/* Nina Hudak
 * Lab 5: Make array of 1000 structures with random values from
 * 0 - 6. Print out structure with max sum.
 * February 20, 2019
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 1000;

struct Structure
{
    int n1, n2, n3;
};

double random(unsigned long int &seed);

void generate_structures(Structure a[]);

int find_max_sum(Structure a[]);

void print_max_structures(Structure a[], int m);

int main()
{
    Structure array[SIZE];
    int max_sum;

    generate_structures(array);
    max_sum = find_max_sum(array);
    print_max_structures(array, find_max_sum(array));
    
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

void generate_structures(Structure a[])
{
    unsigned long int seed;

    for(int i=0; i<SIZE; ++i)
    {
        a[i].n1 = int(6*random(seed));
        a[i].n2 = int(6*random(seed));
        a[i].n3 = int(6*random(seed));
    }
    
    return;
}

int find_max_sum(Structure a[])
{
    int max_sum = 0, total;
    for(int i=0; i<SIZE; ++i)
    {
        total = a[i].n1 + a[i].n2 + a[i].n3;
        if(total > max_sum)
            max_sum = total;
    }

    return max_sum;
}

void print_max_structures(Structure a[], int m)
{
    cout << "The maximum sum is: " << m << endl;
    for(int i=0; i<SIZE; ++i)
    {
        if(a[i].n1 + a[i].n2 + a[i].n3 == m)
        {
            cout << setw(2) << a[i].n1 << " ";
            cout << setw(2) << a[i].n2 << " ";
            cout << setw(2) << a[i].n3 << endl;
        }
    }
}
