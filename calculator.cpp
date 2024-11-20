#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void showMenu();
void performBasicOperation();
void performTrigonometricOperation();
void performPowerOperation(double *base, double *exponent);
void displayResults(double *result);

struct Operation {
    char name[50];
    double result;
};

int main() {
    char choice[10];
    Operation history[100];
    int historyCount = 0;

    do {
        showMenu();
        cout << "Enter your choice (or 'exit' to quit): ";
        cin >> choice;

        if (strcmp(choice, "basic") == 0) {
            performBasicOperation();
        } else if (strcmp(choice, "trig") == 0) {
            performTrigonometricOperation();
        } else if (strcmp(choice, "power") == 0) {
            double base, exponent, result;
            cout << "Enter base: ";
            cin >> base;
            cout << "Enter exponent: ";
            cin >> exponent;
            performPowerOperation(&base, &exponent);
            result = pow(base, exponent);
            displayResults(&result);

            // Store result in history
            strcpy(history[historyCount].name, "Power Calculation");
            history[historyCount].result = result;
            historyCount++;
        } else if (strcmp(choice, "history") == 0) {
            cout << "\nCalculation History:\n";
            for (int i = 0; i < historyCount; i++) {
                cout << history[i].name << ": " << history[i].result << endl;
            }
        } else if (strcmp(choice, "exit") != 0) {
            cout << "Invalid choice, please try again.\n";
        }
    } while (strcmp(choice, "exit") != 0);

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}

void showMenu() {
    cout << "\n===== Calculator Menu =====\n";
    cout << "Type 'basic'  - Perform basic operations (+, -, *, /).\n";
    cout << "Type 'trig'   - Perform trigonometric calculations (sin, cos, tan).\n";
    cout << "Type 'power'  - Perform power calculations.\n";
    cout << "Type 'history' - View calculation history.\n";
    cout << "Type 'exit'   - Quit the program.\n";
    cout << "===========================\n";
}

void performBasicOperation() {
    double num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    double result;
    switch (op) {
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
                cout << "Error: Division by zero is not allowed.\n";
                return;
            }
            break;
        default:
            cout << "Invalid operator.\n";
            return;
    }
    cout << "Result: " << result << endl;
}

void performTrigonometricOperation() {
    double angle;
    char trigFunc[10];
    cout << "Enter trigonometric function (sin, cos, tan): ";
    cin >> trigFunc;
    cout << "Enter angle in degrees: ";
    cin >> angle;

    double radians = angle * M_PI / 180.0; 
    double result;

    if (strcmp(trigFunc, "sin") == 0) {
        result = sin(radians);
    } else if (strcmp(trigFunc, "cos") == 0) {
        result = cos(radians);
    } else if (strcmp(trigFunc, "tan") == 0) {
        result = tan(radians);
    } else {
        cout << "Invalid trigonometric function.\n";
        return;
    }
    cout << "Result: " << result << endl;
}

void performPowerOperation(double *base, double *exponent) {
    cout << "Base: " << *base << ", Exponent: " << *exponent << endl;
}

void displayResults(double *result) {
    cout << "The result is: " << *result << endl;
}
