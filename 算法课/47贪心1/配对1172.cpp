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
const int N = 1e5 + 5;
int a[N],b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    REP(i,0,n)
    {
        cin>>a[i];
    }
    REP(i,0,n)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(a[i]-b[n-i-1]);
    }
    cout<<ans;
    return 0;
}
