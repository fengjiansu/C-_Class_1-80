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
    vector<int> a(n);
    vector<int> sum(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}
