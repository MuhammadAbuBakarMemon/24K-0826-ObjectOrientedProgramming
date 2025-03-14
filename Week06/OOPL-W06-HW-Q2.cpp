#include <iostream>
#include <string>

class Vehicles
{
protected:
    double price;

public:
    Vehicles(double price) : price(price) {}

    virtual void displayDetails() = 0;

    virtual ~Vehicles() {}
};

class Car : public Vehicles
{
protected:
    int seatingCapacity;
    int numDoors;
    std::string fuelType;

public:
    Car(double price, int seatingCapacity, int numDoors, std::string fuelType)
        : Vehicles(price), seatingCapacity(seatingCapacity), numDoors(numDoors), fuelType(fuelType) {}

    void displayDetails() override
    {
        std::cout << "Price: " << price << "\nSeating Capacity: " << seatingCapacity
                  << "\nNumber of Doors: " << numDoors << "\nFuel Type: " << fuelType << std::endl;
    }
};

class Motorcycle : public Vehicles
{
protected:
    int numCylinders;
    int numGears;
    int numWheels;

public:
    Motorcycle(double price, int numCylinders, int numGears, int numWheels)
        : Vehicles(price), numCylinders(numCylinders), numGears(numGears), numWheels(numWheels) {}

    void displayDetails() override
    {
        std::cout << "Price: " << price << "\nNumber of Cylinders: " << numCylinders
                  << "\nNumber of Gears: " << numGears << "\nNumber of Wheels: " << numWheels << std::endl;
    }
};

class Audi : public Car
{
private:
    std::string modelType;

public:
    Audi(double price, int seatingCapacity, int numDoors, std::string fuelType, std::string modelType)
        : Car(price, seatingCapacity, numDoors, fuelType), modelType(modelType) {}

    void displayDetails() override
    {
        Car::displayDetails();
        std::cout << "Model Type: " << modelType << std::endl;
    }
};

class Yamaha : public Motorcycle
{
private:
    std::string makeType;

public:
    Yamaha(double price, int numCylinders, int numGears, int numWheels, std::string makeType)
        : Motorcycle(price, numCylinders, numGears, numWheels), makeType(makeType) {}

    void displayDetails() override
    {
        Motorcycle::displayDetails();
        std::cout << "Make Type: " << makeType << std::endl;
    }
};

int main()
{
    Vehicles *audi = new Audi(50000, 5, 4, "Petrol", "A6");
    Vehicles *yamaha = new Yamaha(15000, 4, 5, 2, "YZF-R1");

    audi->displayDetails();
    yamaha->displayDetails();

    delete audi;
    delete yamaha;

    return 0;
}
