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
const int N = 1e6+5;
int dp[N][N]; // 代表 第i盆花 最多能得到的最大价值 j代表是否选择当前花
int v[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    REP(i,1,n+1) cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = d[i-1][0]+v[i];
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
    return 0;
}
