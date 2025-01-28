#include <iostream>
using namespace std;

int main(void)
{

    int size = 0;

    cout << "Enter the number of elements that you want in your array: " << endl;
    cin >> size;

    float ray[size];

    for (int m = 0; m < size; m++)
    {
        cout << "Data Element at Index Position - " << m << ": " << endl;
        cin >> *(ray+m);
    }

    float *h, *s_h;

    h = (ray+0);
    s_h = (ray+0);

    for  (int m = 0; m < size; m++)
    {
        if ( *(ray+m) > *h)
        {
            s_h = h;
            h = (ray+m);   
        }
        else if ( *(ray+m) != *h && *(ray+m) > *s_h)
        {
            s_h = (ray+m);
        }
    }

    cout << "The secong largest number from the specified input would be: " << *s_h << endl;

    return 0;
}