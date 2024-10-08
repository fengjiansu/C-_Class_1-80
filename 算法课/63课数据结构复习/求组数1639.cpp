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
    int j = 0;

    // 双指针遍历
    for (int i = 0; i < n; ++i) {
        // 更新 j，找到最大的满足 x[j] - x[i] <= k 的位置
        while (j < n && x[j] - x[i] <= k) {
            ++j;
        }
        // 累加满足条件的数对数量
        ans += (j - i - 1);
    }

    cout << ans << endl;
    return 0;
}
