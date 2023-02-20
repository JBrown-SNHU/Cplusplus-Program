#include <iostream>
#include <string>
#include <climits>

using namespace std;

#include "Functions.cpp"

int main() {
    double inAmount;
    double deposit;
    double interest;
    int yr;
    bool choiceYN = true;
    string yesNo = "N";
    string quit = "N";

    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);

    // Main exists inside a while loop, that quits when quit = "Q"
    while (quit != "Q")  {

        // Creates a new object in the investment class
        Investment newInvestment;

        /* Asks user for input and sets the answers to the newIvestment object.
        This is set in a while loop to make sure the user if fine with their choices. 
        Typing Y at yesNo exits the while loop */
        while (yesNo == "N") {
            try {
                cout << endl << "What will be your intial investment amount: ";
                cin >> inAmount;
                inAmount = isOver0(inAmount);           // Makes sure the number is over 0.
    
                cout << "\nYour monthly deposit: ";
                cin >> deposit;
                deposit = isOver0(deposit);             // Makes sure the number is over 0.
    
                cout << "\nWhat is your yearly interest rate: ";
                cin >> interest;
                interest = isOver0(interest);           // Makes sure the number is over 0.

                cout << "\nHow many years will you invest for: ";
                cin >> yr;
                yr = isOver0(yr);                       // Makes sure the number is over 0.

                newInvestment.SetInitialAmount(inAmount);
                newInvestment.SetMonthlyDeposit(deposit);
                newInvestment.SetInterest(interest);
                newInvestment.SetYear(yr);  
                newInvestment.PrintChoices();

                cin >> yesNo;
                yesNo = isYesOrNo(yesNo);               // tests for valid input (Y or N)
            }
            catch (ios_base::failure& excpt) {
                cout << "\nYou must enter a number for all fields: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');

            }
        }
        /* Sets yesNO back to "N".
        If the users reruns the program, this will allow the user to go back through
        the yesNo while loop to reselect their input choices.  */
        yesNo = "N";                                 
        
        // Prints projected savings if there is no monthly deposit.
        newInvestment.PrintAll(newInvestment.GetNoDeposit());      

        // Prints projected savings with the set monthly deposits.     
        newInvestment.PrintAll(newInvestment.GetMonthlyDeposit());

        cout << endl << "Press Q to quit, or type any key to try again: ";
        cin >> quit;                            // Allows the user to quit or rerun the program
        quit = isQuit(quit);                    // Checks user input for q. Assigns q to Q.

    }

    cout << endl << "Goodbye!" << endl;
    return 0;
}
