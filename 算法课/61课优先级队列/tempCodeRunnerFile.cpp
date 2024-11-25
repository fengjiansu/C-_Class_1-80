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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
class Solution {
public:
    ll nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        unordered_set<ll> seen;
        priority_queue<ll, vector<ll>, greater<ll>> heap;
        seen.insert(1L);
        heap.push(1L);
        ll ugly = 0;
        for (int i = 0; i < n; i++) {
            ll curr = heap.top();
            heap.pop();
            ugly = curr;
            for (int factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout<<s.nthUglyNumber(1500);
    return 0;
}
