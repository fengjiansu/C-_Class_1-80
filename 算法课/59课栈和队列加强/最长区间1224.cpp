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

/* 
滑动窗口通常是从 左向右遍历 的算法
定义 left 和 right 分别为滑动窗口的左右边界。
滑动窗口是一个 扩展-收缩 的过程，
 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vi a(n);REP(i,0,n)cin>>a[i];
    int l =0;
    int sum = 0,maxl = 0;
    for(int r=0;r<n;r++)
    {
        sum += a[r];//扩展窗口
        //收缩窗口
        while(sum>m)
        {
            sum -= a[l];
            l++;
        }
        maxl = max(maxl,r-l+1);
    }
    cout<<maxl;
    return 0;
}
