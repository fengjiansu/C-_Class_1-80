#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// ��������������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ����׺���ʽת��Ϊ��׺���ʽ
string pre(const string& str) {
    string res;
    stack<char> ops;

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        //if (isspace(ch)) continue; // �����ո�

        if (isdigit(ch)) {
            // ���ֶ���һλ�ģ�ֱ��ѹ���׺���ʽ
            res.push_back(ch);
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            // ��������ջ�еĲ��������������� '('
            while (!ops.empty() && ops.top() != '(') {
                res.push_back(ops.top());
                ops.pop();
            }
            ops.pop(); // ���� '('
        } else {
            // ������������������ȼ�
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                res.push_back(ops.top());
                ops.pop();
            }
            ops.push(ch);
        }
    }

    // ��ʣ��Ĳ�����ѹ���׺���ʽ
    while (!ops.empty()) {
        res.push_back( ops.top());
        ops.pop();
    }

    return res;
}

// �����׺���ʽ��ֵ
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
            else if (op == '/') result = a / b; // ���費����ֳ���0�����
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
