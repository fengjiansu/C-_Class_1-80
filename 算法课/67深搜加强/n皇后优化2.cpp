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
bool b[20]; // 标记目前皇后所在的列
bool col[20]; // 标记每列是否有皇后
bool d1[40]; // 标记主对角线是否有皇后
bool d2[40]; // 标记副对角线是否有皇后

// 超时 push pop 操作
vi A;
int n;
void dfs( int row)
{
    //这部分没有办法优化
    if (row == n)
    {
        if (num < 3)
        {
            for (int i = 0; i < row; i++)
            {
                cout << A[i]+1 << " ";
            }
            cout << "\n";
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
        // 判断新进入的皇后是否会冲突 从O(n)优化到0(1)
        // 用二维数组 保存每个位置是否可以被放入
        
        
        if (col[i] || d1[i - row + n] || d2[row + i])
            continue;
        
        A[row] = i;
        col[i] = d1[i - row + n] = d2[row + i] = true;
        dfs(row+1);
        col[i] = d1[i - row + n] = d2[row + i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    A.resize(n);
    dfs(0);
    cout << cnt;
    return 0;
}
