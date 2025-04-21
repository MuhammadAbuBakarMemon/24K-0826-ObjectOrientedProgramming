#include <iostream>
#include <string>
#include <vector>

class PatientRecord
{
private:
    std::string name;
    std::string id;
    std::string dob;
    std::string medicalHistory;
    std::vector<std::string> currentTreatments;
    std::vector<double> billingDetails;

    struct MedicalData
    {
        std::string history;
        std::vector<std::string> treatments;
    };

    MedicalData getMedicalData() const
    {
        return {medicalHistory, currentTreatments};
    }

    friend class Doctor;
    friend class Billing;

public:
    struct PublicData
    {
        std::string name;
        std::string id;
        std::string dob;
    };

    PatientRecord(std::string name, std::string id, std::string dob)
        : name(name), id(id), dob(dob) {}

    PublicData getPublicData() const
    {
        return {name, id, dob};
    }
};

class Doctor
{
public:
    void viewMedicalRecord(const PatientRecord &patient)
    {
        auto data = patient.getMedicalData();
        std::cout << "=== Medical Record ===" << std::endl;
        std::cout << "History: " << data.history << std::endl;
        std::cout << "Treatments: ";
        for (const auto &t : data.treatments)
            std::cout << t << ", ";
        std::cout << "\n=====================" << std::endl;
    }

    void updateMedicalHistory(PatientRecord &patient, const std::string &newHistory)
    {
        patient.medicalHistory = newHistory;
    }
};

class Billing
{
public:
    void addCharge(PatientRecord &patient, double amount)
    {
        patient.billingDetails.push_back(amount);
    }

    void viewBill(const PatientRecord &patient)
    {
        std::cout << "=== Billing Details ===" << std::endl;
        for (const auto &charge : patient.billingDetails)
        {
            std::cout << "$" << charge << std::endl;
        }
        std::cout << "=======================" << std::endl;
    }
};

class Receptionist
{
public:
    void tryAccessPrivateData(const PatientRecord &patient)
    {
    }

    void tryCallPrivateMethod(const PatientRecord &patient)
    {
    }
};

int main()
{
    PatientRecord patient("John Doe", "P12345", "1985-07-15");

    Doctor drHouse;
    Billing financeDept;
    Receptionist frontDesk;

    drHouse.updateMedicalHistory(patient, "Family history of hypertension");
    drHouse.viewMedicalRecord(patient);

    financeDept.addCharge(patient, 250.00);
    financeDept.addCharge(patient, 99.99);
    financeDept.viewBill(patient);

    auto publicInfo = patient.getPublicData();
    std::cout << "\nPublic Information:\nName: " << publicInfo.name
              << "\nID: " << publicInfo.id << std::endl;

    return 0;
}