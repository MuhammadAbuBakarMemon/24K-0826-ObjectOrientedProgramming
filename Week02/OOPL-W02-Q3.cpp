
#include <iostream>
using namespace std;

int* resizeArray(int* ray, int& capacity) {
    capacity *= 2;
    int* newRay = new int[capacity];
    for (int i = 0; i < capacity / 2; i++) {
        newRay[i] = ray[i];
    }
    delete[] ray;
    return newRay;
}

int main() {
    int capacity = 5;
    int size = 0;
    int* ray = new int[capacity];

    cout << "Adding elements to the array..." << endl;

    for (int i = 1; i <= 12; i++) {
        if (size >= capacity) {
            ray = resizeArray(ray, capacity);
        }
        ray[size++] = i;
    }

    cout << "Array after adding 12 elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << ray[i] << " ";
    }
    cout << endl;
    cout << "Current size: " << size << ", Current capacity: " << capacity << endl;

    if (size < capacity) {
        int* newRay = new int[size];
        for (int i = 0; i < size; i++) {
            newRay[i] = ray[i];
        }
        delete[] ray;
        ray = newRay;
        capacity = size;
    }

    cout << "Array after finalizing resize to match the number of elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << ray[i] << " ";
    }
    cout << endl;
    cout << "Current size: " << size << ", Current capacity: " << capacity << endl;

    delete[] ray;

    return 0;
}

