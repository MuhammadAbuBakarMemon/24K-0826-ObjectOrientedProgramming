#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDeposit;
    double dailyWithdraw;
    const double maxDeposit = 10000;
    const double maxWithdraw = 5000;

public:
    Wallet() : balance(0), dailyDeposit(0), dailyWithdraw(0) {}

    bool deposit(double amount) {
        if (amount < 0 || dailyDeposit + amount > maxDeposit) return false;
        balance += amount;
        dailyDeposit += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount < 0 || amount > balance || dailyWithdraw + amount > maxWithdraw) return false;
        balance -= amount;
        dailyWithdraw += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) : userID(id), name(n) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    void showBalance() const {
        cout << name << "'s Balance: " << wallet.getBalance() << endl;
    }
};

int main(void) {
    User u1("001", "Alice");
    User u2("002", "Bob");

    u1.deposit(3000);
    u1.withdraw(1000);
    u1.deposit(8000);
    u1.withdraw(5000);
    u1.withdraw(100);

    u2.deposit(5000);
    u2.withdraw(3000);
    u2.deposit(6000);
    u2.withdraw(2500);

    u1.showBalance();
    u2.showBalance();

    return 0;
}
