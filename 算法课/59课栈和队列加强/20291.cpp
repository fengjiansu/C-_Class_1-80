#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// 定义操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 将中缀表达式转换为后缀表达式
string pre(const string& str) {
    string res;
    stack<char> ops;

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        //if (isspace(ch)) continue; // 跳过空格

        if (isdigit(ch)) {
            // 数字都是一位的，直接压入后缀表达式
            res.push_back(ch);
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            // 将操作符栈中的操作符弹出到遇到 '('
            while (!ops.empty() && ops.top() != '(') {
                res.push_back(ops.top());
                ops.pop();
            }
            ops.pop(); // 弹出 '('
        } else {
            // 处理操作符，考虑优先级
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                res.push_back(ops.top());
                ops.pop();
            }
            ops.push(ch);
        }
    }

    // 将剩余的操作符压入后缀表达式
    while (!ops.empty()) {
        res.push_back( ops.top());
        ops.pop();
    }

    return res;
}

// 计算后缀表达式的值
int fun(const string& res) {
    stack<int> values;

    for (auto& c : res) {
        if (isdigit(c)) {
            values.push(c - '0');
        } else {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            char op = c;
            int result = 0;
            if (op == '+') result = a + b;
            else if (op == '-') result = a - b;
            else if (op == '*') result = a * b;
            else if (op == '/') result = a / b; // 假设不会出现除以0的情况
            values.push(result);
        }
    }

    return values.top();
}

int main() {
    string str;
    getline(cin, str);

    string res = pre(str);
    int result = fun(res);

    cout << result << endl;

    return 0;
}
