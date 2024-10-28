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
    vector<int> a(n+1);
    vector<int> s(n+1,0);
    vector<int> pre(n+1,0);
    REP(i,1,n+1)
    {
        cin>>a[i];
        s[i] += s[i-1]+(a[i] == 0 ? -1 : 1);
    }
    int res = 0;
    REP(i,1,n+1)
    {
        res = max(res,s[i]-s[pre[i]]);
        pre[i] = s[i];
    }
    
    cout<<res<<endl;

    return 0;
}