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

bool check(ll mid,vl v,ll c)
{
    ll cnt = 0;
    REP(i,0,v.size())
    {
        REP(j,i,v.size())
        {
            if(abs(v[j]-v[i])>=mid)
            {
                cnt++;
                if(cnt>=c)
                {
                    return true;
                }
            }
        }
    }
    return cnt>=c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,c;
    cin>>n>>c;
    vl v(n);
    ll maxr = 0;
    REP(i,0,n)
    {
        cin>>v[i];
        maxr = max(maxr,v[i]);
    }
    ll l = 0,r = maxr;
    ll res = 0;
    while(l<=r)
    {
        ll mid = l+(r-l)/2;
        if(check(mid,v,c))
        {
            l = mid+1;
            res = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    cout<<res;
    return 0;
}
