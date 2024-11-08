#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// ��������������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ������������һ��������
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b; // �������Ϊ�����������Ҳ�����ֳ���0�����
    return 0;
}

int evaluate(const string& str) {
    stack<int> num;     // ����ջ
    stack<char> op;       // ������ջ

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        //if (isspace(ch)) continue; // �����ո�
        if (isdigit(ch)) {
            // �������ֶ���һλ�ģ�ֱ��ת������
            num.push(ch - '0');
        } else if (ch == '(') {
            op.push(ch);
        } else if (ch == ')') {
            // ���������ڵı��ʽ
            while (!op.empty() && op.top() != '(') {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char c = op.top(); op.pop();
                num.push(applyOp(a, b, c));
            }
            op.pop(); // ���� '('
        } else {
            // ������������������ȼ�
            while (!op.empty() && precedence(op.top()) >= precedence(ch)) {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char c = op.top(); op.pop();
                num.push(applyOp(a, b, c));
            }
            op.push(ch);
        }
    }

    // ����ʣ��Ĳ�����
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
    getline(cin, str); // ��ȡ���б��ʽ
    cout << evaluate(str) << endl;
    return 0;
}
