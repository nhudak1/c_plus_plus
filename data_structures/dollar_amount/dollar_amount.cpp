/* Nina Hudak
 * DollarAmount class implementation file: dollar_amount.cpp
 * September 25, 2019
 */

#include <iostream>
#include <cctype>
#include <cmath>
#include "dollar_amount.h"
using namespace std;

const int MAX_DECIMAL_PLACES = 2;

//"Default" constructor
DollarAmount::DollarAmount()
{
    dollar = 0;
    cents = 0;
}

//Constructor
//Params: dlr is dollar amount, cnt is cent amount
//Precondition: 0 <= dlr <= 9999. 0 <= cnt <= 99
//Postcondition: DollarAmount object is initialized
DollarAmount::DollarAmount(int dlr, int cnt)
{
    dollar = dlr;
    cents = cnt;
}

//Copy Constructor
DollarAmount::DollarAmount(DollarAmount &d)
{
    dollar = d.dollar;
    cents = d.cents;
}

//Accept DollarAmount as input
void DollarAmount::inputAmount(istream &in)
{
    char decimal, temp;
    int next_input, decimal_count;

    in >> dollar; //first input will be int representing dollar
    if(cin.fail()) //If user enter wrong input
    {
        in.clear();
        in.ignore(2048, '\n');
        dollar = 10000; //This block of code had to be included in this function
                        //to work, so wrong_input in the main file can't be set
                        //to true. Instead, set dollar = 10000 so that it will be
                        //caught in main file as out of range and wrong_input will
                        //be triggered to equal true
        return;
    }


    next_input = in.peek(); //Look at next char to see if it exists

    //If the next character is a space, user didn't enter anything else.
    //So set cents to 0
    if(isspace(next_input))
        cents = 0;
    //If the next character isn't a space...
    else
    {
        //...it must logically be a decimal.
        in >> decimal;
        next_input = in.peek(); //Look at next character
        decimal_count = 0;
        cents = 0; //give cents an initial value

        //while the next character exists...
        while(!isspace(next_input))
        {
            decimal_count++; //keep track of amount of decimal places
            in >> temp; //store character in temp bc in.peek() can't see past next character
                        //that hasn't yet been cin-ed.
            //if the amount of decimal places is <= 2
            if(decimal_count <= MAX_DECIMAL_PLACES)
                //then add temp ^ (2-decimal_count) to cents
                //subtract 48 from temp bc temp is currently an ascii code and subtracting
                //48 gives the true amount of temp
                //by keeping track of each digit of the cents one by one, we can
                //properly keep track of amount of decimal places
                //(i.e. if user enters .5 vs .05, they would both be stored as 5 in an int)
                cents += (int(temp)-48) * pow(10, MAX_DECIMAL_PLACES-decimal_count);
            else
                //if number of decimal places exceeds 2, set cents to something that has
                //more than max number of decimal places. This way, .005 won't be
                //seen as 5 and still be accepted in program.. 
                cents = pow(10,MAX_DECIMAL_PLACES + 1);
            next_input = in.peek();//Look at next char
        }
    }
}

//Output DollarAmount
void DollarAmount::outputAmount(ostream &out)
{
    cout << '$' << dollar << '.';
    //Ensure that any cents less than 10 are outputted correctly
    //(i.e. 1 cent isn't outputted as .1)
    if(cents > 9)
        cout << cents;
    else
        cout << "0" << cents;
}

//Set a DollarAmount object equal to preexisting DollarAmount object
void DollarAmount::setAmount(DollarAmount d)
{
    dollar = d.dollar;
    cents = d.cents;
}

//Return dollar amount
int DollarAmount::getDollar()
{
    return dollar;
}

//Return cents amount
int DollarAmount::getCent()
{
    return cents;
}

//Overload > operator to compare two DollarAmount objects
bool DollarAmount::operator > (DollarAmount d)
{
    bool greater_than;

    //If dollar1>dollar2, then DollarAmount1 is greater than DollarAmount2
    if(dollar > d.dollar)
        greater_than = true;
    //Else if the dollars are equal but cents1>cents2, then DollarAmount1
    //is greater than DollarAmount2
    else if(dollar == d.dollar && cents > d.cents)
        greater_than = true;
    //Otherwise, DollarAmount2 is greater than DollarAmount1
    else
        greater_than = false;
    return greater_than;
}

//Overload + operator to add two DollarAmount objects
DollarAmount DollarAmount::operator + (DollarAmount d)
{
    DollarAmount temp;
    int extra_cents;

    //Add cents together and mod by 100 in case added cents exceed 100
    temp.cents = (cents + d.cents) % 100;
    //If cents exceed 100, convert the exceeding cents to dollars
    extra_cents = (cents + d.cents) / 100;
    //Add dollars + any extra cents that became full dollars
    temp.dollar = dollar + d.dollar + extra_cents;
    return temp;
}

//Overload / operator to divide DollarAmount object by an integer
DollarAmount DollarAmount::operator / (int num)
{
    DollarAmount temp;
    int remaining_cents;

    //Divide dollar by integer
    temp.dollar = dollar / num;
    //If dollar doesn't divide evenly, put the excess into cents
    remaining_cents = (dollar%num) * 100;
    //Divide cents + the cents left over from the dollar by the integer
    temp.cents = (cents + remaining_cents) / num;

    return temp;
}

//Overload << operator to output a DollarAmount object
ostream &operator << (ostream &out, DollarAmount d)
{
    d.outputAmount(out);
    return(out);
}

//Overload >> operator to input a DollarAmount object
istream &operator >> (istream &in, DollarAmount &d)
{
    d.inputAmount(in);
    return(in);
}
