#include <iostream>
using namespace std;

int main(void)
{

    float *ray;
    int len = 0;

    cout << "Enter the number of elements that you would like to enter in your array: " << endl;
    cin >> len;

    for (int m = 0; m < len; m++)
    {
        cout << "Enter data element at [" << m << "] - " << endl; 
        cin >> *(ray+m) >> endl;
    }    

    float largest = *ray;

    for (int m = 0; m < len; m++)
    {
        if ( *(ray+m) > largest)
        {
            largest = *(ray+m);
        }
    }

    float s_largest = *ray;

    for (int m = 0; m < len; m++)
    {
        if (s_largest < *(ray+m) && s_largest < largest)
        {
            s_largest = *(ray+m);
        }
    } 

    return 0;
}