#include <iostream>
#include <string>
using namespace std;


class Student {
public:
    
    virtual double getTuition(string status, int creditHours) = 0;
    
    
    virtual ~Student() {}
};


class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    // Override getTuition function
    double getTuition(string status, int creditHours) override {
        if (status == "undergraduate") {
            return creditHours * 200;
        } else if (status == "graduate") {
            return creditHours * 300;
        } else if (status == "doctoral") {
            return creditHours * 400;
        } else {
            cout << "Invalid status provided!" << endl;
            return 0.0;
        }
    }
};

// Main function
int main() {
    GraduateStudent gradStudent;
    

    gradStudent.setResearchTopic("Artificial Intelligence in Education");


    string status;
    int creditHours;

    cout << "Enter student status (undergraduate / graduate / doctoral): ";
    cin >> status;

    cout << "Enter number of credit hours: ";
    cin >> creditHours;


    cout << "\nResearch Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition Fee: $" << gradStudent.getTuition(status, creditHours) << endl;

    return 0;
}
