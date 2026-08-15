#include <iostream>
#include <stack>
#include <string>
#include<cctype>
#include<cmath>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        if(exp[i] == ' '){
            continue;
        }
        if (isdigit(exp[i])) {
            int num = 0;
            while (i < exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            st.push(num);
            i--;   
        }
        else {
            int B = st.top();
            st.pop();

            int A = st.top();
            st.pop();

            switch (exp[i]) {
                case '+':
                    st.push(A + B);
                    break;
                case '-':
                    st.push(A - B);
                    break;
                case '*':
                    st.push(A * B);
                    break;
                case '/':
                    st.push(A / B);
                    break;
                case '^':
                    st.push(pow(A,B));
                    break;
                default:
                    cout<<"Invalid Operator";
                
            }
        }
    }

    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin,exp);
    cout << "Result = " << evaluatePostfix(exp) << endl;

    return 0;
}