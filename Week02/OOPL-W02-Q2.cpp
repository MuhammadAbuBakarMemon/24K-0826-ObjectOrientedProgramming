#include <iostream>
using namespace std;

void * add_ops(void *ray, int s);

int main(void)
{

    int size = 0;

    cout << "Enter the number of elments you would like in your array: " << endl;
    cin >> size;

    int *ray = new int[size];
    // int ray[size];

    cout << "Enter data elements in to your array." << endl;

    for (int m = 0; m < size; m++)
    {

        cout << "Array[" << m << "] - " << endl;
        cin >> *(ray+m);

    }

    ray = static_cast <int*> ( add_ops(ray, size) );

    cout << "Array after performing the additive operation: " << endl;

    for (int m = 0; m < size; m++)
    {
        cout << "Array[" << m << "] - " << *(ray+m) << endl;
    }

    delete[] ray;

    return 0;
}

/*
Using Main Arguments or Command Line Arguments for the same task / operation
*/

// int main(int argc, char * argv[])
// {

//     if (argc <= 1)
//     {
//         cout << "Kindly consider to enter data elements as arguments to your array...." << endl;
//         return 1;
//     }

//     int size = argc - 1;
//     int *ray = new int[size];

//     for (int m = 0; m < size; m++)
//     {
//         *(ray+m) = stoi(*(argv+m+1)); 
//     } 

//     ray = static_cast <int*> ( add_ops(ray, size) );

//     cout << "Array after performing the additive operation: " << endl;

//     for (int m = 0; m < size; m++)
//     {
//         cout << "Array[" << m << "] - " << *(ray+m) << endl;
//     }

//     // freeing the memory to prevent from memory leakages
//     delete[] ray;


//     return 0;
// }

void * add_ops(void *ray, int s)
{

    int a = 0;

    cout << "Enter the value you would like to perform an add operation onto each element of: " << endl;
    cin >> a;

    // traverser (temporary pointer) to preserve the base address of our array

    int *trav = static_cast <int*> (ray);

    for (int m = 0; m < s; m++)
    {
        *(trav+m) += a;
    }

    return ray;

}
