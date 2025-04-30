#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Employee {
public:
    int id;
    string name;
    string designation;
    int yearsOfService;

    Employee() {}
    Employee(int i, string n, string d, int y) : id(i), name(n), designation(d), yearsOfService(y) {}

    string toString() const {
        stringstream ss;
        ss << id << "," << name << "," << designation << "," << yearsOfService;
        return ss.str();
    }

    static Employee fromString(const string& data) {
        stringstream ss(data);
        string token;
        vector<string> fields;
        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        return Employee(stoi(fields[0]), fields[1], fields[2], stoi(fields[3]));
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;
    string filename = "employees.txt";

public:
    void loadData() {
        ifstream fin(filename);
        string line;
        while (getline(fin, line)) {
            employees.push_back(Employee::fromString(line));
        }
        fin.close();
    }

    void saveData() {
        ofstream fout(filename);
        for (const auto& emp : employees) {
            fout << emp.toString() << endl;
        }
        fout.close();
    }

    void insertDummyData() {
        employees = {
            Employee(1, "Alice", "developer", 3),
            Employee(2, "Bob", "manager", 2),
            Employee(3, "Charlie", "manager", 1),
            Employee(4, "David", "tester", 5),
            Employee(5, "Eva", "manager", 3)
        };
        saveData();
    }

    vector<Employee> queryManagersWithMinYears(int minYears) {
        vector<Employee> result;
        for (const auto& emp : employees) {
            if (emp.designation == "manager" && emp.yearsOfService >= minYears) {
                result.push_back(emp);
            }
        }
        return result;
    }

    void deleteExcept(const vector<Employee>& keepList) {
        employees = keepList;
        saveData();
    }

    void writeWithIncrementedData(const vector<Employee>& baseList) {
        vector<Employee> updated;
        int idCounter = 1;
        for (const auto& emp : baseList) {
            updated.push_back(Employee(idCounter++, emp.name, emp.designation, emp.yearsOfService + 1));
        }
        employees = updated;
        saveData();
    }

    void displayAll() {
        for (const auto& emp : employees) {
            cout << emp.toString() << endl;
        }
    }
};

int main() {
    EmployeeManager manager;

    manager.insertDummyData();
    manager.loadData();

    cout << "Query A: Managers with at least 2 years:" << endl;
    vector<Employee> queryResult = manager.queryManagersWithMinYears(2);
    for (const auto& emp : queryResult) {
        cout << emp.toString() << endl;
    }

    cout << "Query B: Delete all except matched data." << endl;
    manager.deleteExcept(queryResult);
    manager.displayAll();

    cout << "Query C: Write same data with incremented ID and years." << endl;
    manager.writeWithIncrementedData(queryResult);
    manager.displayAll();

    return 0;
}
