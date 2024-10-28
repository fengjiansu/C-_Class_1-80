#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> x(n);

    // 输入数组
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // 对数组进行排序
    sort(x.begin(), x.end());

    ll ans = 0;
    int l = 0;
    int r = 0;

    // 双指针遍历
    while(l<n&&r<n)
    {
        while(r<n&&x[r]-x[l]<k)
        {
            r++;
        }
        ans += r-l;
        l++;
    }


    cout << ans << endl;
    return 0;
}
