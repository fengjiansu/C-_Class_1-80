#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, k;
int max_result = 0;

void dfs(int pos, int selected_bits, int current_a)
{
    // ����Ѿ�ѡ���� k λ��������

    if (selected_bits == k)
    {
        max_result = max(max_result, current_a);
        return;
    }
    if (pos >= 8)
    {
        return;
    }

    // ��ѡ��ǰλ
    dfs(pos + 1, selected_bits, current_a);
    // ѡ��ǰλ
    dfs(pos + 1, selected_bits + 1, current_a ^ (b & (1 << pos)));
}

int main()
{
    cin >> k;
    cin >> a >> b;

    // ��a��b�Ķ�����λ�н���dfs
    dfs(0, 0, a);

    cout << max_result << endl;
    return 0;
}