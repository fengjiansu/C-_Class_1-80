#include <bits/stdc++.h>

using namespace std;

int m[10005], w[10005], a, ma;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 1)
            m[i] = 1;
        else
            w[i] = 1;
        m[i] += m[i - 1];
        w[i] += w[i - 1];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (m[j] - m[i] == w[j] - w[i])
            {
                ma = max(ma, m[j] - m[i]);
            }
        }
        
    }
    cout << ma*2 << endl;
    return 0;
}
