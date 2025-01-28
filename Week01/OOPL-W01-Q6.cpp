#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{

    string name;
    float ray[5];

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter test scores: "
    cin >> ray[0] >> ray[1] >> ray[2] >> ray[3] >> ray[4];

    cout << "Student name: " << name << endl;
    cout << "Test scores: ";

    for (int m = 0; m < 5; m++)
    {
        cout << fixed << setprecision(2) << ray[m];
    }

    cout << endl;

    float sum = 0.0;

    for (int m = 0; m < 5; m++)
    {
        sum += ray[m];
    }

    float avg = sum / 5;

    cout << "Average test score: " << fixed << setprecision(2) << avg << endl;

    return 0;
}