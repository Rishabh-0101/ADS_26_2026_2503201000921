#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

string fun(string infix) {
    string postfix = "";
    stack<char> st;

    for (char ch : infix) {

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            st.push(ch);
        }

        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        else { // operator
            while (!st.empty() &&
                   st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                    (precedence(st.top()) == precedence(ch) && ch == '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Swap '(' and ')'
    for (char &ch : infix) {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    // Convert reversed infix to postfix
    string postfix = fun(infix);

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;
    cin >> infix;

    cout << infixToPrefix(infix);

    return 0;
}