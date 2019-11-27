// arithmetic_parsing.cpp - arithmetic_parsing
// Build: g++ -o arithmetic_parsing arithmetic_parsing.cpp -g -Wall
// Author: liyunteng<li_yunteng@163.com> 18510547821

#include "arithmetic_parsing.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
const static bool debug = 0;

string &
trim(string &s)
{
    if (s.empty()) {
        return s;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

string &
trim_sub(string &s)
{
    if (s.empty()) {
        return s;
    }
    trim(s);
    s.erase(0, 1);
    s.erase(s.length() - 1);
    return s;
}

bool
parser::is_sub(const string &input)
{
    if (input.empty()) {
        return false;
    }
    string s = input;
    trim(s);
    string::size_type len = s.length();
    if (s[0] == prefix && s[len - 1] == suffix) {
        return true;
    }
    return false;
}

bool
parser::find_pair(const string &input, string::size_type start,
                  string::size_type &end)
{
    if (input.empty()) {
        return false;
    }
    string::size_type idx = start, len = input.length();
    stack<string::size_type> idx_stack;
    int level = 0;
    for (; idx < len; idx++) {
        switch (input[idx]) {
        case prefix:
            level++;
            if (debug) {
                cout << "stack [in ]: " << idx << " " << level << endl;
            }
            idx_stack.push(idx);
            break;
        case suffix:
            level--;
            idx_stack.pop();
            if (debug) {
                cout << "stack [out]: " << idx << " " << level << endl;
            }
            if (level == 0) {
                end = idx;
                return true;
            }
            break;
        default:
            break;
        }
    }
    return false;
}

// find sin/cos
bool
parser::find_cs(const string &in, string::size_type idx, string::size_type &end,
                stack<string> &operator_stack, stack<string> &operand_stack,
                bool &valid)
{
    if (in.length() <= 0) {
        return false;
    }
    string s;
    if (in.find("sin", idx) == idx || in.find("cos", idx) == idx) {
        if (!find_pair(in, idx + 3, end)) {
            valid = false;
            return false;
        }
        if (in[idx + 4] == prefix) {
            if (!find_pair(in, idx + 4, end)) {
                valid = false;
                return false;
            }
            if (in.find("sin", idx) == idx) {
                operator_stack.push("sin");
            } else {
                operator_stack.push("cos");
            }
            string s = string(in, idx + 4, end - idx - 3);
            parse_sub(s, valid);
        } else {
            string s = string(in, idx, end - idx + 1);
            operand_stack.push(s);
        }
        end = end + 1;
        return true;
    }
    return false;
}

// eval value, special for sin/cos
float
parser::eval_cs(const string &input)
{
    if (input.empty()) {
        return 0.0;
    }
    string s = input;
    trim(s);

    if (s.find("sin") == 0 || s.find("cos") == 0) {
        string::size_type idx = 0, end = 0;
        idx = s.find(prefix);
        if (idx != s.npos && find_pair(s, idx, end)) {
            string tmp = string(s, idx + 1, end - idx - 1);
            float val  = atof(tmp.c_str());
            if (s.find("sin") == 0) {
                return sin(val);
            } else {
                return cos(val);
            }
        }
    }
    return atof(s.c_str());
}

float
parser::eval(stack<string> &operand_stack, stack<string> &operator_stack)
{
    string op;
    string s;
    float val = 0.0, val0, val1;

    if (debug) {
        stack<string> operand_tmp(operand_stack);
        stack<string> operator_tmp(operator_stack);
        cout << "===operand===" << endl;
        while (!operand_tmp.empty()) {
            s = operand_tmp.top();
            cout << s << endl;
            operand_tmp.pop();
        }

        cout << "===operator===" << endl;
        while (!operator_tmp.empty()) {
            cout << operator_tmp.top() << endl;
            operator_tmp.pop();
        }
    }
    if (!operand_stack.empty()) {
        s   = operand_stack.top();
        val = eval_cs(s.c_str());
    }
    while (!operator_stack.empty()) {
        op = operator_stack.top();
        operator_stack.pop();

        if (op == "sin") {
            if (!operand_stack.empty()) {
                s = operand_stack.top();
                operand_stack.pop();
                val1 = eval_cs(s.c_str());
            } else if (!val_stack.empty()) {
                val1 = val_stack.top();
                val_stack.pop();
            } else {
                val1 = 0.0;
            }
            val = sin(val1);
            val_stack.push(val);

        } else if (op == "cos") {
            if (!operand_stack.empty()) {
                s = operand_stack.top();
                operand_stack.pop();
                val1 = eval_cs(s.c_str());
            } else if (!val_stack.empty()) {
                val1 = val_stack.top();
                val_stack.pop();
            } else {
                val1 = 0.0;
            }
            val = cos(val1);
            val_stack.push(val);

        } else {
            if (!operand_stack.empty()) {
                s = operand_stack.top();
                operand_stack.pop();
                val1 = eval_cs(s.c_str());
            } else if (!val_stack.empty()) {
                val1 = val_stack.top();
                val_stack.pop();
            } else {
                val1 = 0.0;
            }

            if (!operand_stack.empty()) {
                s = operand_stack.top();
                operand_stack.pop();
                val0 = eval_cs(s.c_str());
            } else if (!val_stack.empty()) {
                val0 = val_stack.top();
                val_stack.pop();
            } else {
                val0 = 0.0;
            }

            if (op == "+") {
                val = (val0 + val1);
            } else if (op == "-") {
                val = (val0 - val1);
            } else if (op == "*") {
                val = (val0 * val1);
            } else if (op == "/") {
                val = (val0 / val1);
            } else if (op == "sin") {
                val = sin(val1);
            } else if (op == "cos") {
                val = cos(val1);
            }
        }
        if (debug) {
            cout << val0 << " " << op << " " << val1 << " = " << val << endl;
        }
        // operand_stack.push(to_string(val));
    }
    val_stack.push(val);
    return val;
}

float
parser::parse_sub(const string &input, bool &valid)
{
    string in = input;
    trim(in);
    string::size_type idx = 0, end = 0;
    std::stack<std::string> operator_stack;
    std::stack<std::string> operand_stack;
    valid = true;

    if (debug) {
        cout << "input: " << input << endl;
    }
    if (is_sub(in)) {
        trim_sub(in);
        string s;

        if (in[idx] == prefix) {
            if (!find_pair(in, idx, end)) {
                valid = false;
                return 0.0;
            }
            s   = string(in, idx, end - idx + 1);
            idx = end + 1;
            parse_sub(s, valid);
            if (!valid) {
                return 0.0;
            }
        } else if (find_cs(in, idx, end, operator_stack, operand_stack,
                           valid)) {
            if (!valid) {
                return 0.0;
            }
            idx = end;
        } else {
            while (isdigit(in[idx]) || in[idx] == '.') {
                idx++;
            }
            s = string(in, 0, idx);
            trim(s);
            if (!s.empty()) {
                operand_stack.push(s);
            }
        }

        while (in[idx] == ' ') {
            idx++;
        }

        switch (in[idx]) {
        case '+':
        case '-':
        case '*':
        case '/':
            s = string(in, idx, 1);
            operator_stack.push(s);
            idx++;
            break;
        }

        while (in[idx] == ' ') {
            idx++;
        }

        if (in[idx] == prefix) {
            if (!find_pair(in, idx, end)) {
                valid = false;
                return 0.0;
            }
            s = string(in, idx, end - idx + 1);
            parse_sub(s, valid);
            if (!valid) {
                return 0.0;
            }

        } else if (find_cs(in, idx, end, operator_stack, operand_stack,
                           valid)) {
            if (!valid) {
                return 0.0;
            }
            idx = end;
        } else {
            end = idx;
            while (isdigit(in[end]) || in[end] == '.') {
                end++;
            }
            if (end != in.length()) {
                valid = false;
                return 0.0;
            }
            s = string(in, idx, in.length() - idx);
            trim(s);
            if (!s.empty()) {
                operand_stack.push(s);
            }
        }
    } else {
        if (find_cs(in, idx, end, operator_stack, operand_stack, valid)) {
            if (!valid) {
                return 0.0;
            }
            idx = end;
        } else {
            while (isdigit(in[idx]) || in[idx] == '.' || in[idx] == '-') {
                idx++;
            }
            if (idx != in.length()) {
                valid = false;
                return 0.0;
            }
            string s = string(in, 0, idx);
            trim(s);
            if (!s.empty()) {
                operand_stack.push(s);
            }
            // operand_stack.push(in);
        }
    }

    if (debug) {
        cout << "---------------------------------" << endl;
    }
    valid = true;
    return eval(operand_stack, operator_stack);
}

float
parser::parse(const string &input)
{
    if (input.empty()) {
        return 0.0;
    }

    bool valid;
    float a = parse_sub(input, valid);
    if (!valid) {
        cout << "!!INVALID!! ";
    }
    while (!val_stack.empty()) {
        val_stack.pop();
    }
    return a;
}

int
main(void)
{
    const string inputs[] = {
        "",
        "()",
        "1+2.0",  // !!! ivalid !!!
        "-3",
        "cos((1-2.5))",
        "sin(-2.5)",
        "(1/2)",
        "(1+sin(-2.5))",
        "(((1+2)*(4-3))/(1+2.5))",
        "((1 + 1) * ((3 + 4) + cos(6)))",
        "(((1-2)*(3-4))/((5-7)/cos(3)))",
        "(((sin(1) + cos(2)) + sin(3)) * cos(4))",
        "(sin(1) + ((cos(2) + sin(3)) * cos(4)))",
        "(((1+cos(2.5)) * (2 + 1.1)) + (2 * 3.3))",
        "((1+sin(0)) * (3.0 + (4 * 5)))",
    };

    cout << showpoint << fixed << setprecision(2) << boolalpha;

    parser p;
    for (auto s : inputs) {
        float r = p.parse(s);
        cout << s << " =  " << r << endl;
    }

    // cout << 1+2.0 << endl;
    // cout << -3.0 << endl;
    // cout << cos(1-2.5) << endl;
    // cout << sin(-2.5) << endl;
    // cout << 1.0/2 << endl;
    // cout << 1+sin(-2.5) << endl;
    // cout << (((1+2)*(4-3))/(1+2.5)) << endl;
    // cout << ((1 + 1) * ((3 + 4) + cos(6))) << endl;
    // cout << (((1-2)*(3-4))/((5-7)/cos(3))) << endl;
    // cout << (((sin(1) + cos(2)) + sin(3)) * cos(4)) << endl;
    // cout << (sin(1) + ((cos(2) + sin(3)) * cos(4))) << endl;
    // cout << (((1+cos(2.5)) * (2 + 1.1)) + (2 * 3.3)) << endl;
    // cout << ((1+sin(0)) * (3.0 + (4 * 5))) << endl;

    return 0;
}
