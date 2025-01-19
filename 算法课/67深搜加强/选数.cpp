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
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)

/*
从n个数字中选出k个数字,类似子集问题,每个数字只能选1次
区别在于 子集是把每个数字都选或者都不选
这道问题是只选择k个数字而且必须选择k个

 */
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int cnt = 0;
bool b[25];
int num = 0;//增量构造法 选中k个元素
int sum=0;
void dfs1(vi &S, int cur, int k) // 增量构造法 不需要A存放结果
{
    if (cur == S.size())
    {
        if (num == k)
        {
            int sum = 0;
            for (int i = 0; i < S.size(); i++)
            {
                if (b[i])
                    sum += S[i];
            }
            if (isPrime(sum))
            {
                /* for(int i=0;i<A.size();i++)
                {
                    cout<<A[i]<<" ";
                }
                cout<<endl; */
                cnt++;
            }
        }

        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        b[cur] = i;
        if(i==1){ num++;sum+=S[cur];}
        dfs1(S, cur + 1, k);
        if(b[cur]==1) {num--;sum -= S[cur];}
        b[cur] = !b[cur];
    }
}

void dfs(vi &S, int cur, int k) // 增量构造法 不需要A存放结果
{
    if (cur == S.size())
    {
        if (num == k)
        {
            /* int sum = 0;
            for (int i = 0; i < S.size(); i++)
            {
                if (b[i])
                    sum += S[i];
            } */
            if (isPrime(sum))
            {
                /* for(int i=0;i<A.size();i++)
                {
                    cout<<A[i]<<" ";
                }
                cout<<endl; */
                cnt++;
            }
        }

        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        b[cur] = i;
        if(i==1) num++;
        dfs(S, cur + 1, k);
        if(b[cur]==1) num--;
        b[cur] = !b[cur];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
/*     dfs(S, 0, k); */
dfs1(S,0,k);
    cout << cnt << endl;
    return 0;
}