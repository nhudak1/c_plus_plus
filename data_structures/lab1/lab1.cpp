/* Nina Hudak
 * Data Structures
 * ...
 * September 11, 2019 */

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

const string ONES[] = {"zero", "one", "two", "three", "four", 
                       "five", "six", "seven", "eight", "nine"};
const string TENS[] = {"", "ten", "twenty", "thirty", "forty", "fifty", 
                       "sixty", "seventy", "eighty", "ninety"};
const string TEENS[] = {"", "eleven", "twelve", "thirteen", "fourteen", 
                        "fifteen", "sixteen", "seventeen", "eighteen", 
                        "nineteen"};

//Parameters: accepts an integer
//Pre-conditions: integer cannot be greater than 9999 or less than 0
//Post-conditions: function returns the number spelled out as a string
string convert_number(int dlr);

int main()
{
    int dollar, cents, next_input;
    char decimal, again;
    bool wrong_input;
    string converted_dollar;

    do  //Loop determining whether or not to play again
    {
        do  //Loop determining if user entered valid input
        {
            cout << "\nEnter the dollar amount: $";
            cin >> dollar;

            next_input = cin.peek();
            if(isspace(next_input))
            {
                decimal = '.';
                cents = 0;
            }
            else
            {
                cin >> decimal;
                next_input = cin.peek();
                if(isspace(next_input))
                    cents = 0;
                else
                    cin >> cents;
            }

            //If user enters wrong data type
            if(cin.fail())
            {
                cin.clear(); //Clear the error flags in cin
                cin.ignore(2048, '\n'); //Ignore everything in the input buffer, 
                                        //up to 2048 char, up to the newline char 
                                        //=< ignore the rest of the line
                cout << "Wrong input. Try again:\n";
                wrong_input = true;
            }
            //If user enters number out of range
            else if(dollar >= 10000 || dollar < 0 || cents > 99) 
            {
                cout << "Wrong input. Try again:\n";
                wrong_input = true;
            }
            //If user enters valid input
            else
                wrong_input = false;
        }   while(wrong_input);

        converted_dollar = convert_number(dollar); //Convert dollar from int to string

        cout << "It's " << converted_dollar << "and " << cents << "/100\n"; //Output

        cout << "Try again(y/n): "; //Determine if user wants to play again
        cin >> again;
    }   while(again == 'y' || again == 'Y');

    cout << endl;

    return 0;
}

//Convert number to words
string convert_number(int dlr)
{
    int digit;
    string converted = "", temp, label;

    if(dlr == 0)    //Account for case where user enters 0 dollars
        converted = ONES[dlr] + " ";

    while(dlr > 0) //If dlr > 0, loop repeats until dlr == 0
    {
        if(dlr/1000 > 0) //If dlr has a number in the thousands place
        {
            digit = dlr / 1000; //Get digit in thousands place
            dlr = dlr % 1000; //Update dlr so greatest place is hundreds
            temp = ONES[digit]; //Get string equivalent of digit from array
            label = " thousand"; //Label thousands place
        }
        else if(dlr/100 > 0) //If dlr has a number in the hundreds place
        {
            digit = dlr/100; //Get digit in hundreds place
            dlr = dlr % 100; //update dlr so greatest place is tens
            temp = ONES[digit];
            label = " hundred";
        }
        else if(dlr/10 > 0) //If dlr has a number in the tens place
        {
            digit = dlr/10; //Get digit in tens place
            dlr = dlr % 10; //update dlr so greatest place is ones
            if(digit == 1 && dlr != 0) //If last two digits between 11-19
            {
                temp = TEENS[dlr];
                dlr = 0; //dlr = 0 because we already accounted for ones place
            }
            else
                temp = TENS[digit];
            label = "";
        }
        else //If dlr has a number in the ones place
        {
            temp = ONES[dlr];
            dlr = 0;
            label = "";
        }

        converted = converted + temp + label + " "; //Update converted string for each digit
    }

    return converted;
}
