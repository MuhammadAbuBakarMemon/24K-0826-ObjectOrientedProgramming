#include <string>

class Student {
public:
    virtual double getTuition(const std::string& status, int creditHours) const = 0;
    virtual ~Student() = default;
};

class GraduateStudent : public Student {
private:
    std::string researchTopic;

public:
    
    double getTuition(const std::string& status, int creditHours) const override {
        if (status == "undergraduate") return 200 * creditHours;
        else if (status == "graduate") return 300 * creditHours;
        else if (status == "doctoral") return 400 * creditHours;
        return 0; // Handle invalid status if needed
    }

    void setResearchTopic(const std::string& topic) {
        researchTopic = topic;
    }

    std::string getResearchTopic() const {
        return researchTopic;
    }
};