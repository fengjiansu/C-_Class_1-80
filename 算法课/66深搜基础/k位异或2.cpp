#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, k;
int max_result = 0;

void dfs(int pos, int selected_bits, int current_a)
{
    // 如果已经选择了 k 位，计算结果

    if (selected_bits == k)
    {
        max_result = max(max_result, current_a);
        return;
    }
    if (pos >= 8)
    {
        return;
    }

    // 不选择当前位
    dfs(pos + 1, selected_bits, current_a);
    // 选择当前位
    dfs(pos + 1, selected_bits + 1, current_a ^ (b & (1 << pos)));
}

int main()
{
    cin >> k;
    cin >> a >> b;

    // 从a和b的二进制位中进行dfs
    dfs(0, 0, a);

    cout << max_result << endl;
    return 0;
}