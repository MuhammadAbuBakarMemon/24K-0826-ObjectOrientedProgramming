#include <iostream>
#include <string>

class Student
{
protected:
    std::string name;
    int rollNo;

public:
    Student(std::string name, int rollNo) : name(name), rollNo(rollNo) {}

    virtual void displayStudentInfo()
    {
        std::cout << "Name: " << name << "\nRoll Number: " << rollNo << std::endl;
    }

    virtual ~Student() {}
};

class Marks : public Student
{
protected:
    int course1, course2, course3;

public:
    Marks(std::string name, int rollNo, int course1, int course2, int course3)
        : Student(name, rollNo), course1(course1), course2(course2), course3(course3) {}

    void displayMarks()
    {
        std::cout << "Marks in Course 1: " << course1 << "\nMarks in Course 2: " << course2
                  << "\nMarks in Course 3: " << course3 << std::endl;
    }

    virtual ~Marks() {}
};

class Result : public Marks
{
private:
    int totalMarks;
    float averageMarks;

public:
    Result(std::string name, int rollNo, int course1, int course2, int course3)
        : Marks(name, rollNo, course1, course2, course3), totalMarks(0), averageMarks(0) {}

    void calculateResult()
    {
        totalMarks = course1 + course2 + course3;
        averageMarks = totalMarks / 3.0;
    }

    void displayResult()
    {
        calculateResult();
        displayStudentInfo();
        displayMarks();
        std::cout << "Total Marks: " << totalMarks << "\nAverage Marks: " << averageMarks << std::endl;
    }

    virtual ~Result() {}
};

int main()
{
    Result studentResult("John Doe", 12345, 85, 90, 88);
    studentResult.displayResult();

    return 0;
}
