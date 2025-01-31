#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{

    if (argc <= 1)
    {
        cout << "The program is coded in a manner that it requires the elements of your array as command line arguments...." << endl;
        return 1;
        // so as to ensure the differentiate that the program is returned with an exit code of 1, which can allow us to differentiate from thr default 'return 0' statement for the program's ending....
    }

    int size = argc - 1;

    int ray[size];
    
    for (int m = 0; m < size; m++)
    {
        *(ray+m) = atoi(argv[m + 1]);
    }

    // computing the sum

    int tot = 0;

    // need to copy the base address of our array to traverse it, because if we don't and still attempt to traverse it the the compiler will most probably throw an error, it is because if the compiler 
    // allowed us to traverse on the pointer with the base address of the array, then incrementing the base address to get the next data element from the array -stored in pointwer notation- would result 
    // in the programmer loosing the pointer to the base address of the array
    // and we copied the base address of the initial array into a pointer, 

    int *trav = ray;

    for (int m = 0; m < size; m++)
    {
        tot += *(trav+m);
    }

    cout << "The sum of the elements in the array you entered is: " << tot << endl;

    return 0;
}