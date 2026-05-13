#include <iostream>
using namespace std;

int main() {
    char exp[100], stack[100];
    int top = -1;

    cout << "Enter expression: ";
    cin >> exp;

    for (int i = 0; exp[i] != '\0'; i++) {

        // Push opening brackets
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        }

        // Check closing brackets
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if (top == -1) {
                cout << "Not Balanced";
                return 0;
            }

            char last = stack[top--];

            if ((exp[i] == ')' && last != '(') ||
                (exp[i] == '}' && last != '{') ||
                (exp[i] == ']' && last != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (top == -1)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}