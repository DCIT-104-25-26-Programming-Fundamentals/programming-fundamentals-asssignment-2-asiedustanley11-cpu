// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// PART A — Print the first N terms
// -----------------------------------------------------------------------------
// Prints the first n Fibonacci numbers on one line, separated by spaces.
void printFibonacciTerms(int n) {
    int a = 0;
    int b = 1;
 
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i != n - 1) {
            cout << " ";
        }
 
        // Slide the two "tracking" values forward, using a temporary
        // variable since C++ doesn't support Python's tuple swapping.
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}
 
// -----------------------------------------------------------------------------
// PART B — Check membership
// -----------------------------------------------------------------------------
// Returns true if "number" appears in the Fibonacci sequence, false otherwise.
bool isFibonacciNumber(int number) {
    // Negative numbers are never part of the sequence.
    if (number < 0) {
        return false;
    }
 
    int a = 0;
    int b = 1;
 
    // Generate Fibonacci numbers, stopping once we reach or pass the target.
    while (a < number) {
        int next = a + b;
        a = b;
        b = next;
    }
 
    // After the loop, "a" is either equal to the number (found it)
    // or has jumped past it (not a Fibonacci number).
    return a == number;
}
 
int main() {
    // -------------------------------------------------------------------
    // PART A — Print the first N terms
    // -------------------------------------------------------------------
    int n;
    cout << "How many terms? ";
    cin >> n;
 
    if (cin.fail() || n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }
 
    printFibonacciTerms(n);
 
    // -------------------------------------------------------------------
    // PART B — Check if a number belongs to the sequence
    // -------------------------------------------------------------------
    int number;
    cout << "Enter a number to check: ";
    cin >> number;
 
    if (cin.fail()) {
        cout << "Please enter a valid whole number." << endl;
        return 1;
    }
 
    if (isFibonacciNumber(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }
 
    return 0;
}