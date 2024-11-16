
/* 葫芦娃，葫芦娃，一根藤上好多朵花！现在葫芦娃已经找到了爷爷，轮到爷爷开始找葫芦娃啦！（想不到吧，我也想不到 

现在有一棵n个节点的树,节点编号为1?n,根节点为1号节点。用以下输入方式给定这一棵树
第一行输入n,
表示树的节点个数,第二行用空格分隔输入n?1个正整数，分别表示2?n号节点的父节点的编号。 
接下来再第3行输入一个数字q表示接下来有q个询问，每个询问输入一个1?n整数之间的整数，需要你输出这个节点的子节点个数，然后按照编号从小到大输出这个节点的子节点。
n,q≤1000 */

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

 int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<set<int>> tree(n+1);
    int p;
    REP(i,2,n+1)
    {
        cin>>p;
        tree[p].insert(i);//i的父节点是p
    }
    int q;
    cin>>q;
    int a;
    while(q--)
    {
        cin>>a;
        cout<<tree[a].size()<<"\n";
        //set<int>::iterator it;
    /*     for(auto i=tree[a].begin();i!=tree[a].end();i++)
        {
            cout<<*i<<" ";
        } */ 
         
        for (auto &it : tree[a])
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

 int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    int p;
    REP(i,2,n+1)
    {
        cin>>p;
        tree[p].push_back(i);//i的父节点是p
    }
    int q;
    cin>>q;
    int a;
    while(q--)
    {
        cin>>a;
        cout<<tree[a].size()<<"\n";
        sort(tree[a].begin(),tree[a].end());
        for(int i=0;i<tree[a].size();i++)
        {
            cout<<tree[a][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
