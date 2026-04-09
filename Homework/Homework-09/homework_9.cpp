#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception class
class CustomException : public exception {
public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};

// Division function
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }

    return (double)numerator / denominator;
}

// Array access function
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }

    return arr[index];
}

// Function that throws exception
void nestedFunction() {
    throw CustomException();
}

// Function that catches and rethrows exception
void outerFunction() {
    try {
        nestedFunction();
    }
    catch (CustomException& e) {
        cout << "Caught exception in outerFunction: " << e.what() << endl;
        throw;
    }
}

int main() {
    // Nested exception part
    try {
        outerFunction();
    }
    catch (CustomException& e) {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }

    cout << endl;

    // Division part
    int numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        double result = divide(numerator, denominator);
        cout << "Result: " << result << endl;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl;

    // Array part
    int size, index;

    cout << "Enter array size: ";
    cin >> size;

    int arr[100];

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    cout << "Enter index to access: ";
    cin >> index;

    try {
        cout << "Value: " << accessArray(arr, size, index) << endl;
    }
    catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}