#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee 
{
    private:
        string firstName;
        string lastName;
        double monthlySalary;

    public:
        Employee(string first, string last, double salary) 
        {
            firstName = first;
            lastName = last;
            setMonthlySalary(salary);
        }

    void setMonthlySalary(double salary) 
    {
        if (salary >= 0.0) {
            monthlySalary = salary;
        } else {
            monthlySalary = 0.0;
        }
    }

    double getMonthlySalary() const 
    {
        return monthlySalary;
    }

    double getYearlySalary() const 
    {
        return monthlySalary * 12;
    }

    void giveRaise() 
    {
        monthlySalary *= 1.10;
    }

    void displayDetails() const 
    {
        cout << "Employee: " << firstName << " " << lastName << endl;
        cout << "Monthly Salary: $" << fixed << setprecision(2) << monthlySalary << endl;
        cout << "Yearly Salary: $" << fixed << setprecision(2) << getYearlySalary() << endl;
    }
};

int main(int argc, char* argv[]) 
{
    if (argc != 7) {
        cerr << "Usage: " << argv[0] << " <firstName1> <lastName1> <salary1> <firstName2> <lastName2> <salary2>" << endl;
        return 1;
    }

    string firstName1 = argv[1];
    string lastName1 = argv[2];
    double salary1 = stod(argv[3]);

    string firstName2 = argv[4];
    string lastName2 = argv[5];
    double salary2 = stod(argv[6]);

    Employee employee1(firstName1, lastName1, salary1);
    Employee employee2(firstName2, lastName2, salary2);

    cout << "Initial Employee Details:" << endl;
    employee1.displayDetails();
    employee2.displayDetails();
    cout << endl;

    employee1.giveRaise();
    employee2.giveRaise();

    cout << "After 10% Raise:" << endl;
    employee1.displayDetails();
    employee2.displayDetails();

    return 0;
}