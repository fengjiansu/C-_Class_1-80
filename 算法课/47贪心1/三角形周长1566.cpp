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
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=3;i--)
    {
        if(a[i]<a[i-1]+a[i-2])
        {
            cout<<a[i]+a[i-1]+a[i-2]<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
