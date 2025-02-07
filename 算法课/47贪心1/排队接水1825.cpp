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
struct P
{
    int id,v;
};
bool cmp(P a,P b)
{
    if(a.v==b.v) return a.id<b.id;
    return a.v<b.v;
}
P p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        p[i].id=i;
        cin>>p[i].v;
    }
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        cout<<p[i].id<<" ";
    }
    cout<<"\n";
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        sum += p[i].v*(n-i);
    }
    cout<<fixed<<setprecision(2)<<sum/n<<"\n";

    return 0;
}
