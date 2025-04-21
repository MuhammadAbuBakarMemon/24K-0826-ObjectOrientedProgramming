#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class Flight
{
private:
    std::string flightNumber;
    std::string departure;
    std::string arrival;
    int capacity;
    std::unordered_set<std::string> bookedSeats;
    std::unordered_set<std::string> upgradedSeats;

public:
    Flight(std::string num, std::string dep, std::string arr, int cap)
        : flightNumber(num), departure(dep), arrival(arr), capacity(cap) {}

    bool bookSeat(std::string seat)
    {
        if (bookedSeats.size() >= capacity)
            return false;
        return bookedSeats.insert(seat).second;
    }

    bool cancelSeat(std::string seat)
    {
        if (upgradedSeats.find(seat) != upgradedSeats.end())
        {
            upgradedSeats.erase(seat);
        }
        return bookedSeats.erase(seat);
    }

    bool upgradeSeat(std::string seat)
    {
        if (bookedSeats.find(seat) == bookedSeats.end())
            return false;
        return upgradedSeats.insert(seat).second;
    }

    int availableSeats() const
    {
        return capacity - bookedSeats.size();
    }

    std::string getFlightInfo() const
    {
        return flightNumber + ": " + departure + " to " + arrival;
    }
};

class Passenger
{
private:
    std::string id;
    std::string name;

public:
    Passenger(std::string pid, std::string pname) : id(pid), name(pname) {}

    bool requestBooking(Flight &flight, std::string seat)
    {
        return flight.bookSeat(seat);
    }

    bool requestCancellation(Flight &flight, std::string seat)
    {
        return flight.cancelSeat(seat);
    }

    bool requestUpgrade(Flight &flight, std::string seat)
    {
        return flight.upgradeSeat(seat);
    }

    std::string getPassengerInfo() const
    {
        return name + " (" + id + ")";
    }
};

int main()
{
    Flight nycSf("UA123", "JFK", "SFO", 150);
    Flight bosLa("AA456", "BOS", "LAX", 200);

    Passenger p1("P1001", "John Doe");
    Passenger p2("P1002", "Jane Smith");

    std::cout << nycSf.getFlightInfo() << " - Available: " << nycSf.availableSeats() << std::endl;
    std::cout << bosLa.getFlightInfo() << " - Available: " << bosLa.availableSeats() << std::endl;

    p1.requestBooking(nycSf, "12A");
    p2.requestBooking(nycSf, "15B");
    p1.requestBooking(bosLa, "8C");

    std::cout << "\nAfter bookings:" << std::endl;
    std::cout << nycSf.getFlightInfo() << " - Available: " << nycSf.availableSeats() << std::endl;
    std::cout << bosLa.getFlightInfo() << " - Available: " << bosLa.availableSeats() << std::endl;

    p1.requestUpgrade(nycSf, "12A");
    p2.requestCancellation(nycSf, "15B");

    std::cout << "\nAfter changes:" << std::endl;
    std::cout << nycSf.getFlightInfo() << " - Available: " << nycSf.availableSeats() << std::endl;
    std::cout << bosLa.getFlightInfo() << " - Available: " << bosLa.availableSeats() << std::endl;

    return 0;
}