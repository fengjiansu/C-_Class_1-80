#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> heights(10);
    int maxReach;

    // ������Ʒ�߶�
    for (int i = 0; i < 10; ++i) {
        cin >> heights[i];
    }

    // �����е��������ָ߶�
    cin >> maxReach;

    // ��е���ڽ���֧�żܺ�����߶�
    int maxTotalReach = maxReach + 30;
    int count = 0;

    // ����������ܹ�ȡ������Ʒ����
    for (int height : heights) {
        if (height <= maxTotalReach) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}