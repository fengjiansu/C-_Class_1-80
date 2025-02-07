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

struct item{
    int w,v;
    double p;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    vector<item> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].w>>a[i].v;
        a[i].p=1.0*a[i].v/a[i].w;
    }
    sort(a.begin(),a.end(),[](item a,item b){return a.p>b.p;});
    double ans=0;
    for(int i=0;i<n;i++)
    {
        if(t>=a[i].w)
        {
            t-=a[i].w;
            ans+=a[i].v;
        }
        else
        {
            ans+=t*a[i].p;
            break;
        }
    }
    //保留两位小数
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
