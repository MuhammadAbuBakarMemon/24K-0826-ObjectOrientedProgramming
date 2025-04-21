#include <iostream>
#include <string>

class Car
{
protected:
    std::string model;
    double price;

public:
    Car(const std::string &m, double p) : model(m), price(p) {}

    std::string getModel() const
    {
        return model;
    }

    double getPrice() const
    {
        return price;
    }

    void setModel(const std::string &m)
    {
        model = m;
    }

    virtual void setPrice(double p) = 0;

    virtual void display() const
    {
        std::cout << "Model: " << model << ", Price: $" << price;
    }

    virtual ~Car() {}
};

class Color : public Car
{
private:
    std::string color;

public:
    Color(const std::string &m, double p, const std::string &c)
        : Car(m, p), color(c) {}

    void setPrice(double p) override
    {
        price = p * 0.9; 
    }

    void display() const override
    {
        Car::display();
        std::cout << ", Color: " << color << std::endl;
    }
};

class Company : public Car
{
private:
    std::string company;

public:
    Company(const std::string &m, double p, const std::string &comp)
        : Car(m, p), company(comp) {}

    void setPrice(double p) override
    {
        price = p * 1.1; 
    }

    void display() const override
    {
        Car::display();
        std::cout << ", Company: " << company << std::endl;
    }
};

int main()
{
    Color colorCar("Sedan", 30000, "Red");
    Company companyCar("SUV", 45000, "Tesla");

    colorCar.setPrice(30000);
    companyCar.setPrice(45000);

    std::cout << "Color Car Details:" << std::endl;
    colorCar.display();

    std::cout << "\nCompany Car Details:" << std::endl;
    companyCar.display();

    return 0;
}