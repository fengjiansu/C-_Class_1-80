#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> warehouse;       // ջ�����ڴ�ż�װ�������
    stack<int> max_stack;       // ����ջ�����ڴ�ŵ�ǰջ�е����ֵ

    for (int i = 0; i < N; ++i) {
        int op;
        cin >> op;

        if (op == 0) {
            // ��װ��������
            int weight;
            cin >> weight;
            warehouse.push(weight);
            // �������ջΪ�գ����������ļ�װ��ȵ�ǰ���װ�����������ֵջ
            if (max_stack.empty() || weight >= max_stack.top()) {
                max_stack.push(weight);
            }
        } else if (op == 1) {
            // ��װ��������
            if (!warehouse.empty()) {
                // �������ļ�װ���ǵ�ǰ���ֵ������Ҫͬ����������ջ�е����ֵ
                if (warehouse.top() == max_stack.top()) {
                    max_stack.pop();
                }
                warehouse.pop();
            }
        } else if (op == 2) {
            // ��ѯ��ǰ���װ������
            if (max_stack.empty()) {
                cout << 0 << endl;
            } else {
                cout << max_stack.top() << endl;
            }
        }
    }

    return 0;
}