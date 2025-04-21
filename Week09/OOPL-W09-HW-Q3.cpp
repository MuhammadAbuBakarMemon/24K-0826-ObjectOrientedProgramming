#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int empId;
    float salary;

public:
    virtual void getdata()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter base salary: ";
        cin >> salary;
    }

    virtual void displaydata()
    {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Base Salary: " << salary << endl;
    }

    virtual float bonus()
    {
        return 0; // Base class has no bonus calculation
    }

    virtual ~Person() {}
};

class Admin : virtual public Person
{
protected:
    float adminBonus;

public:
    void getdata() override
    {
        Person::getdata();
        cout << "Enter admin bonus percentage: ";
        cin >> adminBonus;
    }

    float bonus() override
    {
        return salary * adminBonus / 100;
    }

    void displaydata() override
    {
        Person::displaydata();
        cout << "Admin Bonus: " << bonus() << endl;
    }
};

class Account : virtual public Person
{
protected:
    float accountBonus;

public:
    void getdata() override
    {
        Person::getdata();
        cout << "Enter account bonus percentage: ";
        cin >> accountBonus;
    }

    float bonus() override
    {
        return salary * accountBonus / 100;
    }

    void displaydata() override
    {
        Person::displaydata();
        cout << "Account Bonus: " << bonus() << endl;
    }
};

class Master : public Admin, public Account
{
public:
    void getdata() override
    {
        Person::getdata();
        cout << "Enter admin bonus percentage: ";
        cin >> adminBonus;
        cout << "Enter account bonus percentage: ";
        cin >> accountBonus;
    }

    float bonus() override
    {
        return Admin::bonus() + Account::bonus();
    }

    void displaydata() override
    {
        Person::displaydata();
        cout << "Admin Bonus: " << Admin::bonus() << endl;
        cout << "Account Bonus: " << Account::bonus() << endl;
        cout << "Total Bonus: " << bonus() << endl;
    }
};

int main()
{
    Person *employees[3];

    employees[0] = new Admin();
    employees[1] = new Account();
    employees[2] = new Master();

    cout << "Enter employee details:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":\n";
        employees[i]->getdata();
    }

    cout << "\nEmployee Details and Bonuses:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEmployee " << i + 1 << ":\n";
        employees[i]->displaydata();
    }

    for (int i = 0; i < 3; i++)
    {
        delete employees[i];
    }

    return 0;
}