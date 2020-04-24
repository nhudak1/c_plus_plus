/* Nina Hudak
 * Header file for class to do binary operations on complex numbers
 * April 11, 2019
 */

using namespace std;

class Complex
{
    public:
        void InputC(istream &in);
        void OutputC(ostream &out);
        Complex AddC(Complex x);
        Complex SubC(Complex x);
        Complex MultC(Complex x);
        Complex DivC(Complex x);
        Complex ExpC(int n);
    private:
        double real, imag;
};
