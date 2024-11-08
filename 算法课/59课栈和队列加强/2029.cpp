#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// 定义操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 计算两个数和一个操作符
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b; // 假设除法为整数除法，且不会出现除以0的情况
    return 0;
}

int evaluate(const string& str) {
    stack<int> num;     // 数字栈
    stack<char> op;       // 操作符栈

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        //if (isspace(ch)) continue; // 跳过空格
        if (isdigit(ch)) {
            // 由于数字都是一位的，直接转换即可
            num.push(ch - '0');
        } else if (ch == '(') {
            op.push(ch);
        } else if (ch == ')') {
            // 处理括号内的表达式
            while (!op.empty() && op.top() != '(') {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char c = op.top(); op.pop();
                num.push(applyOp(a, b, c));
            }
            op.pop(); // 弹出 '('
        } else {
            // 处理操作符，考虑优先级
            while (!op.empty() && precedence(op.top()) >= precedence(ch)) {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char c = op.top(); op.pop();
                num.push(applyOp(a, b, c));
            }
            op.push(ch);
        }
    }

    // 处理剩余的操作符
    while (!op.empty()) {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char oc= op.top(); op.pop();
        num.push(applyOp(a, b,c));
    }

    return num.top();
}

int main() {
    string str;
    getline(cin, str); // 读取整行表达式
    cout << evaluate(str) << endl;
    return 0;
}
