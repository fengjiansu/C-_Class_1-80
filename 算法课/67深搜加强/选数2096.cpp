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
从n个数字中选出k个数字,类似子集问题,每个数字只能选1次
区别在于 子集是把每个数字都选或者都不选
这道问题是只选择k个数字而且必须选择k个 

 */
bool isPrime(int n)
{
    if(n<2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int cnt =0;
void dfs(vi &A,vi & S,int n,int k,int start) //增量构造法
{
    if(A.size()==k)
    {
        int sum =0;
        for(int i=0;i<A.size();i++)
        {
            sum += A[i];
        }
        if(isPrime(sum))
        {
            /* for(int i=0;i<A.size();i++)
            {
                cout<<A[i]<<" ";
            }
            cout<<endl; */
            cnt++;
        }
        return;
    }
    //如果A不为空，那么从A的最后一个元素的下一个开始
    // 这时 S 中元素不是连续的,所以必须引入一个索引变量 
    for(int i=start;i<n;i++)
    {
        A.push_back(S[i]);
        dfs(A,S,n,k,i+1); //每次下一次选择的元素是上一个位置+1
        A.pop_back();
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;cin>>n>>k;
    vi A,S(n);
    for(int i=0;i<n;i++) cin>>S[i];
    dfs(A,S,n,k,0);
    cout<<cnt<<endl;
    return 0;
}
