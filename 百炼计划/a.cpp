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
    int n,a,b;
    cin>>n>>a>>b;
    int x = n/2+1;
    int maxn = max(a,b);
    if(maxn>=x)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
