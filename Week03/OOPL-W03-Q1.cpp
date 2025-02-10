#include <iostream>
#include <string>

class User
{

    public:
        int Age;
        std::string Name;

};

int main(int argc, char* argv[])
{

    // guard clause applied
    /*
    A guard clause is a type of programming pattern that in which you can check for particular condition (in our case checking the number of 
    command line arguments into our function), these condition are checked before continuing on with the programs flow contol/logic 
    If the condition is failed to be met it exits the function early by printing an error message gurading the rest of teh main function
    */

    if (argc != 3)
    {
        std::cout << "Incorrect arguments were passed into the function, the correct format for passing arguments is" << argv[0] << "<Name> <Age>." << std::endl;

        // we can also use the alternative standard error stream in c++ that is used interchangibly for printing out error messages to the terminal 
        // window or the standard error output or the console

        std::cerr << "Incorrect arguments were passed into the function, the correct format for passing arguments is" << argv[0] << "<Name> <Age>." << std::endl;

        return 1;
        /*
        We use return 1 as a conventional (non-zero exit code for our programs), signaling that an error has occured 
        */
    }

    User obj;
    obj.Name = argv[1];

    try
    {
        obj.Age = std::stoi(argv[2]);
    }

    catch (const std::exception& e) 
    {
        std::cerr <<  argv[2] << " is an Invlid Age" << std::endl;
        return 2;
    }

    std::cout << "My name is {" << obj.Name << "} and I'm {" << obj.Age << "} years old." << std::endl;

    return 0;

}