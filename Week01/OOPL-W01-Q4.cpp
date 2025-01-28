#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{

    float kg = 0.0;

    cout << "Enter weight of an individual in kilograms: " << endl;
    cin >> kg;

    cout << "The weight of the individual in kilograms is: " << fixed << setprecision(2) << kg << endl;

    // printing out the two decimal places part with a new technique

    float p = kg * 2.2;

    p = (p * 100 + 0.5);
    int truncated_p = static_cast <int> (p);

    int int_p =  truncated_p / 100;
    int dec_p = truncated_p % 100;

    cout << "The weight of the individual in kilograms is: " << int_p << ".";

    if (dec_p < 10)
    {
        cout << "0";
    }

    cout << dec_p << endl;

    return 0;
}

