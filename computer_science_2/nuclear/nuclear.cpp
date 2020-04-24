/* Nina Hudak
 * Extra credit: Determine the thickness of nuclear reactor's wall
 * so less than 2% of neutrons escape.
 * March 4, 2019
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int MAX_COLLISIONS = 7;
const int NUM_NEUTRONS = 30000;
unsigned long int seed;

double random(unsigned long int &seed);

int main()
{
    double angle_entry, angle_deflect, d, tot_distance=0;
    int wall_width=0, neut_escape;

    //Outer loop determining if 2% of total neutrons are passing wall
    do
    {
        ++wall_width;
        neut_escape = 0;
        //Iterating through all neutrons
        for(int i=0; i<NUM_NEUTRONS; ++i)
        {
            angle_entry = -180 + 360*random(seed);

            //if neutron not within angle_entry, this next step irrelevant
            if(angle_entry>=-70.0 && angle_entry<=70.0)
            {
                //find total distance travelled by one neutron
                for(int j=1; j<MAX_COLLISIONS; ++j)
                {
                    do
                        angle_deflect = -170 + 340*random(seed);
                    while(angle_deflect<10 && angle_deflect>-10);

                    d = .6 + .7*random(seed);
                    tot_distance += d*cos(angle_deflect - angle_entry);
                }

                //keep track of how many neutrons travel through wall
                if(tot_distance > wall_width)
                    neut_escape++;
                tot_distance = 0;
            }
        }
    }while(double(neut_escape)/NUM_NEUTRONS > .02);

    cout << "Wall width: " << setw(3) << wall_width << endl;
}

double random(unsigned long int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed)+INCREMENT)%MODULUS;
    return double(seed)/MODULUS;
}
