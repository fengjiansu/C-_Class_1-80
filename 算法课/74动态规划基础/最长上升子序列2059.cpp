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
int dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    dp[0]=1;
    int res=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
                res=max(res,dp[i]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
