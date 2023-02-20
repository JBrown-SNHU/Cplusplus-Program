#ifndef INVESTMENTCLASS_H
#define INVESTMENTCLASS_H

class Investment {
    public:
        Investment();
        void SetInitialAmount(double inAmount);     // Sets initial amount
        void SetMonthlyDeposit(double deposit);     // Sets monthly deposit
        void SetInterest(double interest);          // Sets interest rate
        void SetYear(int years);                    // Sets years   
        double GetInitialAmount() const;            // Gets set initial amount
        double GetMonthlyDeposit() const;           // Gets set monthly deposit
        double GetNoDeposit() const;                // Gets set no montly deposit ($0)
        double GetInterest() const;                 // Gets set interest
        int GetYear() const;                        // Gets set year amount
        void PrintChoices();                        // Prints users input to confirm their choice
        void PrintAll(double deposit);              // Prints projected savings
    
    private:
        double initialAmount;                   
        double monthlyDeposit;
        double noDeposit;
        double interestRate;
        int years;
    

};

#endif