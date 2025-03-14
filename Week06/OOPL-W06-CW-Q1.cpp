#include <iostream>
#include <vector>
#include <string>

class BankAccount
{
protected:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accountNumber, double balance = 0.0)
        : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount)
    {
        balance += amount;
    }

    virtual bool withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cout << "Insufficient funds\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const
    {
        return balance;
    }

    virtual void printAccountDetails() const
    {
        std::cout << "Account Number: " << accountNumber << ", Balance: " << balance << std::endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(std::string accountNumber, double interestRate, double balance = 0.0)
        : BankAccount(accountNumber, balance), interestRate(interestRate) {}

    void applyInterest()
    {
        balance += balance * interestRate;
    }

    void printAccountDetails() const override
    {
        std::cout << "Savings Account\n";
        BankAccount::printAccountDetails();
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(std::string accountNumber, double overdraftLimit, double balance = 0.0)
        : BankAccount(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    bool withdraw(double amount) override
    {
        if (amount > balance + overdraftLimit)
        {
            std::cout << "Overdraft limit exceeded\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    void printAccountDetails() const override
    {
        std::cout << "Checking Account\n";
        BankAccount::printAccountDetails();
    }
};

class BusinessAccount : public BankAccount
{
private:
    double taxRate;

public:
    BusinessAccount(std::string accountNumber, double taxRate, double balance = 0.0)
        : BankAccount(accountNumber, balance), taxRate(taxRate) {}

    void deposit(double amount) override
    {
        double tax = amount * taxRate;
        balance += (amount - tax);
    }

    void printAccountDetails() const override
    {
        std::cout << "Business Account\n";
        BankAccount::printAccountDetails();
    }
};

class Employee
{
protected:
    std::string name;

public:
    Employee(std::string name) : name(name) {}
    virtual void performOperations(BankAccount &account) = 0;
    virtual ~Employee() {}
};

class Customer : public Employee
{
public:
    Customer(std::string name) : Employee(name) {}

    void performOperations(BankAccount &account) override
    {
        std::cout << "Customer can only deposit or withdraw\n";
    }
};

class Teller : public Employee
{
public:
    Teller(std::string name) : Employee(name) {}

    void performOperations(BankAccount &account) override
    {
        std::cout << "Teller can deposit, withdraw, or freeze accounts\n";
    }
};

class Manager : public Employee
{
public:
    Manager(std::string name) : Employee(name) {}

    void performOperations(BankAccount &account) override
    {
        std::cout << "Manager can deposit, withdraw, freeze accounts, or adjust limits\n";
    }
};

int main()
{
    BankAccount *acc1 = new SavingsAccount("S123", 0.03, 1000);
    BankAccount *acc2 = new CheckingAccount("C456", 500, 200);
    BankAccount *acc3 = new BusinessAccount("B789", 0.1, 10000);

    std::vector<BankAccount *> accounts = {acc1, acc2, acc3};

    for (auto &account : accounts)
    {
        account->deposit(500);
        account->printAccountDetails();
    }

    Employee *customer = new Customer("Alice");
    Employee *teller = new Teller("Bob");
    Employee *manager = new Manager("Charlie");

    customer->performOperations(*acc1);
    teller->performOperations(*acc2);
    manager->performOperations(*acc3);

    delete acc1;
    delete acc2;
    delete acc3;
    delete customer;
    delete teller;
    delete manager;

    return 0;
}
