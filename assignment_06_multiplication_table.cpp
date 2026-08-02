// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// Prints the multiplication table for "number", from 1 to 12.
void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
 
    for (int multiplier = 1; multiplier <= 12; multiplier++) {
        int product = number * multiplier;
        // setw(2) left-aligned would need left flag; here we just pad
        // the multiplier so results line up neatly even at 2 digits.
        cout << number << " x " << setw(2) << multiplier
             << " = " << product << endl;
    }
}
 
// -----------------------------------------------------------------------------
// PART B — Tables from 1 to N
// -----------------------------------------------------------------------------
// Prints the full multiplication table (1-12) for every number from
// 1 to n, separated by a divider line.
void printTablesUpTo(int n) {
    for (int number = 1; number <= n; number++) {
        printTable(number);
 
        // Add a separator line after each table except the very last one.
        if (number != n) {
            cout << string(27, '-') << endl;
        }
    }
}
 
// Reads a positive integer, returning true on success and false if the
// input was invalid (not a whole number, or not positive).
bool readPositiveInt(const string& prompt, int& value) {
    cout << prompt;
    cin >> value;
 
    if (cin.fail() || value <= 0) {
        return false;
    }
    return true;
}
 
int main() {
    // -------------------------------------------------------------------
    // PART A — Single table
    // -------------------------------------------------------------------
    int number;
    if (!readPositiveInt("Enter a number: ", number)) {
        cout << "Error: please enter a positive integer." << endl;
        return 1;
    }
 
    printTable(number);
 
    // -------------------------------------------------------------------
    // PART B — Tables from 1 to N
    // -------------------------------------------------------------------
    cout << endl;
    int n;
    if (!readPositiveInt("Enter N to print tables from 1 to N: ", n)) {
        cout << "Error: please enter a positive integer." << endl;
        return 1;
    }
 
    cout << endl;
    printTablesUpTo(n);
 
    return 0;
}