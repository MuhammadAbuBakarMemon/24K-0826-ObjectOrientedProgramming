#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Account {
protected:
    std::string accountNumber;
    double balance;
    std::string accountHolderName;
    std::string accountType;
    std::vector<std::string> transactionHistory;

public:
    Account(const std::string& num, const std::string& holder, double initialBalance)
        : accountNumber(num), accountHolderName(holder), balance(initialBalance), accountType("Generic") {}

    virtual ~Account() {}

    virtual void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Deposit amount must be positive\n";
            return;
        }
        balance += amount;
        transactionHistory.push_back("Deposit: +" + std::to_string(amount));
    }

    virtual void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Error: Insufficient funds\n";
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrawal: -" + std::to_string(amount));
    }

    virtual double calculateInterest() const {
        return 0.0;
    }

    virtual void printStatement() const {
        std::cout << "Account Statement for " << accountNumber << "\n";
        std::cout << "Holder: " << accountHolderName << "\n";
        std::cout << "Type: " << accountType << "\n";
        std::cout << "Balance: " << balance << "\n";
        std::cout << "Transaction History:\n";
        for (const auto& entry : transactionHistory) {
            std::cout << "  " << entry << "\n";
        }
    }

    virtual std::string getAccountInfo() const {
        return "Account Number: " + accountNumber + "\nHolder: " + accountHolderName + 
               "\nType: " + accountType + "\nBalance: " + std::to_string(balance);
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(const std::string& num, const std::string& holder, double initialBalance, double rate, double minBal)
        : Account(num, holder, initialBalance), interestRate(rate), minimumBalance(minBal) {
        accountType = "Savings";
    }

    void withdraw(double amount) override {
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive\n";
            return;
        }
        if (amount > balance) {
            std::cout << "Error: Insufficient funds\n";
            return;
        }
        if ((balance - amount) < minimumBalance) {
            std::cout << "Error: Cannot go below minimum balance\n";
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrawal: -" + std::to_string(amount));
    }

    double calculateInterest() const override {
        return balance * interestRate / 100.0;
    }

    void printStatement() const override {
        Account::printStatement();
        std::cout << "Interest Rate: " << interestRate << "%\n";
        std::cout << "Minimum Balance: " << minimumBalance << "\n";
        std::cout << "Projected Interest: " << calculateInterest() << "\n";
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(const std::string& num, const std::string& holder, double initialBalance, double limit)
        : Account(num, holder, initialBalance), overdraftLimit(limit) {
        accountType = "Checking";
    }

    void withdraw(double amount) override {
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive\n";
            return;
        }
        if (amount > (balance + overdraftLimit)) {
            std::cout << "Error: Exceeds overdraft limit\n";
            return;
        }
        balance -= amount;
        transactionHistory.push_back("Withdrawal: -" + std::to_string(amount));
    }

    void printStatement() const override {
        Account::printStatement();
        std::cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }
};

class FixedDepositAccount : public Account {
private:
    time_t maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(const std::string& num, const std::string& holder, double initialBalance, double rate, int days)
        : Account(num, holder, initialBalance), fixedInterestRate(rate) {
        accountType = "Fixed Deposit";
        time_t now = time(0);
        maturityDate = now + (days * 24 * 60 * 60);
    }

    void withdraw(double amount) override {
        time_t now = time(0);
        if (now < maturityDate) {
            std::cout << "Error: Cannot withdraw before maturity date\n";
            return;
        }
        Account::withdraw(amount);
    }

    double calculateInterest() const override {
        time_t now = time(0);
        if (now >= maturityDate) {
            return balance * fixedInterestRate / 100.0;
        }
        return 0.0;
    }

    void printStatement() const override {
        Account::printStatement();
        std::cout << "Maturity Date: " << ctime(&maturityDate);
        std::cout << "Fixed Interest Rate: " << fixedInterestRate << "%\n";
        std::cout << "Projected Interest: " << calculateInterest() << "\n";
    }
};

int main() {
    SavingsAccount sa("SA123", "John Doe", 5000, 3.5, 1000);
    CheckingAccount ca("CA456", "Jane Smith", 3000, 2000);
    FixedDepositAccount fd("FD789", "Bob Johnson", 10000, 5.0, 365);

    sa.deposit(1000);
    sa.withdraw(2000);
    sa.withdraw(4000);

    ca.deposit(500);
    ca.withdraw(3500);
    ca.withdraw(2000);

    fd.deposit(2000);
    fd.withdraw(500);

    std::cout << "\nSavings Account Statement:\n";
    sa.printStatement();

    std::cout << "\nChecking Account Statement:\n";
    ca.printStatement();

    std::cout << "\nFixed Deposit Account Statement:\n";
    fd.printStatement();

    return 0;
}