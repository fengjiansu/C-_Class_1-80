#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i)
    {
        q.emplace(nums[i], i);
    }
    vector<int> ans = {q.top().first};
    for (int i = k; i < n; ++i)
    {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k)
        {
            q.pop();
        }
        ans.push_back(q.top().first);
    }
    for (auto& i : ans)
        cout << i << " ";
    return 0;
}
