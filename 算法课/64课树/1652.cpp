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
        max_depth = current_depth; // ����������
    }
    for (int v : tree[u])
    {
        dfs(v, tree, current_depth + 1, max_depth); // �ݹ�����ӽڵ㣬��ȼ�1
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

            // �����ò����нڵ�
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
        //����ڵ�v �����Ĳ����Ϣ��ֻ�����ӽڵ�
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
        tree[p].push_back(i); // i�ĸ��ڵ���p
    }
    int max_depth = 0;
    dfs(1, tree, 1, max_depth);
    // �Ӹ��ڵ㿪ʼ����ʼ���Ϊ1
    cout << max_depth << "\n";
    return 0;
}
