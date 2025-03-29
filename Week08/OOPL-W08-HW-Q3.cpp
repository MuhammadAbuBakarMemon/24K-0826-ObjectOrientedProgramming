#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string employeeID;

public:
    virtual void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }
    virtual void displayData() const
    {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person
{
private:
    string name;
    double monthlyIncome;

public:
    void getData() override
    {
        Person::getData();
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter monthly income: ";
        cin >> monthlyIncome;
    }
    void displayData() const override
    {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }
    double bonus() const
    {
        return monthlyIncome * 12 * 0.05;
    }
};

class Accounts : public Person
{
private:
    string name;
    double monthlyIncome;

public:
    void getData() override
    {
        Person::getData();
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter monthly income: ";
        cin >> monthlyIncome;
    }
    void displayData() const override
    {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }
    double bonus() const
    {
        return monthlyIncome * 12 * 0.05;
    }
};

int main()
{
    Admin adminEmp;
    cout << "Enter Admin Employee Details:" << endl;
    adminEmp.getData();
    cout << "\nAdmin Employee Information:" << endl;
    adminEmp.displayData();

    Accounts accountsEmp;
    cout << "\nEnter Accounts Employee Details:" << endl;
    accountsEmp.getData();
    cout << "\nAccounts Employee Information:" << endl;
    accountsEmp.displayData();

    return 0;
}