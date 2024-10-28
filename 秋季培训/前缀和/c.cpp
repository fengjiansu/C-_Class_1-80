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
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    vector<int> sum(n+1,0);
    REP(i,1,n+1)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int max_r = INT_MIN;
    REP(i,1,n+1-k)
    {
        max_r=max(max_r,sum[i+k]-sum[i-1]);
    }
    cout<<max_r<<endl;
    return 0;
}
