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

void update_diff(int l, int r,ll d,vector<ll> &diff)
{
    diff[l] += d;
    if(r+1 < diff.size())
    {
        diff[r+1] -= d;
    }
}

ll get_diff(int l, int r,vector<ll> &sum)
{
    return sum[r]-sum[l-1];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ll> a(n+1,0);
    vector<ll> diff(n+2,0);// 多加一位，防止越界
    vector<ll> sum(n+1,0);
    REP(i,1,n+1) 
    {
        cin>>a[i];
        diff[i] = a[i] - a[i-1];
    }
    int t,l,r,d;
    REP(i,0,q)
    {
        cin>>t;
        
        if(t==1)
        {
            cin>>l>>r>>d;
            update_diff(l,r,d,diff);
        }
        else
        {
            cin>>l>>r;
            REP(i,1,n+1)
            {
                a[i] = a[i-1] + diff[i];
            }
             // 重新计算前缀和数组 sum
            sum[0] = 0;
            REP(i,1,n+1)
            {
                sum[i] = a[i] + sum[i-1]; 
            }
            cout<<get_diff(l,r,sum)<<endl;
        }
        
    }
    return 0;
}
