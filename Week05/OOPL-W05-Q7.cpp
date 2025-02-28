#include <iostream>

class Student 
{
public:
    const int roll_no;
    
    Student() : roll_no(0) {}
    
    void setRollNo(int roll) 
    {
        const_cast<int&>(roll_no) = roll;
    }
    
    void display() 
    {
        std::cout << "Student Roll Number: " << roll_no << std::endl;
    }
};

int main() 
{
    Student student;
    
    int roll;
    std::cout << "Enter the student's roll number: ";
    std::cin >> roll;
    
    student.setRollNo(roll);
    
    student.display();
    
    return 0;
}
