//
// Created by Vladimir Petit-Homme on 10/19/2021.
//
#include "stack.h"

#include <iostream>
#include <string>

#include <locale>         // std::locale, std::isdigit


using namespace std;
string postfix;

stack operandStack;


bool isNumber(const string &s) {
    for (char const &ch: s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

bool isLetter(const string &s) {
    for (char const &ch: s) {
        if (std::isalpha(ch) == 0)
            return false;
    }
    return true;
}

int main() {
    string choice;

    do {

        int operandCount = 0;
        int operatorCount = 0;
        int stackCount = 0;
        cout << "Please enter a  postfix expression" << endl;
        getline(cin, postfix);
        for (int i = 0; i < postfix.length(); i++) {
            string operandValue = postfix.substr(i, 1);


            if (isLetter(operandValue) || isNumber(operandValue)) {
                operandStack.push(operandValue);
                operandCount++;
                stackCount++;
            }
            if (operandValue == "+" || operandValue == "*" || operandValue == "/" || operandValue == "-") {
                operatorCount++;
            }
            if (postfix[i] == ' ') {
                continue;
            }
            if (postfix.length() == 1 && operandValue == "+") {
                cout << "too many operators and not enough operands" << endl;

                break;
            }
            if (postfix.length() == 1) {
                string op1 = operandStack.top();
                operandStack.pop();
                operandStack.push("(" + op1 + ")");
                break;
            }


            if (operatorCount >= operandCount) {
                cout << "too many operators and not enough operands " << endl;

                operandStack.pop();
                break;


            }

            if (stackCount >= 3) {

                cout << "too many operands and not enough operators" << endl;
                operandStack.pop();
                operandStack.pop();
                operandStack.pop();
                break;
            }

            if (operandValue == "+" || operandValue == "*" || operandValue == "/" || operandValue == "-") {

                string op1 = operandStack.top();

                operandStack.pop();
                stackCount--;

                string op2 = operandStack.top();
                operandStack.pop();
                stackCount--;

                operandStack.push("(" + op2 + operandValue + op1 + ")");



            }



        }


        operandStack.print();


        operandStack.pop();  // clears the operand stack
        cout << "Please type y to continue : ";

        cin >> choice;

        getchar();

        cout << endl;


    } while (choice == "y" || choice == "Y");

    system("pause");

    return 0;
}
