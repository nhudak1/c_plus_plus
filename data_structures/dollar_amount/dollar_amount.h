/* Nina Hudak
 * Header file for class DollarAmount: dollar_amount.h
 * Due date
 */

#undef DOLLAR_AMOUNT_H
#ifndef DOLLAR_AMOUNT_H
#define DOLLAR_AMOUNT_H

#include <iostream>
using namespace std;

class DollarAmount
{
    public:
        DollarAmount(); //Constructor

        //Overloaded Constructor
        //Params: dlr is dollar amount, cnt is cent amount
        //Precondition: 0 <= dlr <= 9999. 0 <= cnt <= 99
        //Postcondition: DollarAmount object is initialized
        DollarAmount(int dlr, int cnt);

        //Copy Constructor
        //d is an object DollarAmount that is already initialized
        DollarAmount(DollarAmount &d);

        //Takes in information from user and stores it as a DollarAmount object
        //Postcondition: If user doesn't enter . or cents, cents = 0.
        //               If user enters more than 2 decimal places, cents = 100
        //               Otherwise, dollar and cents initialized by user input
        void inputAmount(istream &in);

        //Outputs object in form of $dollar.cents
        void outputAmount(ostream &out);

        //Accesses the current value of dollar
        //Precondition: object must be initialized, and 0<dollar<9999
        //Postcondition: function returns dollar value as an integer
        int getDollar();

        //Accesses the current value of cents
        //Precondition: object must be initialized, and 0<cents<99
        //Postcondition: function returns cent value as an integer
        int getCent();

        //Changes the amount of dollar
        //Param: d is the dollaramount value that you want to set
        //       the new amount equal to
        //Precondition: d must be initialized
        //Postcondition: object is set to value d
        void setAmount(DollarAmount d);

        //Overload greater than operator to compare DollarAmount objects
        bool operator > (DollarAmount d);

        //Overload + operator to add DollarAmount objects
        DollarAmount operator + (DollarAmount d);

        //Overload / operator to divide DollarAmount objects by int num
        DollarAmount operator / (int num);
    private:
        int dollar, cents;
};

ostream &operator << (ostream &out, DollarAmount d);
istream &operator >> (istream &in, DollarAmount &d);
#endif
