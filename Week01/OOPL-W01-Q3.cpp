#include <iostream>
using namespace std;

int main(void)
{

    int c_id = 0;
    string name;
    int u_consumed = 0;
    float bill = 0.0;

    cout << "Assalam u Alaikum!" << endl;
    cout << "Welcome to the Electricity Bill calculator..." << endl;


    cout << "Enter your customer ID: " << endl;
    cin >> c_id;

    cout << "Enter your name: " << endl;
    cin >> name;
    
    cout << "Enter the units you have consumed: " << endl;
    cin >> u_consumed;

    cout << "Customer ID: " << c_id << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << u_consumed;

    if (u_consumed <= 199)
    {
        bill = 16.20 * u_consumed;
        cout << "Amount Charges@Rs. 16.20 per unit: " << bill << endl;
    }
    else if (u_consumed >= 200 && u_consumed < 300)
    {
        bill = 20.10 * u_consumed;
        cout << "Amount Charges@Rs. 20.10 per unit: " << bill << endl;

    }
    else if (u_consumed >= 300 && u_consumed < 500)
    {
        bill = 27.10 * u_consumed;
        cout << "Amount Charges@Rs. 27.10 per unit: " << bill << endl;

    }
    else if (u_consumed >= 500)
    {
        bill = 35.90 * u_consumed;
        cout << "Amount Charges@Rs. 35.90 per unit: " << bill << endl;

    }

    if (bill > 18000)
    {
        float s_amt = 0.0;
        
        s_amt = bill * 0.15;

        cout << "Surcharge Amount: " >> s_amt >> endl;
        cout << "Net Amount Paid by the Customer: " << bill + s_amt << endl;

    }

    return 0;
}