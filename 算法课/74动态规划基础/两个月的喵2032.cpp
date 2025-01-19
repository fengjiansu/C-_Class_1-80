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
bool vis[N];
int fun(int n)
{
    if(n<0) return 0;
    if(vis[n])      return dp[n];
    vis[n] = true;
    if(n==0)   return dp[n] = 0;
    if(n==1)   return dp[n] = a[1];
    return dp[n]= max(fun(n-1),fun(n-2))+a[n];

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<fun(n);
    return 0;
}
