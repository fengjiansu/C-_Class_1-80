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

bool fun(int n,int x,int y)
{
for(int a = 0; a<=n; a++)
{
    double b = (n-a*x)*1.0/y;
    if(b<0) return false;
    int bb = (int)b;
    if(bb == b)
    {
        return true;
    }
}
return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin >> x >> y;
    int ans=0;
    for(int i = 1000; i > 0; i--)
    {
        if(!fun(i,x,y))
        {
            ans = i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
