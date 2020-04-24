/* Nina Hudak
 * Lab 5: Use stack to determine if parenthesis are balanced
 * November 2019
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Compare two parentheses and determine if parentheses form a matching pair
//@param open: a char that contains an open parenthesis i.e. (, {, or [
//@param close: a char that contains a closing parenthesis i.e. ), }, or ]
//@pre: cur_paren and close are both initialized to valid values
//@post: bool will be returned determining if parentheses form a match
//@return true if parenthesis match, false if not
bool FormsMatch(char open, char close);

//Determine if parentheses are balanced
//@param input: a string of input to be evaluated
//@pre: string length > 0
//@post: bool will be returned determining if parenthesis are balanced
//@return true if parentheses are balanced, false if not balanced
bool IsBalanced(string input);

//Outputs result of whether parentheses in string are balanced
//@param is_balanced: bool that represents whether parenthesis are balanced
//@pre: is_balanced is initialized
//@post: message will be printed communicating whether string is balanced
//@return nothing
void OutputResult(bool is_balanced);

int main()
{
    string input;
    bool balanced;

    cout << "\nTest Cases:\n" << endl;

    cout << "Case 1: ()()]" << endl; //Test case 1
    input = "()()]";                 //Initialize input
    balanced = IsBalanced(input);    //Call function to see if balanced
    OutputResult(balanced);          //Output result

    cout << "Case 2: {[()(})" << endl; //Test case 2
    input = "{[()(})";
    balanced = IsBalanced(input);
    OutputResult(balanced);

    cout << "Case 3: [()]{}" << endl; //Test case 3
    input = "[()]{}";
    balanced = IsBalanced(input);
    OutputResult(balanced);

    cout << "Case 4: {[()()]{}}" << endl; //Test case 4
    input = "{[()()]{}}";
    balanced = IsBalanced(input);
    OutputResult(balanced);

    cout << "Try it yourself!" << endl;
    
    do //Allow user to test their own cases
    {
        cout << "Enter a message to test or type q to quit: ";
        getline(cin, input);

        if(input == "q")
            cout << "Bye!\n" << endl;
        else
            OutputResult(IsBalanced(input));
    }   while(input != "q");

    return 0;
}

//Compare two parentheses and determine if they form a matching pair
bool FormsMatch(char open, char close)
{
    bool is_match;

    if(open == '{' && close == '}') //if they form {}, they match
        is_match = true;
    else if(open == '(' && close == ')') //if they form (), they match
        is_match = true;
    else if(open == '[' && close == ']') //if they form [], they match
        is_match = true;
    else                //otherwise, they don't match
        is_match = false;

    return is_match;
}

//Determine if parentheses are balanced
bool IsBalanced(string input)
{
    stack <char> s; //Declare stack of char using STL template

    for(int i=0; i<input.length(); i++) //Loop through input string
    {
        //if current char is an open symbol...
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
            s.push(input[i]); //add it to the stack
        //if current char is a closing symbol...
        else if(input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if(s.size() == 0) //if stack is empty, current symbol has no match
                return false;
            else if(FormsMatch(s.top(), input[i])) //if char matches element on top...
                s.pop(); //...they match so remove top element from stack
            else    //if char doesn't match element on top, string not balanced
                return false;
        }
    }

    if(s.size() != 0) //if stack still has elements after loop finishes - unbalanced
        return false;

    return true; //otherwise, string is balanced
}

//Output result of whether parentheses in string are balanced
void OutputResult(bool is_balanced)
{
    if(is_balanced == true)
        cout << "The parenthesis are balanced -- yay!" << endl;
    else
        cout << "The parenthesis are not balanced" << endl;
    cout << endl;
}
