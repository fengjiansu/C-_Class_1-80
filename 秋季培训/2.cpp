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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,res = 0;
    cin>>n>>m;
    multiset<ll> a;
    vi b(m,0);
    REP(i,0,n)
    {
        int t;
        cin>>t;
        a.insert(t);
    }
    REP(i,0,m)
    {
        cin>>b[i];
    }
    for(auto &bi:b)
    {
        if(a.count(bi))
        {
            res+=bi;
            a.erase(a.find(bi));
        }
        else
        {
            auto it = a.upper_bound(bi);
            if(it!=a.end())
            {
                res+=*it;
                a.erase(it);
            }
            else
            {
                res = -1;
                break;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
