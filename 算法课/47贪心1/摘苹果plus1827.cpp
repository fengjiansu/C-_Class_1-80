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
    int n,s;cin>>n>>s;
    int a,b;cin>>a>>b;
    vi x,y;
    REP(i,1,n+1)
    {
        int x1,y1;
        cin>>x1>>y1;
        if(x1<=a+b)
        {   
            x.push_back(x1);
            y.push_back(y1);
        }
    }
    sort(y.begin(),y.end());
    int ans = 0;
    for(int i=0;i<y.size();i++)
    {
        if(y[i]<=s)
        {
            ans++;
            s-=y[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
