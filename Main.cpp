#include <iostream>
#include <stack>
#include <string>

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosingBracket(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

bool areMatchingBrackets(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
        (opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']');
}

bool checkBrackets(const std::string& expression) {
    std::stack<char> bracketsStack;

    for (char ch : expression) {
        if (isOpeningBracket(ch)) {
            bracketsStack.push(ch);
        }
        else if (isClosingBracket(ch)) {
            if (bracketsStack.empty() || !areMatchingBrackets(bracketsStack.top(), ch)) {
                return false;  // Incorrect bracket pair or extra closing bracket
            }
            bracketsStack.pop();
        }
    }

    return bracketsStack.empty();  // If the stack is empty, all brackets are correctly matched
}

int main() {
    std::string expression;
    std::cout << "Enter a string with brackets: ";
    std::getline(std::cin, expression);

    if (checkBrackets(expression)) {
        std::cout << "Brackets are placed correctly." << std::endl;
    }
    else {
        std::cout << "Brackets are placed incorrectly." << std::endl;
    }

    return 0;
}
