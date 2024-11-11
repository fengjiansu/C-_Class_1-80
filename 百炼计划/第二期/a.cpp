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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vl a(n);
    REP(i,0,n) cin>>a[i];
    ll s = 0;
    ll res = 0;
    for(int i=n-1;i>=0;i--)
    {
        s += a[i];
        if(s<4)
        {
            res++;
        }
        else
        {
            break;
        }
    }  
    cout<<n-res;  
    return 0;
}
