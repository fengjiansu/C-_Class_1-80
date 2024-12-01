#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)

/* void dfs(int u, vector<vector<int>> &tree)
{
    cout << u << " ";
    for (int v : tree[u])
    {l
        dfs(v, tree);
    }
    return;
} */
void dfs(int u, vector<vector<int>> &tree, int current_depth, int &max_depth)
{
    if (current_depth > max_depth)
    {
        max_depth = current_depth; // 更新最大深度
    }
    for (int v : tree[u])
    {
        dfs(v, tree, current_depth + 1, max_depth); // 递归遍历子节点，深度加1
    }
    return;
}

int bfs(int u, vector<vector<int>> &tree)
{
    queue<int> q;
    q.push(u);
    int max_depth = 0;
    while (!q.empty())
    {
        max_depth++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int v = q.front();
            q.pop();

            // 遍历该层所有节点
            for (auto &w : tree[v])
            {
                q.push(w);
            }
        }
    }
    return max_depth;
}
/*
void bfs(int u, vector<vector<int>> &tree)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        //处理节点v 不关心层次信息，只关心子节点
        for (auto  &w : tree[v])
        {
            q.push(w);
        }
    }
}
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    REP(i, 2, n + 1)
    {
        int p;
        cin >> p;
        tree[p].push_back(i); // i的父节点是p
    }
    int max_depth = 0;
    dfs(1, tree, 1, max_depth);
    // 从根节点开始，初始深度为1
    cout << max_depth << "\n";
    return 0;
}
