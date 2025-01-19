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

vector<vector<int>> tree;
vector<int> parent,dep;
int max_depth = 1;
void dfs(int root,int depth)
{
    dep[root] = depth;
    max_depth = max(max_depth, depth);
    if(tree[root].empty()) return;
    if (tree[root].size() > 0) dfs(tree[root][0], depth + 1); // 左子节点
    if (tree[root].size() > 1) dfs(tree[root][1], depth + 1); // 右子节点
}

int max_breadth = 1;
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        max_breadth = max(max_breadth,size);
        for(int i=0;i<size;i++)
        {
            int u = q.front();
            q.pop();
            for(auto &v:tree[u])
            {
                q.push(v);
            }
        }
    }
}


int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    while (dep[u] > dep[v]) u = parent[u];
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

 int getd(int u, int v)
{
    int lcaNode = lca(u,v);
    return (dep[u]-dep[lcaNode])*2+(dep[v]-dep[lcaNode]);
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    tree.resize(n+1);
    parent.resize(n+1,-1);
    dep.resize(n+1,1);
    int a,b;
    REP(i,1,n)
    {
        
        cin>>a>>b;
        tree[a].PB(b);
        parent[b] = a;
    }
    
    dfs(1,1);
    bfs(1);
    cout<<max_depth<<endl<<max_breadth<<endl;
    int x,y;
    cin >> x >> y;
    cout<<getd(x,y)<<endl;
	/* int ans = 0;
	int path = 2;
	if(dep[y] > dep[x])
	{
		swap(x, y);
		path = 1;

	}
	while(dep[x] > dep[y])
	{
		x = parent[x];
		ans += path;
	}//x节点沿父节点向上直到与y同一深度
	while(x != y)
	{
		x = parent[x];
		y = parent[y];
		ans += 3;
	}//x、y一同向上直到相遇
	cout << ans << endl;//输出x、y的距离 */
    return 0;
}