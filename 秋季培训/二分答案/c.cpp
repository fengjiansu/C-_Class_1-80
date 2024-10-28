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
bool check(int mid,vi &v,int m)
{
    int last = 0,sum = 0;
    int n = v.size();
    REP(i,1,n)
    {
        if(v[i]-v[last]>mid)
        {
            sum ++;
        }
        else
        {
            last = i;
        }
    }
    return sum>=m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l,n,m;
    cin>>l>>n>>m;
    vector<int> a(n+2);
    a[0] = 1;
    a[n+1] = n;
    REP(i,1,n+1)
    {
        cin>>a[i];
    }
    int l = 1,r=l-1;
    int res = 0;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(check(mid,a,m))
        {
            l = mid+1;
            res = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    
    
    cout<<res<<endl;

    return 0;
}
