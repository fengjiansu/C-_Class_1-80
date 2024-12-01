#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count_substr(const string &s, int k)
{
    int n = s.size(), l = 0, cnt = 0;long long res = 0;
    vector<int> freq(26, 0); // 记录每个字母的频率
    /*
    扩展右边界 r：
每次将 s[r] 加入窗口，更新 freq 和 cnt。
收缩左边界 l：
当 cnt >= k 时，收缩左边界，直到窗口不满足条件。
同时，计算以 r 为右端点的所有满足条件的子串数量。
     */
    for (int r = 0; r < n; r++)
    {
        if (freq[s[r] - 'a']++ == 0)
            cnt++; // 增加新字母

        while (cnt >= k)
        {                       // 如果符合条件
            res += n - r;       // 所有以 r 为右端点的子串都满足
            freq[s[l] - 'a']--; // 移除左边界字符
            if (freq[s[l] - 'a'] == 0)
                cnt--; // 如果移除后种类数减少
            l++;       // 缩小左边界
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        int k;
        cin >> s >> k;
        cout << count_substr(s, k) << endl;
    }
    return 0;
}
