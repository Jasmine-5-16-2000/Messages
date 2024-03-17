#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2, result;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error! Division by zero.";
                return 1; // Exiting program if division by zero occurs
            }
            break;
        default:
            cout << "Invalid operator!";
            return 1; // Exiting program if invalid operator is entered
    }

    cout << "Result: " << result;

    return 0;
}
