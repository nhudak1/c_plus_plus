/* Nina Hudak
 * Appointment class implementation file: appointment.cpp
 * September 25, 2019
 */

#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include "appointment.h"
using namespace std;

//"Default" constructor
Appointment::Appointment()
{
    month = 0;
    day = 0;
    year = 0;
    description = "";
}

//Overloaded Constructor
Appointment::Appointment(int m, int d, int y, string des)
{
    month = m;
    day = d;
    year = y;
    description = des;
}

//Copy Constructor
Appointment::Appointment(const Appointment &a)
{
    month = a.month;
    day = a.day;
    year = a.year;
    description = a.description;
}

//Accept Appointment as input
void Appointment::inputAppointment(istream &in)
{
    const int TOTAL_DATE_LENGTH = 5; //"length" of date (ie m/d/y)
    char slash;
    int next_input, counter;
    string temp;

    in >> month; //first input will be int representing month

    if(cin.fail()) //If user enters wrong input
    {
        in.clear();
        in.ignore(2048, '\n');
        month = 13; //Set month = 13 so that it will be caught in main file
                    //as out of range and wrong_input will be triggered to
                    //equal true
        return;
    }

    counter = 1; //Counter is variable keeping track of how many places
                 //we have stored for the date. Right now it is one because
                 //we have already stored month.
                
    //if month==13, then it may have undergone the previous block of 
    //code, in which case, day and year won't be initialized. So if month==13,
    //don't enter while loop.
    //Loop through the places of the date
    while(counter < TOTAL_DATE_LENGTH && month != 13)
    {
        counter++;

        next_input = in.peek(); //Look at next char to see if it exists
        
        //if next input is space then user didn't enter a necessary field (error)
        if(isspace(next_input))
            month = 13; //set month = 13 to trigger wrong_input = true in main
        //if next_input isn't a space...
        else
        {
            //...it must be a slash or an int
            if(counter%2==0) //if counter is even the input must be a slash
                in >> slash;
            else if(counter == 3)
                in >> day;
            else
                in >> year;
        }
    }

    next_input = in.peek();

    description = "";

    //If next_input isn't a new line, user entered description -- start loop.
    //Otherwise, user didn't enter description so description will remain
    //empty string.
    while(next_input != 10)
    {
        //Determine if theres another word. If there is, update description.
        in >> temp;
        description = description + temp + " ";
        next_input = in.peek();
    }
}


//Output Appointment
void Appointment::outputAppointment(ostream &out)
{
    //If month < 10, output 0 for better formatting (ie 1 vs 01)
    if(month < 10)
        cout << "0";
    cout << month << "/";
    //Same formatting for day
    if(day < 10)
        cout << "0";
    cout << day << "/" << year << " " << description;
}

//Determines if a date is valid
bool Appointment::wrongInput()
{
    bool error;

    //If month is less than 1 or greater than 12, the date doesn't exist
    if(month <= 0 || month >= 13)
        error = true;
    //If the day is less than one then the date doesn't exist
    else if(day<1)
        error = true;
    //If the month should have a max of 31 days and day is greater than 31,
    //then the date doesn't exist
    else if(((month<8 && month%2==1) || (month>7 && month%2==0)) && day>31)
        error = true;
    //If the month is February and the day is greater than 28...
    else if(month==2 && day>28)
    {
        //...if it's a leap year and day==29, then the date is valid
        if(year%4==0 && day == 29)
            error = false;
        //...otherwise, the date doesn't exist
        else
            error = true;
    }
    //If the month should have a max of 30 days and the day>30, then the
    //date doesn't exist
    else if(((month<8 && month%2==0) || (month>7 && month%2==1)) && day>30)
        error = true;
    //Otherwise, the date is valid
    else
        error = false;

    return error;
}

//Return month value
int Appointment::getMonth()
{
    return month;
}

//Return day value
int Appointment::getDay()
{
    return day;
}

//Return year value
int Appointment::getYear()
{
    return year;
}

//Return description value
string Appointment::getDescription()
{
    return description;
}


//Compares the time frame of two Appointment objects
char Appointment::ComparedTo(Appointment a)
{
    char comparison;

    //If year1>year2, then Appointment1 is greater than Appointment2
    if(year > a.year)
        comparison = '>';
    //Else if the years are equal but month1>month2, then Appointment1
    //is greater than Appointment2
    else if(year == a.year && month > a.month)
        comparison = '>';
    //Else if the years and months are equal but day1>day2 then Appointment1
    //is greater than Appointment2
    else if(year == a.year && month == a.month && day > a.day)
        comparison = '>';
    //Else if the years, months, and days are equal, then Appointment1 equals
    //Appointment2
    else if(year == a.year && month == a.month && day == a.day)
        comparison = '=';
    //Otherwise, Appointment1 is less than Appointment2
    else
        comparison = '<';
    return comparison;
}

//Overload assignment operator
void Appointment::operator = (Appointment a)
{
    month = a.month;
    day = a.day;
    year = a.year;
    description = a.description;
}

//Overload << operator to output an Appointment object
ostream &operator << (ostream &out, Appointment a)
{
    a.outputAppointment(out);
    return(out);
}

//Overload >> operator to input an Appointment object
istream &operator >> (istream &in, Appointment &a)
{
    a.inputAppointment(in);
    return(in);
}

