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
const int N = 2e3+5;
int dp[N][N];// 第i个手续由第j个人办理的时间
int a[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    REP(i,1,n+1)
    {
        REP(j,1,m+1)
        {
            cin>>a[i][j];
        }
    }
    
    REP(i,1,n+1)
    {
        REP(j,1,m+1)
        {
            int x = j==1?m:j-1;
            dp[i][j]=min(dp[i-1][j],dp[i-1][x])+a[i][j];
        }
    }
    int res=INT_MAX;
    REP(j,1,m+1)
    {
        res = min(res,dp[n][j]);
    }
    cout<<res<<endl;
    return 0;
}
