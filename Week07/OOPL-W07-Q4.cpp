#include <iostream>
#include <string>

const int MAX_COURSES = 10;
const int MAX_STUDENTS = 50;

class Person {
protected:
    std::string name;
    std::string id;
    std::string address;
    std::string phone;
    std::string email;

public:
    Person(std::string n, std::string i, std::string a, std::string p, std::string e)
        : name(n), id(i), address(a), phone(p), email(e) {}

    virtual void display() {
        std::cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address 
                  << "\nPhone: " << phone << "\nEmail: " << email << "\n";
    }

    virtual void update(std::string a, std::string p, std::string e) {
        address = a;
        phone = p;
        email = e;
    }

    std::string getId() { return id; }
    std::string getName() { return name; }
};

class Course;

class Student : public Person {
private:
    Course* courses[MAX_COURSES];
    int courseCount;
    double gpa;
    int year;

public:
    Student(std::string n, std::string i, std::string a, std::string p, std::string e, int y)
        : Person(n, i, a, p, e), gpa(0.0), year(y), courseCount(0) {}

    void display() override {
        Person::display();
        std::cout << "Year: " << year << "\nGPA: " << gpa << "\nCourses: " << courseCount << "\n";
    }

    bool addCourse(Course* c);
    bool dropCourse(std::string courseId);
    void setGPA(double g) { gpa = g; }
};

class Professor : public Person {
private:
    std::string dept;
    Course* courses[MAX_COURSES];
    int courseCount;
    double salary;

public:
    Professor(std::string n, std::string i, std::string a, std::string p, std::string e, std::string d, double s)
        : Person(n, i, a, p, e), dept(d), salary(s), courseCount(0) {}

    void display() override {
        Person::display();
        std::cout << "Department: " << dept << "\nSalary: $" << salary << "\nCourses: " << courseCount << "\n";
    }

    bool assignCourse(Course* c);
    bool removeCourse(std::string courseId);
    void setSalary(double s) { salary = s; }
};

class Staff : public Person {
private:
    std::string dept;
    std::string position;
    double salary;

public:
    Staff(std::string n, std::string i, std::string a, std::string p, std::string e, std::string d, std::string pos, double s)
        : Person(n, i, a, p, e), dept(d), position(pos), salary(s) {}

    void display() override {
        Person::display();
        std::cout << "Department: " << dept << "\nPosition: " << position << "\nSalary: $" << salary << "\n";
    }

    void setPosition(std::string p) { position = p; }
    void setSalary(double s) { salary = s; }
};

class Course {
private:
    std::string id;
    std::string name;
    int credits;
    Professor* prof;
    std::string schedule;
    Student* students[MAX_STUDENTS];
    int studentCount;

public:
    Course(std::string i, std::string n, int c, std::string s)
        : id(i), name(n), credits(c), schedule(s), prof(nullptr), studentCount(0) {}

    bool enroll(Student* s) {
        if (studentCount >= MAX_STUDENTS) return false;
        students[studentCount++] = s;
        return true;
    }

    bool remove(std::string studentId) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getId() == studentId) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                return true;
            }
        }
        return false;
    }

    void setInstructor(Professor* p) {
        prof = p;
    }

    void calcGrades() {
        std::cout << "Calculating grades for " << name << "\n";
    }

    void display() {
        std::cout << "Course: " << id << " - " << name << "\nCredits: " << credits 
                  << "\nSchedule: " << schedule << "\nInstructor: " << (prof ? prof->getName() : "None") 
                  << "\nStudents: " << studentCount << "\n";
    }

    std::string getId() { return id; }
    std::string getName() { return name; }
};

bool Student::addCourse(Course* c) {
    if (courseCount >= MAX_COURSES) return false;
    if (c->enroll(this)) {
        courses[courseCount++] = c;
        return true;
    }
    return false;
}

bool Student::dropCourse(std::string courseId) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i]->getId() == courseId) {
            courses[i]->remove(id);
            for (int j = i; j < courseCount - 1; j++) {
                courses[j] = courses[j + 1];
            }
            courseCount--;
            return true;
        }
    }
    return false;
}

bool Professor::assignCourse(Course* c) {
    if (courseCount >= MAX_COURSES) return false;
    c->setInstructor(this);
    courses[courseCount++] = c;
    return true;
}

bool Professor::removeCourse(std::string courseId) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i]->getId() == courseId) {
            courses[i]->setInstructor(nullptr);
            for (int j = i; j < courseCount - 1; j++) {
                courses[j] = courses[j + 1];
            }
            courseCount--;
            return true;
        }
    }
    return false;
}

int main() {
    Student student1("John Doe", "S1001", "123 Campus Rd", "555-0101", "john@uni.edu", 2022);
    Professor prof1("Dr. Smith", "P2001", "456 Faculty Ave", "555-0202", "smith@uni.edu", "Computer Science", 85000);
    Staff staff1("Alice Johnson", "E3001", "789 Admin Blvd", "555-0303", "alice@uni.edu", "Registrar", "Office Manager", 60000);

    Course cs101("CS101", "Introduction to Programming", 4, "Mon/Wed 10:00-11:30");
    Course cs201("CS201", "Data Structures", 4, "Tue/Thu 13:00-14:30");

    student1.display();
    prof1.display();
    staff1.display();

    student1.addCourse(&cs101);
    prof1.assignCourse(&cs101);
    prof1.assignCourse(&cs201);

    cs101.display();
    cs201.display();

    student1.update("124 Campus Rd", "555-0102", "john.doe@uni.edu");
    prof1.setSalary(90000);
    staff1.setPosition("Senior Office Manager");

    student1.display();
    prof1.display();
    staff1.display();

    return 0;
}