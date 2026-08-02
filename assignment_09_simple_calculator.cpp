// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}
 
double subtract(double a, double b) {
    return a - b;
}
 
double multiply(double a, double b) {
    return a * b;
}
 
// Divides a by b. Throws a runtime_error if b is 0, so the caller
// can catch it and print a friendly message instead of crashing.
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Cannot divide by zero.");
    }
    return a / b;
}
 
// Returns the remainder of a / b. Uses fmod() from <cmath> since C++'s
// built-in % operator only works on whole numbers (int), not decimals.
// Named modOperation (not "modulus") to avoid clashing with std::modulus,
// a built-in name the standard library defines behind the scenes.
double modOperation(double a, double b) {
    if (b == 0) {
        throw runtime_error("Cannot divide by zero.");
    }
    return fmod(a, b);
}
 
// Uses pow() from <cmath> to raise a to the power of b.
double exponentiate(double a, double b) {
    return pow(a, b);
}
 
// Prints the calculator's main menu.
void showMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}
 
int main() {
    // Symbols shown in the "Result: a SYMBOL b = result" line, indexed
    // to match each menu choice (index 0 is unused, since choices start at 1).
    string symbols[] = {"", "+", "-", "*", "/", "%", "^"};
 
    while (true) {
        showMenu();
        cout << "Select an operation (1-7): ";
 
        int choice;
        cin >> choice;
 
        if (cin.fail()) {
            cout << "Invalid choice. Please select a number from 1 to 7." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl;
            continue;
        }
 
        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }
 
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please select a number from 1 to 7." << endl;
            cout << endl;
            continue;
        }
 
        cout << "Enter first number : ";
        double firstNumber;
        cin >> firstNumber;
 
        if (cin.fail()) {
            cout << "Invalid number entered." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl;
            continue;
        }
 
        cout << "Enter second number: ";
        double secondNumber;
        cin >> secondNumber;
 
        if (cin.fail()) {
            cout << "Invalid number entered." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl;
            continue;
        }
 
        // Route to the correct operation function based on the menu choice.
        double result = 0;
        bool success = true;
 
        try {
            switch (choice) {
                case 1: result = add(firstNumber, secondNumber); break;
                case 2: result = subtract(firstNumber, secondNumber); break;
                case 3: result = multiply(firstNumber, secondNumber); break;
                case 4: result = divide(firstNumber, secondNumber); break;
                case 5: result = modOperation(firstNumber, secondNumber); break;
                case 6: result = exponentiate(firstNumber, secondNumber); break;
            }
        } catch (const runtime_error& error) {
            cout << "Error: " << error.what() << endl;
            success = false;
        }
 
        if (success) {
            cout << fixed << setprecision(2);
            cout << "Result: " << firstNumber << " " << symbols[choice]
                 << " " << secondNumber << " = " << result << endl;
        }
 
        cout << endl;
    }
 
    return 0;
}