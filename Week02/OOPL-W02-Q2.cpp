#include <iostream>

using namespace std;

void* addToArray(void* ray, int size) {
    int* intRay = static_cast<int*>(ray);
    for (int i = 0; i < size; ++i) {
        intRay[i] += 10;
    }
    return ray;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "Please provide array elements as arguments." << endl;
        return 1;
    }

    int size = argc - 1;
    int* ray = new int[size];

    for (int i = 0; i < size; ++i) {
        ray[i] = stoi(argv[i + 1]);
    }

    ray = static_cast<int*>(addToArray(static_cast<void*>(ray), size));

    cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        cout << ray[i] << " ";
    }
    cout << endl;

    delete[] ray;

    return 0;
}
