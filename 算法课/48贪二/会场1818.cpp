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

struct node
{
    int a,b;
    bool operator < (const node &x) const
    {
        return b<x.b;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<node> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i].a >> v[i].b;
    }
    sort(v.begin(),v.end());
    int ans = 0;
    int last = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].a>=last)
        {
            ans++;
            last = v[i].b;
        }
    }
    cout<<ans<<endl;
    return 0;
}
