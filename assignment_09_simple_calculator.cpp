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
// Addition
double add(double a, double b) {
    return a + b;
}

// Subtraction
double subtract(double a, double b) {
    return a - b;
}

// Multiplication
double multiply(double a, double b) {
    return a * b;
}

// Division
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Cannot divide by zero.");
    }
    return a / b;
}

// Modulus (works with integers)
int modulus(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: Cannot perform modulus with zero.");
    }
    return a % b;
}

// Exponentiation
double exponentiate(double base, int exp) {
    return pow(base, exp);
}

// Menu display
void showMenu() {
    cout << "\n============================\n";
    cout << "       SIMPLE CALCULATOR     \n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        double num1, num2;
        int int1, int2;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter first number : ";
                    cin >> num1;
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                    break;

                case 2:
                    cout << "Enter first number : ";
                    cin >> num1;
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                    break;

                case 3:
                    cout << "Enter first number : ";
                    cin >> num1;
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                    break;

                case 4:
                    cout << "Enter first number : ";
                    cin >> num1;
                    cout << "Enter second number: ";
                    cin >> num2;
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                    break;

                case 5:
                    cout << "Enter first integer : ";
                    cin >> int1;
                    cout << "Enter second integer: ";
                    cin >> int2;
                    cout << "Result: " << int1 << " % " << int2 << " = " << modulus(int1, int2) << endl;
                    break;

                case 6:
                    cout << "Enter base number : ";
                    cin >> num1;
                    cout << "Enter exponent (integer): ";
                    cin >> int2;
                    cout << fixed << setprecision(2);
                    cout << "Result: " << num1 << " ^ " << int2 << " = " << exponentiate(num1, int2) << endl;
                    break;

                case 7:
                    cout << "Goodbye!" << endl;
                    break;

                default:
                    cout << "Error: Invalid choice. Please enter 1-7." << endl;
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }

    } while (choice != 7);

    return 0;
}

