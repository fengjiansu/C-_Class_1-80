#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(a,b) for(auto &a:b)

bool check(int mid,vector<pair<int,int>> &v,int k)
{
    int n = v.size();
    int sum = 0;
    REP(i,0,n)
    {
        sum +=(v[i].S/mid)*(v[i].F/mid);
        if (sum >= k) return true;  // 如果已经足够了，提前返回
    }
    return sum>=k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v(n);
    int maxr = 0;
    REP(i,0,n)
    {
        cin>>v[i].F>>v[i].S;
        maxr = max(maxr,v[i].S);
        maxr = max(maxr,v[i].F);
    }
    int l = 1,r = maxr;
    int res = 0;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(check(mid,v,k))
        {
            l = mid+1;
            res = mid;
        }
        else
        {
            r = mid-1;
        }
    }
    cout<<res;
    return 0;
}
