/* 
һ�ҵ��Ź�˾�ƻ�����һЩȫ�µ�5G�źŻ�վ��Ŀ���Ǹ���һ�������еĲ���С������֪��������N��С����ÿ��С������״����Ϊһ�������Σ���СΪHi * Wi��

��˾�ƻ���װ�Ļ�վ���źŷ���ǿ�ȿ��Ը��������������ǿ��P��PΪ���������ڵ���ĳС������ϳ��ıߵ�һ�룬����Ϊ���Ը��Ǹ�С����Ϊ�˷�����������л�վ���ź�ǿ�ȱ���һ�¡�

���ڹ�˾ϣ�����æ���㣬���豣֤������K��С�����ܱ�һ����վ���ǣ��źŻ�վ�����õ���С�źŷ���ǿ���Ƕ��٣�

���磬������С�����������С�ֱ���2*3��3*5��5*7��K=2����ǿ��������Ϊ3���ܱ�֤�������ٸ���ǰ����С����

����
��һ�У������ÿո������������N��K��1 �� K �� N �� 10^5������ʾС���������ͻ�վҪ���ǵ�С��������

��������N�У�ÿ�а����ÿո����������������Hi��Wi��1 �� Hi, Wi �� 10^5������ʾ��i��С���������ߵĳ��ȡ�

���
һ����������ʾ�ɱ�֤������K��С�����źŸ��ǵĻ�վ����С�źŷ���ǿ��P��

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ж��ź�ǿ�� p �Ƿ��ܸ������� k ��С��
bool is_covered(int p, const vector<pair<int, int>>& sizes, int k) {
    int count = 0;
    for (const auto& size : sizes) {
        int h = size.first, w = size.second;
        // ֱ�����������㣬���⸡������������
        if (p * 2 >= max(h, w)) {
            count++;
            if (count >= k) { // ��ǰ�����Ż�
                return true;
            }
        }
    }
    return count >= k;
}

int main() {
    // ���봦��
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> sizes(n);
    for (int i = 0; i < n; i++) {
        cin >> sizes[i].first >> sizes[i].second;
    }

    // ���ֲ����ź�ǿ�� P
    int low = 1;
    int high = 0;

    // ���������ܵ��ź�ǿ�ȣ�ÿ��С�������ߵ�һ�룩
    for (const auto& size : sizes) {
        high = max(high, (max(size.first, size.second) + 1) / 2);
    }

    int result = high;

    // ���ֲ���
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_covered(mid, sizes, k)) {
            result = mid;    // ��¼��ǰ���е� P
            high = mid - 1;  // ���Ը�С�� P
        } else {
            low = mid + 1;   // ���Ը���� P
        }
    }

    // ������
    cout << result << endl;

    return 0;
}