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
n皇后问题
很容易想到 把问题转化为从n*n个格子中选出n个格子
共有C(2N,N)种情况`
对角线 和平行线

因为每行每列各放置1个皇后 ,用 A[x]表示第x行皇后的列的编号
那么就变成了一个全排列问题

主对角线用y-x表示，次对角线用y+x表示
 */
int cnt = 0;
int num = 0;
bool b[20];
void dfs(vi &A, int n)
{
    if (A.size() == n)
    {
        if (num < 3)
        {
            for (int i = 0; i < A.size(); i++)
            {
                cout << A[i]+1 << " ";
            }
            cout << endl;
        }

        cnt++;
        num++;
        return;
    }
    //int x = A.size() ? A.back() + 1 : 1;
    for (int i = 0; i < n; i++)
    {
        /*
        因为是横着遍历的 所以同一行的情况就不用判断
        判断 同一列
        同一主对角线
        同一副对角线
         */
        bool f = false;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] == i || A[j] - j == i - A.size() || A[j] + j ==  i+A.size())
            {
            	f = true;
                break;
                
            }
        }
        if (f)
            continue;
        if(b[i]) continue; // 不需要 因为会去判断每一列不能重复放
        b[i] = true;
        A.push_back(i);
        dfs(A, n);
        A.pop_back();
        b[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi A;
    dfs(A, n);
    cout << cnt;
    return 0;
}
