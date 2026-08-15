#include <iostream>
#include <stack>
#include <string>
#include<cctype>
#include<cmath>
using namespace std;

int evaluatePrefix(string exp) {
    stack<int> st;

    for (int i = exp.length() - 1; i >= 0; i--) {

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
            int A = st.top();
            st.pop();

            int B = st.top();
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
                    return -1;
                
            }
        }
    }

    return st.top();
}

int main() {
    string exp;
    cout << "Enter prefix expression: ";
    getline(cin,exp);
    
    cout << "Result = " << evaluatePrefix(exp) << endl;

    return 0;
}