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
    int n,d,p;
    cin>>n>>d>>p;
    vector<ll> f(n);
    REP(i,0,n)
    {
        cin>>f[i];
    }
    sort(f.begin(),f.end());
    int day = n-1;
    int cnt = 0;
    bool flag = false;
    int dn = 0;
    while(day>=0)
    {
        
    }
    ll lei = 0;
    REP(i,0,d)
    {
        lei += f[day];
        day--;
    }
    if(lei<p) flag = true;
    ll r = 0;
    cout<<day<<endl;
    REP(i,0,day)
    {
        r += f[i];
    }
    if(flag) r += p;
    cout<<r;
    return 0;
}
