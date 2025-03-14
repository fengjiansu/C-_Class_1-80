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
const int N = 1e3+5; 

int dp[N][N];  // dp[i][j] 表示从(k,0)出发到(i,j)的最短路径 dp[i] [j]=min(dp[i-1][j],dp[i+1][j],dp[i-1[j]])+a[i][j]
int a[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        dp[i][0]=a[i][0];
    }
    for(int j=1;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i==0) dp[i][j]=min(dp[n-1][j-1],min(dp[i+1][j-1],dp[i][j-1]))+a[i][j];
            else if(i==n-1) dp[i][j]=min(dp[i-1][j-1],min(dp[0][j-1],dp[i][j-1]))+a[i][j];
            else dp[i][j]=min(dp[i-1][j-1],min(dp[i+1][j-1],dp[i][j-1]))+a[i][j];
        }
    }
    int res = INT_MAX;
    for(int i=0;i<n;i++)
    {
        res = min(res,dp[i][m-1]);
    }
    cout<<res;
    return 0;
}
