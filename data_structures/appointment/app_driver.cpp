/* Nina Hudak
 * Driver file for classes Appointment and UnsortedType: app_driver.cpp
 * October 10, 2019
 */

#include <iostream>
#include <string>
#include <cctype>
#include "appointment.h"
#include "unsorted.h"

using namespace std;

const string COMMAND_OPTIONS[] = {"DISPLAY", "ADD", "SEARCH", "DELETE", "QUIT"};
const int SIZE = 5; //Size of COMMAND_OPTIONS

int main()
{
    string command;
    char command_char;
    Appointment appt, temp;
    UnsortedType arr;
    int next_input;
    bool found, wrong_input;

    cout << endl;
    cout << "Choose one of the following:" << endl;
    cout << "'Display': display all appointments" << endl;
    cout << "'Add': add a new appointment of form 'm/d/y description'" << endl;
    cout << "       Example: Add 01/28/1998 coffee date" << endl;
    cout << "'Search': search for an appointment with a specified date" << endl;
    cout << "          Example: Search 01/28/1998" << endl;
    cout << "'Delete': delete an appointment with a specified date" << endl;
    cout << "          Example: Delete 01/28/1998" << endl;
    cout << "'Quit': quit the program" << endl;
    cout << endl;

    do //Loop to keep program going until user wants to quit
    {
        do //Loop to keep prompting for command until proper input received
        {
            wrong_input = true; //Assume the user enters invalid input

            //Get a command from the user
            cout << "Command: ";
            cin >> command;

            //Put command in all capitals for to ensure consistency
            for(int i=0; i < command.length(); i++)
                command[i] = toupper(command[i]);

            //If the user entered a command that is on the list,
            //then wrong_input = false
            for(int i=0; i < SIZE; i++)
            {
                if(command == COMMAND_OPTIONS[i])
                    wrong_input = false;
            }

            //If wrong_input still equals true at this point, then the command
            //is not on the list. Output error message.
            if(wrong_input == true)
                cout << "Error: invalid command" << endl;

            //Peek next character
            next_input = cin.peek();

            //If command == ADD, DELETE, or SEARCH and user didn't enter 
            //an appointment or date, then output error message
            if((command == "ADD" || command == "SEARCH" || command == "DELETE") 
                    && next_input == 10)
            {
                wrong_input = true;
                cout << "Error: Didn't enter appointment or date" << endl;
            }

            //If wrong_input is true, don't do this bc it will output error
            //for appointment input even if user entered valid appointment.
            //If user entered an appointment and wrong input is false...
            if(next_input != 10 && wrong_input == false)
            {
                cin >> appt; //Input appointment
                wrong_input = appt.wrongInput(); //Check if it's valid
                if(wrong_input == true) //if invalid, output error
                    cout << "Error: invalid appointment input" << endl;
            }
        }   while(wrong_input);

        //Switch statement can only be used on chars and ints. Indices 0 and 1
        //of the commands are not unique, so use index 2.
        switch(command[2])
        {
            case 'S': //if command[2] is 'S' (aka DISPLAY)
                //Output arr
                for(int i=0; i<arr.GetLength(); i++)
                    cout << "\t" << arr[i] << endl; 
                break;
            case 'D': //if command[2] is 'D' (aka ADD) 
                arr.PutItem(appt); //insert appt into arr
                break;
            case 'A': //if command[2] is 'A' (aka SEARCH)
                //search for appt and store it in temp
                temp = arr.GetItem(appt, found);
                //if appt is found, output it
                if(found == true)
                    cout << "\tThe appointment is " << temp << endl;
                //otherwise, say it doesn't exist
                else 
                    cout << "\tThe appointment does not exist" << endl;
                break;
            case 'L': //if command[2] is 'L' (aka DELETE)
                //Call GetItem to see if appt exists in the list
                temp = arr.GetItem(appt, found);
                //if it does, delete it from the list
                if(found == true)
                    arr.DeleteItem(appt);
                //otherwise, say it doesn't exist
                else
                    cout << "\tThe appointment does not exist" << endl;
                break;
            case 'I': //if command[2] is 'I' (aka QUIT)
                cout << "Bye!\n" << endl;
                break;
            default: //Default is that command doesn't exist but this part
                     //of the code should never be accessed
                cout << "Error: command does not exist";
                break;
        }
    }while(command != "QUIT");

    return 0;
}
