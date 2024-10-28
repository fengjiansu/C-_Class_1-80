#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

bool check(ll mid,vi &v,ll m)
{
    ll sum = 0;
    ll n = v.size();
    REP(i,0,n)
    {
        if(v[i]>mid) sum+=v[i]-mid;
    }
    return sum>=m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vi v(n);
    REP(i,0,n)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll res = 0;
    ll l = 0,r = v[n-1];
    while(l<=r)
    {
        ll mid = l+(r-l)/2;
        if(check(mid,v, m))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout<<res<<endl;
    return 0;
}
