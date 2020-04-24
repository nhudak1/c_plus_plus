/* Nina Hudak
 * Header file for class Appointment: appointment.h
 * Due date
 */

using namespace std;

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

class Appointment
{
    public:
        //"Default" constructor
        Appointment();

        //Overloaded Constructor
        //Params: m is month, d is day, y is year, des is description
        //Precondition: 1 <= m <= 12. 1 <= d <= 31.
        //Postcondition: Appointment object is initialized
        Appointment(int m, int d, int y, string des);

        //Copy Constructor
        //a is an Appointment object that is already initialized
        Appointment(const Appointment &a);

        //Takes in information from user and stores it as an Appointment object
        //Postcondition: month, day, and year are initialized. If user enters
        //               invalid date format, month = 13. If user enters
        //               description, it's set to value. Else, it's set to empty
        //               string
        void inputAppointment(istream &in);

        //Outputs Appointment object
        //Pre: 0<month<13. day must be in appropriate range depending on month
        //Post: Appointment is outputted
        void outputAppointment(ostream &out);

        //Returns whether the user entered invalid input into appointment object
        //Pre: user enters appointment in form m/d/y
        //Post: returns true if the date is valid
        bool wrongInput();

        //Accesses the current value of month
        //Precondition: object must be initialized, and 1<= month <= 12
        //Postcondition: function returns month value as an integer
        int getMonth();

        //Accesses the current value of day
        //Precondition: object must be initialized, and day must be in appropriate
        //              range
        //Postcondition: function returns day value as an integer
        int getDay();

        //Accesses the current value of year
        //Precondition: object must be initialized. Year can be any value
        //              s.t. year>2019 is future appointment, year<2019 is
        //              previous appointment, and year<0 is a B.C.E. year
        //Postcondition: function returns year value as an integer
        int getYear();

        //Accesses the current value of description
        //Precondition: object must be initialized 
        //Postcondition: function returns description value as a string
        string getDescription();

        //Returns a char comparing Appointment object to Appointment a
        //Pre: object and a are both initialized to valid values
        //Post: > is returned if object comes after a
        //      < is returned if object comes before a
        //      = is returned if object is on same date as a
        char ComparedTo(Appointment a);

        //Overload assignment operator for Appointment objects
        void operator = (Appointment a);
    private:
        int month, day, year;
        string description;
};

ostream &operator << (ostream &out, Appointment a);
istream &operator >> (istream &in, Appointment &a);
#endif

