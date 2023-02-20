#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "InvestmentClass.h"
#include "OtherFunctions.h"

//Constructor
Investment::Investment () {
    initialAmount = 1;
    monthlyDeposit = 0;
    noDeposit = 0;
    interestRate = 1;
    years = 1;
}

//Setters
void Investment::SetInitialAmount(double inAmount) {
    initialAmount = inAmount;

    return;
}

void Investment::SetMonthlyDeposit(double deposit) {
    monthlyDeposit = deposit;

    return;
}

void Investment::SetInterest(double interest) {
    interestRate = interest;

    return;
}

void Investment::SetYear(int years) {
    this->years = years;

    return;
}

//Getters
double Investment::GetInitialAmount() const {
    return initialAmount;
}

double Investment::GetMonthlyDeposit() const {
    return monthlyDeposit;
}

double Investment::GetNoDeposit() const {
    return noDeposit;
}

double Investment::GetInterest() const {
    return interestRate;
}

int Investment::GetYear() const {
    return years;
}

// Printing Functions
// Prints users input to confirm their choice
void Investment::PrintChoices() {
    cout << endl << nCharString(30, '*') << endl;
    cout << nCharString(9, '*') << " Data Input " << nCharString(9, '*') << endl;
    cout << fixed << setprecision(2);
    cout << "Initial Amount: $" << initialAmount << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest: " << interestRate << "%" << endl;
    cout << "Number of Years: " << years << endl;
    cout << "Is this correct? Type Y or N: ";

    return;
}

// Prints projected savings
void Investment::PrintAll(double deposit) {
    double closingBalance = initialAmount;
    double monthsInterest = 0;
    double yearEndInterest = 0;
    int month = years * 12;

    cout << endl;
    cout << nCharString(50, '-') << endl;
    if (deposit == 0) {
        cout << "Projected Savings With No Deposit" << endl;
    }
    else {
        cout << "Projected Savings Depositing $" << deposit << " A Month" << endl;
    }
    cout << nCharString(50, '-') << endl;
    cout << "Year" << nCharString(6, ' ') << "Year End Balance" << nCharString(6, ' ') << "Interest Earned" << endl;
    cout << nCharString(50, '-') << endl;
    for (int i = 1; i <= month; ++i) {
        monthsInterest = ((closingBalance + deposit) * ((interestRate / 100) / 12));
        closingBalance += deposit + monthsInterest;
        yearEndInterest += monthsInterest;
        if (i % 12 == 0) {
            cout << fixed << setprecision(2);
            cout << setw(4) << right << (i / 12) << setw(12) << right << "$" << setw(10) << right << closingBalance; 
            cout << setw(13) << right << "$" << setw(8) << right << yearEndInterest << endl;
            yearEndInterest = 0;
        }        
    }
    cout << nCharString(50, '-') << endl;

    return;
}

// Other Functions
// Creates a border for design
string nCharString(size_t n, char c) {
    string border;
    for (int i = 0; i < n; ++i) {
        border += c;
    }

    return border;
    
}

// Used for yes or no response 
string isYesOrNo(string response) {
    string input = response;
    while ((input != "Y") && (input != "y") && (input != "N") && (input != "n")) {
        cout << endl << "Invalid Response!" << endl;
        cout << "Type Y or N: ";
        cin >> input;
    }
    if (input == "y") {
        input = "Y";
    }
    else if (input == "n") {
        input = "N";
    }

    return input;
}

// used for terminating the main
string isQuit(string response) {
    string input = response;
    while (input == "q") {
        input = "Q";
    }

    return input;
}

double isOver0(double num) {
    double tester = num;

    while (tester < 0) {
        cout << endl << "You must enter a number greater than 0: ";
        cin >> tester;
    }

    return tester;
}