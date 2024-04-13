#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

double f2(string str) {
    char c;
    int x;
    int x1, x2;
    stringstream st;
    st << str;
    stack<int> s;

    st >> c;
    while (st) {
    if (isdigit(c)) {
        st.putback(c);
        st >> x;
        s.push(x);
    } else {
        x1 = s.top();
        switch (c) {
        case '+':
            s.pop();
            x2 = s.top();
            s.pop();
            s.push(x1 + x2);
            break;
        case '-':
            s.pop();
            x2 = s.top();
            s.pop();
            s.push(x2 - x1);
            break;
        case '*':
            s.pop();
            x2 = s.top();
            s.pop();
            s.push(x2 * x1);
            break;
        case '/':
            s.pop();
            x2 = s.top();
            s.pop();
            s.push(x2 / x1);
            break;
        default:
            break;
        }
    }
    st >> c;
}
return s.top();
}

string f1(string s) {
    string output_s;
    stringstream st;
    st << s;
    stack <char> oper;
    char c;
    int x;
    st >> c;
    while (st) {
        if (isdigit(c)) {
            st.putback(c);
            st >> x;
            output_s = output_s + " " +to_string(x);
        }
        else {
            switch (c)
            {
            case '(':
                oper.push(c);
                break;
            case ')':
                while (oper.top() != '(') {
                    output_s = output_s + " " + oper.top();
                    oper.pop();
                }
                oper.pop();
                break;
            case '*':
            case '/':
                while (!oper.empty() && oper.top() != '(' && oper.top() != '+' && oper.top()  != '-') {
                    output_s = output_s + " " + oper.top();
                    oper.pop();
                }
                oper.push(c);
                break;
            case '+':
            case '-':
                while (!oper.empty() && oper.top() != '(') {
                    output_s = output_s + " " + oper.top();
                    oper.pop();
                }
                oper.push(c);
                break;
            default:
                break;
            }
        }
        st >> c;
    }
    while (!oper.empty()) {
        output_s = output_s + " " + oper.top();
        oper.pop();
    }
    return output_s;
}

double calc(string s) {
    return f2(f1(s));
}

int main() {
    cout << calc("5 + 4 * 2 / (1 - 5)");
}