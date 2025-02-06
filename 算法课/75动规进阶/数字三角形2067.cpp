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
const int N=1e3+5;
int dp[N][N];
int a[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
    dp[1][1]=a[1][1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
    int ans=0;
    for(int i = 1; i <= n; i++)
        ans=max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}
