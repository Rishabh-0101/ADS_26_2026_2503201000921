#include <iostream>
#include <stack>
#include <cctype>
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

        else {
            while (!st.empty() &&
                  (precedence(st.top()) > precedence(ch) ||
                  (precedence(st.top()) == precedence(ch) && ch != '^'))) {
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

int main() {
    string infix;
    cin >> infix;

    cout << fun(infix);

    return 0;
}