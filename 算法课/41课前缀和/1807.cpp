#include <bits/stdc++.h>

using namespace std;

long long n, k, a, s[1000005], ans;
int main()
{
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    long long maxa = 0;
    if (k != 0)
    {
        for (int i = 2; i <= n; i++)
        {
            int l = i - k, r = i + k;
            if (l < 1)
                l = 1;
            if (r > n)
                r = n;
            maxa = max(maxa, max(s[i] - s[l], s[r] - s[i]));
        }
    }
    ans = s[n] - maxa;
    cout << ans << endl;
    return 0;
}
