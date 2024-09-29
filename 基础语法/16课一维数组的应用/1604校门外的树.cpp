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
int a[1005];
bool f[1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        for(int i = x; i <= y; i++)
        {
            f[i] = true;
        }
    }
    int cnt = 0;
    for(int i = 0; i <= n; i++)
    {
        if(!f[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
