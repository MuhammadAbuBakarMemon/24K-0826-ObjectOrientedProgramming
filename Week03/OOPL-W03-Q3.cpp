#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Glass
{

    public :
        int LiquidLevels;

        // using Member Initializer list
        // Glass() : LiquidLevels(200) {}

        // using Inline Initializer (Default Member Initializer)
        Glass()
        {
            LiquidLevels = 200;
        }

        void Drink(int mililiters)
        {

            if (mililiters <= 0)
            {
                cout << "Invalid amount, if one drinks a sip the amount drank must always be a positive value...." << endl;
                return 2;
            }

            if (mililiters > LiquidLevels)
            {
                cout << "Insufficient Fluid in the glass for you to successfully drink the desired amount...." << endl;
                return 2; 
            }

            LiquidLevels -= mililiters;
            cout << "The volume of liquid drunk was: " << mililiters << " and the volume of liquid left in the glass is: " << LiquidLevels << endl;

            if (mililiters < 100)
            {
                Refill();
            }

        }

        void Refill()
        {
            cout << "Glass has been refilled back to 200 milliliters" << endl;
            LiquidLevels = 200;
        }

};

int main(int argc, char* argv[])
{

    // applying guard clause

    if (argc <= 1)
    {
        cout << "Pass atleast one or more than one argument(s) into the function, in this format (command 1) (command 2)." << endl;
        cout << "The two possible options for you to choose for the commands are: drink {amount} or exit." << endl;
        return 1;
    }

    Glass g1;
    cout << "The Liquidlevel at the start is set to 200 milliliters." << endl;

    for (int m = 0; m < argc - 1; m++)
    {

        string cmd = argv[m+1];

        if (cmd == "exit")
        {
            cout << "You have chosen to stop drinking...." << endl;
            break;
        }

        else if (cmd == "drink")
        {

            if (m + 1 < argc)
            {

                try 
                {
                    g1.Drink(stoi(argv[m + 1]));
                    m++;
                }

                catch(invalid_argument&) 
                {
                    cout << "Invalid argument, enter a vallid number after drink command." << endl;
                }

            }
        }

        else 
        {
            cout << "The command " << cmd << " entered was invalid, either use 'drink' or 'exit'." << endl;
        }

    }

    return 0;
}