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

bool check(int mid,vi &v,int k)
{
    int sum = 0;
    int n = v.size();
    REP(i,0,n)
    {
         sum+=v[i]/mid;
    }
    return sum>=k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi v(n,0);
    REP(i,0,n)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l = 1,r = v[n-1];
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
    cout<<res<<endl;
    return 0;
}
