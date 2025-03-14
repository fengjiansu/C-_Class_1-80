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
int t[1005][1005];
int dp[1005][1005];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool vis[1005][1005];
int n,m;
int f(int x,int y)
{
    if(vis[x][y])return dp[x][y];
    vis[x][y] = 1;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && t[nx][ny]>t[x][y])
        {
            return dp[x][y] = max(dp[x][y],f(nx,ny)+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>t[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j] = 1;
        }
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            res =max(res,f(i,j));
        }
    }
    
    cout<<res<<endl;
    return 0;
}
