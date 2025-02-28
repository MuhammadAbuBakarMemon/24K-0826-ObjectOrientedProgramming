#include <iostream>

class Car 
{
public:
    int engine_hp;
    int seating_capacity;
    int no_of_speakers;

    void setValues(int hp, int seats, int speakers) const 
    {
        const_cast<Car*>(this)->engine_hp = hp;
        const_cast<Car*>(this)->seating_capacity = seats;
        const_cast<Car*>(this)->no_of_speakers = speakers;
    }

    void display() const 
    {
        std::cout << "Engine Horsepower: " << engine_hp << std::endl;
        std::cout << "Seating Capacity: " << seating_capacity << std::endl;
        std::cout << "Number of Speakers: " << no_of_speakers << std::endl;
    }
};

int main() 
{
    Car myCar;
    myCar.setValues(300, 5, 6);
    myCar.display();
    return 0;
}
