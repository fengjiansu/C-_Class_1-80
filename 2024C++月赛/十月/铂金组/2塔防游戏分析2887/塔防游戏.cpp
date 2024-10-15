#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> warehouse;       // 栈，用于存放集装箱的重量
    stack<int> max_stack;       // 辅助栈，用于存放当前栈中的最大值

    for (int i = 0; i < N; ++i) {
        int op;
        cin >> op;

        if (op == 0) {
            // 集装箱入库操作
            int weight;
            cin >> weight;
            warehouse.push(weight);
            // 如果辅助栈为空，或者新入库的集装箱比当前最大集装箱大，则更新最大值栈
            if (max_stack.empty() || weight >= max_stack.top()) {
                max_stack.push(weight);
            }
        } else if (op == 1) {
            // 集装箱出库操作
            if (!warehouse.empty()) {
                // 如果出库的集装箱是当前最大值，则需要同步弹出辅助栈中的最大值
                if (warehouse.top() == max_stack.top()) {
                    max_stack.pop();
                }
                warehouse.pop();
            }
        } else if (op == 2) {
            // 查询当前最大集装箱重量
            if (max_stack.empty()) {
                cout << 0 << endl;
            } else {
                cout << max_stack.top() << endl;
            }
        }
    }

    return 0;
}