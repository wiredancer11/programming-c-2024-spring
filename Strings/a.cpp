#include <iostream>
#include <string>

using namespace std;

bool is_ip_addr(string s) {
    int i, n;
    int start = 0;
    string sub_s;
    for (int j = 0; j < 4; j++) {
        if (j < 3) {
            i = s.find_first_of('.');
            if (i == string::npos) return false;
        } else i = string::npos;
        sub_s = s.substr(0, i);
        if (sub_s.empty() || sub_s.find_first_not_of("0123456789") != string::npos) return false;
        n = stoi(sub_s);
        if (n < 0 || n > 255) {
            return false;
        }
        s.erase(0, i+1);
    }
    return true;
}

string highlight_found(string s, string sub_s) {
    string result="";
    int i;
    int size = sub_s.size();
    i = s.find(sub_s);
    while (i != string::npos) {
        result += s.substr(0, i) + "(" + sub_s + ")";
        s.erase(0, i+size);
        i = s.find(sub_s);
    }
    result += s;
    return result;
}

string replace_sums(string s) {
    string sub_s;
    int n1 = 0;
    int n2 = 0;
    bool after_plus = false;
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' > 0 && s[i] - '0' < 10) {
            if (!after_plus) {
                n1 *= 10;
                n1 += (s[i] - '0');
            } else {
                n2 *= 10;
                n2 += (s[i] -'0');
            }
        }
        else if (s[i] == '+') {
            if (n1 > 0) after_plus = true;
            else result += '+';
        }
        else {
            if (n1 > 0) {
                if (!after_plus) {
                    result += to_string(n1);
                } else {
                    if (n2 == 0) {
                        result += to_string(n1) + "+";
                    } else {
                    result += to_string(n1+n2);
                    }
                }
            }
            result += s[i];
            n1 = 0;
            n2 = 0;
            after_plus = false;
        }
    }
    if (n1 > 0) {
        if (!after_plus) {
            result += to_string(n1);
        } else {
            if (n2 == 0) {
                result += to_string(n1) + "+";
            } else {
            result += to_string(n1+n2);
            }
        }
    }
    return result;
}

int main() {
    string s, sub_s;
    cout << replace_sums("5+26-72+35gh32+45");
    return EXIT_SUCCESS;;
};