#include <iostream>

int main(void)
{

    int len = 0;

    std::cout << "Specify the number of eleements you intend to store in your array: " << std::endl;
    std::cin >> len;

    int ray[len];

    for (int m = 0; m < len; m++)
    {
        std::cout << "Array[" << m << "] - " << std::endl;
        std::cin >> *(ray+m);
    }

    int sum = 0;

    for  (int m = 0; m < len; m++)
    {
        sum += *(ray+m);
    }

    std::cout << "The sum of all elements in the array is: " << sum << std::endl;

    return 0;
}