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
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> s(n+1,0);
    ll sum = 0;
    REP(i,0,n)
    {
        cin>>a[i];
        s[i+1]=s[i]+a[i];
    }
    REP(i,2,n+1)
    {
        if(s[i]>0)
        {
        sum+=s[i];
        }
    }
    cout<<sum;
    return 0;
}
