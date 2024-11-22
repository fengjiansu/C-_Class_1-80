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

const int N = 233334;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vi a(n);REP(i,0,n)cin>>a[i];
    vi a_n(n,0);//数组的值记录该口味在当前窗口中的数量
    int l =0;
    int sum = 0,maxl = 0;
    for(int r=0;r<n;r++)
    {
        int x = a[r];//x为当前口味
        a_n[x] ++;//记录口味x在当前窗口中的数量
        if(a_n[x] == 1)
        {
            sum ++;
        }
        while(sum>m)
        {
            int y = a[l];
            a_n[y] --;
            if(a_n[y] == 0)
            {
                sum --;
            }
            l ++;
        }
        maxl = max(maxl,r-l+1);
    }
    cout<<maxl;
    return 0;
    return 0;
}
