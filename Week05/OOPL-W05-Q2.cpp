#include <iostream>

using namespace std;

class Engine 
{
public:
    Engine() 
    {
        cout << "Engine created." << endl;
    }

    ~Engine() 
    {
        cout << "Engine destroyed." << endl;
    }
};

class Car 
{
private:
    Engine engine;

public:
    string name;
    int id;

    Car(const string& carName, int carId) : name(carName), id(carId) 
    {
        cout << "Car '" << name << "' created with ID: " << id << endl;
    }

    ~Car() 
    {
        cout << "Car '" << name << "' destroyed." << endl;
    }

    void display() const 
    {
        cout << "Car: " << name << ", ID: " << id << endl;
    }
};

class Garage 
{
private:
    Car* cars[3];
    int count = 0;

public:
    void parkCar(Car* car) 
    {
        if (count < 3) 
        {
            cars[count++] = car;
        }
    }

    void listCars() const 
    {
        cout << "Cars in the garage:" << endl;
        for (int i = 0; i < count; ++i) 
        {
            cars[i]->display();
        }
    }
};

int main() 
{
    Car car1("Toyota", 101);
    Car car2("Honda", 102);
    Car car3("Ford", 103);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();

    cout << "End of main function. Cars will be destroyed now." << endl;

    return 0;
}
