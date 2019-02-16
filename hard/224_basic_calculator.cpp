#include <string>
#include <stack>
#include <iostream>

using namespace std;

struct Parser {
    string s;
    int index;

    Parser(const string& s1) : s(s1), index(0) {}

    // return -1: no, 0: int 1: operator
    int has_next() {
        for (; index < s.length() && s[index] == ' '; ++index) ;
        if (index == s.length())
            return -1;
        return (s[index] >= '0' && s[index] <= '9') ? 0 : 1;
    }

    int next_int() {
        int v = 0;
        for (; index < s.length() && s[index] >= '0' && s[index] <= '9'; ++index)
            v = v * 10 + (s[index] - '0');
        return v;
    }

    char next_op() {
        return s[index++];
    }
};

class Solution {
public:
    int calculate(string s) {
        Parser p(s);
        stack<char> ops;
        stack<int> values;
        while (true) {
            int status = p.has_next();
            if (status == -1)
                break;
            if (status == 0) {
                values.emplace(p.next_int());
                continue;
            }
            char op = p.next_op();
            if (op == '(') {
                ops.emplace(op);
            } else if (op == ')') {
                while (!ops.empty()) {
                    char top = ops.top();
                    ops.pop();
                    if (top == '(')
                        break;
                    calc(top, values);
                }
            } else {
                while (!ops.empty()) {
                    char top = ops.top();
                    if (top == '(')
                        break;
                    ops.pop();
                    calc(top, values);
                }
                ops.emplace(op);
            }
        }
        while (!ops.empty()) {
            char top = ops.top();
            ops.pop();
            calc(top, values);
        }
        return values.top();
    }

private:
    void calc(char op, stack<int>& values) {
        int v2 = values.top();
        values.pop();
        int v1 = values.top();
        values.pop();
        if (op == '+')
            values.emplace(v1 + v2);
        else
            values.emplace(v1 - v2);
    }
};


int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution sln;
    sln.calculate(s);
    return 0;
}
