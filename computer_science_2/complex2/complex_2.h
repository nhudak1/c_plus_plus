/* Nina Hudak
 * Header file for class to do binary operations on complex numbers
 * April 11, 2019
 */

using namespace std;

class Complex
{
    public:
        Complex() {}
        Complex(double init_real, double init_imag);
        void InputC(istream &in);
        void OutputC(ostream &out);
        Complex operator + (Complex x);
        Complex operator - (Complex x);
        Complex operator * (Complex x);
        Complex operator / (Complex x);
        Complex operator ^ (int n);
    private:
        double real, imag;
};

ostream &operator << (ostream &out, Complex x);
istream &operator >> (istream &in, Complex &x);

