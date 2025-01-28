#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{

    string name;
    float ray[5];

    // cout << "Enter Name: ";
    getline(cin, name);

    // cout << "Enter test scores: ";
    cin >> ray[0] >> ray[1] >> ray[2] >> ray[3] >> ray[4];

    cout << "Student name: " << name << endl;
    cout << "Test scores: ";

    for (int m = 0; m < 5; m++)
    {
        cout << fixed << setprecision(2) << ray[m] << " ";
    }

    cout << endl;

    float sum = 0.0;

    for (int m = 0; m < 5; m++)
    {
        sum += ray[m];
    }

    float avg = sum / 5;

    // This commented out line below in the easy way out for getting decimal places upto a fixed precision, as per our desires, 
    // However, I have also used applied a method without any standard library funcvtions to implement the same functionality
    // for learning pupose

    // cout << "Average test score: " << fixed << setprecision(2) << avg << endl;

    // The more techinal but lovely way, in my opinion.

    avg = (avg * 100 + 0.5);
    int t_part = static_cast <int> (avg);

    int int_p = t_part / 100;
    int dec_p = t_part % 100;

    cout < "Average test score: " << int_p; 

    if (dec_p < 10)
    {
        cout << "0";
    }

    cout << decp << endl;

    return 0;
}