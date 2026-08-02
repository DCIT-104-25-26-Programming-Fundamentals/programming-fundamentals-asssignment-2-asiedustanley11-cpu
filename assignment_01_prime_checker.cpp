// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Returns true if n is a prime number, false otherwise.
bool isPrime(int n) {
    // Numbers less than 2 are never prime.
    if (n < 2) {
        return false;
    }
 
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
 
    // No other even number can be prime.
    if (n % 2 == 0) {
        return false;
    }
 
    // Check odd divisors up to the square root of n.
    // If n has a factor larger than its square root, it must also have
    // a corresponding factor smaller than the square root, so checking
    // up to sqrt(n) is enough.
    for (int divisor = 3; divisor * divisor <= n; divisor += 2) {
        if (n % divisor == 0) {
            return false;
        }
    }
 
    return true;
}
 
int main() {
    int number;
 
    cout << "Enter a number: ";
    cin >> number;
 
    // Basic protection against non-numeric input, so the program
    // doesn't loop forever or behave unpredictably.
    if (cin.fail()) {
        cout << "Please enter a valid whole number." << endl;
        return 1;
    }
 
    // Call the function and print the result.
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
 
    return 0;
}