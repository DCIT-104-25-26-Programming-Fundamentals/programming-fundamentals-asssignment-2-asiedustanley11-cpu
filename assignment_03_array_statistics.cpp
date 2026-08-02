// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Returns the sum of all elements in the array.
int getSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
 
// Returns the average of all elements in the array, as a double so
// fractional results (like 4.6) are preserved instead of truncated.
double getAverage(int arr[], int size) {
    int sum = getSum(arr, size);
    return static_cast<double>(sum) / size;
}
 
// Returns the largest value in the array.
int getMax(int arr[], int size) {
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}
 
// Returns the smallest value in the array.
int getMin(int arr[], int size) {
    int minValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}
 
int main() {
    int n;
 
    cout << "How many numbers? ";
    cin >> n;
 
    if (cin.fail()) {
        cout << "Please enter a valid whole number." << endl;
        return 1;
    }
 
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }
 
    // Dynamically allocate an array of size n, since n is only known
    // at run time (not fixed at compile time).
    int* numbers = new int[n];
 
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
 
        if (cin.fail()) {
            cout << "Please enter a valid whole number." << endl;
            delete[] numbers;   // free the memory before exiting
            return 1;
        }
    }
 
    int sum = getSum(numbers, n);
    double average = getAverage(numbers, n);
    int maximum = getMax(numbers, n);
    int minimum = getMin(numbers, n);
 
    cout << endl;
    cout << "Results:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
 
    // Free the dynamically allocated memory now that we're done with it.
    delete[] numbers;
 
    return 0;
}