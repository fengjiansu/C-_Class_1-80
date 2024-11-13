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

int k,a,b;
int res = 0;
bool f[10];
//位运算法
void fun(int n,vector<int> &v)
{
    //v.clear();
    for (int i = 0; i < 8; i++) {
        v.push_back(n % 2);  // 将最低位添加到向量
        n /= 2;
    }
    reverse(v.begin(),v.end());
}

void dfs(int cur,int cnt,vector<int> &va,vector<int> &vb)
{
    if(cnt==k)
    {
        int sum = 0;
        for(int i=0;i<va.size();i++)
        {
            if(f[i])
            {
                sum = sum*2 + (va[i]^vb[i]);//位运算优先级
            }
            else
            {
                sum = sum*2 + va[i];
            }
            
        }
        res = max(res,sum);
        return;
    }
    if(cur>=8)
    {
        return ;
    }
    f[cur] = 1;
    dfs(cur+1,cnt+1,va,vb);
    f[cur] = 0; 
    dfs(cur+1,cnt,va,vb);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
cin>>k>>a>>b;
    vector<int> va,vb;
    fun(a,va);
    fun(b,vb);
    dfs(0,0,va,vb);
    cout<<res<<endl;
    return 0;
}
