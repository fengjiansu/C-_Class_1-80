#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char pre = s[0];
    int max = 1, cnt = 1;
    int res = 0; //最长段数量
    for (int i = 1; i < s.size(); i++)
    {
        if (pre == s[i])
        {
            cnt++;
        }
        else
        {
            if (max < cnt)
            {
                max = cnt;
                res = 1;
            }
            else if (max == cnt)
            {
                res++;
            }
            cnt = 1;
            pre = s[i];
        }
    }
    if (max < cnt)
    {
        max = cnt;
        res = 1;
    }
    else if (max == cnt)
    {
        res++;
    }
    cout << max << " " << res;
    return 0;
}
