#include <iostream>
#include <vector>
#include <string>

class Employee
{
protected:
    int id;
    std::string name;

public:
    Employee(int id, std::string name) : id(id), name(name) {}
    virtual void displayInfo()
    {
        std::cout << "Employee ID: " << id << ", Name: " << name << std::endl;
    }
    virtual ~Employee() {}
};

class IOrderTaker
{
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer
{
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller
{
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker
{
public:
    Waiter(int id, std::string name) : Employee(id, name) {}

    void takeOrder() override
    {
        std::cout << name << " is taking the order." << std::endl;
    }

    void displayInfo() override
    {
        Employee::displayInfo();
        std::cout << "Role: Waiter" << std::endl;
    }
};

class Chef : public Employee, public IOrderPreparer
{
public:
    Chef(int id, std::string name) : Employee(id, name) {}

    void prepareOrder() override
    {
        std::cout << name << " is preparing the order." << std::endl;
    }

    void displayInfo() override
    {
        Employee::displayInfo();
        std::cout << "Role: Chef" << std::endl;
    }
};

class Cashier : public Employee, public IBiller
{
public:
    Cashier(int id, std::string name) : Employee(id, name) {}

    void generateBill() override
    {
        std::cout << name << " is generating the bill." << std::endl;
    }

    void displayInfo() override
    {
        Employee::displayInfo();
        std::cout << "Role: Cashier" << std::endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller
{
public:
    Manager(int id, std::string name) : Employee(id, name) {}

    void takeOrder() override
    {
        std::cout << name << " is taking the order." << std::endl;
    }

    void generateBill() override
    {
        std::cout << name << " is generating the bill." << std::endl;
    }

    void displayInfo() override
    {
        Employee::displayInfo();
        std::cout << "Role: Manager" << std::endl;
    }
};

class Menu
{
protected:
    std::vector<std::string> items;

public:
    virtual double calculateTotalCost() = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu
{
public:
    FoodMenu()
    {
        items = {"Pizza", "Burger", "Pasta"};
    }

    double calculateTotalCost() override
    {
        return items.size() * 10.0;
    }
};

class BeverageMenu : public Menu
{
public:
    BeverageMenu()
    {
        items = {"Soda", "Coffee", "Tea"};
    }

    double calculateTotalCost() override
    {
        return items.size() * 5.0 + 2.0; // Adding a beverage tax
    }
};

int main()
{
    std::vector<Employee *> employees;
    employees.push_back(new Waiter(1, "John"));
    employees.push_back(new Chef(2, "Alice"));
    employees.push_back(new Cashier(3, "Bob"));
    employees.push_back(new Manager(4, "Charlie"));

    for (auto &employee : employees)
    {
        employee->displayInfo();
    }

    IOrderTaker *orderTaker = new Waiter(5, "David");
    IOrderPreparer *orderPreparer = new Chef(6, "Eve");
    IBiller *biller = new Cashier(7, "Grace");

    orderTaker->takeOrder();
    orderPreparer->prepareOrder();
    biller->generateBill();

    Menu *foodMenu = new FoodMenu();
    Menu *beverageMenu = new BeverageMenu();

    std::cout << "Food Menu Total: $" << foodMenu->calculateTotalCost() << std::endl;
    std::cout << "Beverage Menu Total: $" << beverageMenu->calculateTotalCost() << std::endl;

    delete orderTaker;
    delete orderPreparer;
    delete biller;
    delete foodMenu;
    delete beverageMenu;

    for (auto &employee : employees)
    {
        delete employee;
    }

    return 0;
}
