#include <iostream>
#include <cstdlib>

class Date 
{

    private:
        int m;
        int d;
        int y;

    public:
        void displayDate()
        {
            std::cout << m << "/" << d << "/" << y << std::endl;
        }

        // setters for the month, date, and year in that order 

        void set_m(int x)
        {
            m = x;
        }

        void set_d(int y)
        {
            d = y;
        }

        void set_y(int z)
        {
            y = z;
        }

};

int main(int argc, char* argv[])
{

    // applying guard clause to check if the correct number of arguments are passed

    if (argc != 4)
    {
        std::cerr << "Incorrect number of arguments are passed into the function, the correct format is: " << argv[0] << " <Month> <Date> <Year>" << std::endl; 
        return 1;
    }

    Date t_day;

    t_day.set_m(std::stoi(argv[1]));
    t_day.set_d(std::atoi(argv[2]));
    t_day.set_y(std::stoi(argv[3]));

    std::cout << "The date is: " << std::endl;

    t_day.displayDate();

    return 0;
}