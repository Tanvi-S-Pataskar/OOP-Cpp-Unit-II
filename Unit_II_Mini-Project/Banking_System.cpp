#include <iostream>
#include <string>

using namespace std;

// Base Class: Account
class Account {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor for Base Class
    Account(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = initialBalance;
    }

    // Virtual Destructor for cleanup
    virtual ~Account() {}

    // Deposit Money Function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n[SUCCESS] Amount deposited successfully." << endl;
            cout << "Updated Balance: Rs. " << balance << endl;
        } else {
            cout << "\n[ERROR] Deposit amount must be positive!" << endl;
        }
    }

    // Withdrawal Money Function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n[SUCCESS] Amount withdrawn successfully." << endl;
            cout << "Updated Balance: Rs. " << balance << endl;
        } else if (amount > balance) {
            cout << "\n[ERROR] Insufficient balance!" << endl;
        } else {
            cout << "\n[ERROR] Invalid withdrawal amount!" << endl;
        }
    }

    // Virtual function for Account-Specific behavior (Interest Calculation)
    virtual void calculateInterest() {
        cout << "\nGeneral account has no specific interest calculation." << endl;
    }

    // Virtual Display Function
    virtual void displayDetails() {
        cout << "\n----------------------------------------" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << accountHolderName << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }

    // Getter for Account Number
    int getAccountNumber() {
        return accountNumber;
    }
};

// Derived Class 1: SavingsAccount (Public Inheritance)
class SavingsAccount : public Account {
private:
    double interestRate; // e.g., 4%

public:
    // Constructor calling Base Class Constructor
    SavingsAccount(int accNo, string name, double initialBalance, double rate)
        : Account(accNo, name, initialBalance) {
        interestRate = rate;
    }

    // Overriding calculateInterest function
    void calculateInterest() override {
        double interest = (balance * interestRate) / 100.0;
        cout << "\n--- Savings Account Interest ---" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Calculated Annual Interest: Rs. " << interest << endl;
    }

    // Overriding displayDetails function
    void displayDetails() override {
        Account::displayDetails();
        cout << "Account Type   : Savings Account" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "----------------------------------------" << endl;
    }
};

// Derived Class 2: CurrentAccount (Public Inheritance)
class CurrentAccount : public Account {
private:
    double minimumBalance;

public:
    CurrentAccount(int accNo, string name, double initialBalance, double minBal)
        : Account(accNo, name, initialBalance) {
        minimumBalance = minBal;
    }

    // Overriding calculateInterest function
    void calculateInterest() override {
        cout << "\n--- Current Account Info ---" << endl;
        cout << "Current Accounts do not earn interest." << endl;
        if (balance < minimumBalance) {
            cout << "[WARNING] Balance is below minimum required balance of Rs. " << minimumBalance << endl;
        } else {
            cout << "Minimum balance criteria maintained." << endl;
        }
    }

    // Overriding displayDetails function
    void displayDetails() override {
        Account::displayDetails();
        cout << "Account Type   : Current Account" << endl;
        cout << "Minimum Balance: Rs. " << minimumBalance << endl;
        cout << "----------------------------------------" << endl;
    }
};

// Derived Class 3: FixedDepositAccount (Public Inheritance)
class FixedDepositAccount : public Account {
private:
    int tenureInMonths;
    double interestRate; // e.g., 7%

public:
    FixedDepositAccount(int accNo, string name, double initialBalance, int tenure, double rate)
        : Account(accNo, name, initialBalance) {
        tenureInMonths = tenure;
        interestRate = rate;
    }

    // Overriding calculateInterest function
    void calculateInterest() override {
        double timeInYears = tenureInMonths / 12.0;
        double interest = (balance * interestRate * timeInYears) / 100.0;
        cout << "\n--- Fixed Deposit Interest ---" << endl;
        cout << "Tenure         : " << tenureInMonths << " months" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "Total Interest at Maturity: Rs. " << interest << endl;
        cout << "Maturity Amount: Rs. " << (balance + interest) << endl;
    }

    // Overriding displayDetails function
    void displayDetails() override {
        Account::displayDetails();
        cout << "Account Type   : Fixed Deposit" << endl;
        cout << "FD Tenure      : " << tenureInMonths << " months" << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "----------------------------------------" << endl;
    }
};

// Main Menu Driver
int main() {
    Account* currentAcc = nullptr; // Polymorphic base-class pointer
    int choice;

    do {
        cout << "\n========================================" << endl;
        cout << "     BANKING SYSTEM MENU (UNIT II)      " << endl;
        cout << "========================================" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Calculate Interest" << endl;
        cout << "7. Display Account Details" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int accNo;
                string name;
                double bal, rate;

                cout << "\nEnter Account Number: ";
                cin >> accNo;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Balance: Rs. ";
                cin >> bal;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;

                delete currentAcc; // Free memory if account already exists
                currentAcc = new SavingsAccount(accNo, name, bal, rate);
                cout << "\n[SUCCESS] Savings Account created successfully!" << endl;
                break;
            }

            case 2: {
                int accNo;
                string name;
                double bal, minBal;

                cout << "\nEnter Account Number: ";
                cin >> accNo;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Balance: Rs. ";
                cin >> bal;
                cout << "Enter Minimum Balance Limit: Rs. ";
                cin >> minBal;

                delete currentAcc;
                currentAcc = new CurrentAccount(accNo, name, bal, minBal);
                cout << "\n[SUCCESS] Current Account created successfully!" << endl;
                break;
            }

            case 3: {
                int accNo, tenure;
                string name;
                double bal, rate;

                cout << "\nEnter Account Number: ";
                cin >> accNo;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Deposit Amount: Rs. ";
                cin >> bal;
                cout << "Enter Tenure (in months): ";
                cin >> tenure;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;

                delete currentAcc;
                currentAcc = new FixedDepositAccount(accNo, name, bal, tenure, rate);
                cout << "\n[SUCCESS] Fixed Deposit Account created successfully!" << endl;
                break;
            }

            case 4: {
                if (currentAcc == nullptr) {
                    cout << "\n[ERROR] No account created yet! Create an account first." << endl;
                } else {
                    double amt;
                    cout << "Enter amount to deposit: Rs. ";
                    cin >> amt;
                    currentAcc->deposit(amt);
                }
                break;
            }

            case 5: {
                if (currentAcc == nullptr) {
                    cout << "\n[ERROR] No account created yet! Create an account first." << endl;
                } else {
                    double amt;
                    cout << "Enter amount to withdraw: Rs. ";
                    cin >> amt;
                    currentAcc->withdraw(amt);
                }
                break;
            }

            case 6: {
                if (currentAcc == nullptr) {
                    cout << "\n[ERROR] No account created yet! Create an account first." << endl;
                } else {
                    // Runtime Polymorphism in action
                    currentAcc->calculateInterest();
                }
                break;
            }

            case 7: {
                if (currentAcc == nullptr) {
                    cout << "\n[ERROR] No account created yet! Create an account first." << endl;
                } else {
                    // Runtime Polymorphism in action
                    currentAcc->displayDetails();
                }
                break;
            }

            case 8:
                cout << "\nExiting Banking System. Goodbye!" << endl;
                break;

            default:
                cout << "\n[ERROR] Invalid choice! Please enter a number between 1 and 8." << endl;
        }
    } while (choice != 8);

    // Clean up dynamic object memory before exiting
    delete currentAcc;
    return 0;
}