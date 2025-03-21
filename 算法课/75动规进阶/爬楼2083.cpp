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
const int N = 1e5+5;
int a[N];
int dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,b;cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1] = min(a[1],b);
    for(int i=2;i<=n;i++)
    {
        dp[i] = min(dp[i-1]+a[i],min(dp[i-1]+b,dp[i-2]+b));
    }
    cout<<dp[n]<<endl;
    return 0;
}
