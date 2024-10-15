#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> heights(10);
    int maxReach;

    // 输入物品高度
    for (int i = 0; i < 10; ++i) {
        cin >> heights[i];
    }

    // 输入机械臂最大伸手高度
    cin >> maxReach;

    // 机械臂在借助支撑架后的最大高度
    int maxTotalReach = maxReach + 30;
    int count = 0;

    // 计算机器人能够取到的物品数量
    for (int height : heights) {
        if (height <= maxTotalReach) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}