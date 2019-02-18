#include <string>
#include <stack>

using namespace std;

enum ParserStatus {
    NO,
    INT,
    OP
};

struct Parser {
    string s;
    int id;

    Parser(string s1): s(s1), id(0) {}

    ParserStatus has_next() {
        for (; id < s.length() && s[id] == ' '; ++id) ;
        if (id == s.length())
            return NO;
        else if (s[id] >= '0' && s[id] <= '9')
            return INT;
        else
            return OP;
    }

    int next_int() {
        int ret = 0;
        for (; id < s.length() && s[id] >= '0' && s[id] <= '9'; ++id)
            ret = (s[id] - '0') + ret * 10;
        return ret;
    }

    char next_op() {
        return s[id++];
    }
};

class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> values;
        Parser parser(s);
        while (true) {
            ParserStatus status = parser.has_next();
            if (status == NO)
                break;
            if (status == INT) {
                values.emplace(parser.next_int());
                continue;
            }
            char op = parser.next_op();
            if (ops.empty()) {
                ops.emplace(op);
                continue;
            }
            char top = ops.top();
            if (op == '*' || op == '/') {
                if (top == '*' || top == '/') 
                    calc(ops, values);
            } else {
                while (!ops.empty())
                    calc(ops, values);
            }
            ops.emplace(op);
        }
        while (!ops.empty())
            calc(ops, values);
        return values.top();
    }

private:
    void calc(stack<char>& ops, stack<int>& values) {
        char top = ops.top();
        ops.pop();
        int v2 = values.top();
        values.pop();
        int v1 = values.top();
        values.pop();
        if (top == '+')
            values.emplace(v1 + v2);
        else if (top == '-')
            values.emplace(v1 - v2);
        else if (top == '*')
            values.emplace(v1 * v2);
        else
            values.emplace(v1 / v2);
    }
};
