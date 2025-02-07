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
    int n,m;cin >> n >> m;
    vi a(n),b(m);
    REP(i,0,n) cin >> a[i];
    REP(i,0,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    int j = 0;
    REP(i,0,n)
    {
        while(j < m && b[j] < a[i]) j++;
        if(j < m)
        {
            ans++;
            j++;
        } 
    }
    cout<< ans << endl;
    return 0;
}
