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
1. 按过期时间d排序，d相同的按照p排序
2.把商品用优先级队列存储
3.每次从队首取出过期时间最早的商品和当前日期比较
4.如果过期时间小于等于当前日期，那么这个商品可以购买
错误点:思路二无法动态调整已选商品
不一定过期日期前的要先买
正确思路:
这是一个典型的 贪心算法 问题，类似于 任务调度 问题，其中每个任务都有一个截止时间和一个收益。
我们的目标是在有限的时间内（每天只能卖一件商品），选择一组商品，使得总收益最大，且所有商品都在过期日期之前卖出。
按过期时间排序：将所有商品按照过期时间 从小到大排序，优先处理过期时间早的商品。
1. 按过期时间排序
将所有商品按照它们的过期时间 从小到大排序。
优先考虑过期时间较早的商品，确保这些商品不会因过期而无法销售。

2.使用最小堆（优先队列）：使用一个最小堆（priority_queue），动态维护当前选择的商品利润。
最小堆的性质是堆顶元素是最小的，这样方便我们在需要的时候移除利润最小的商品
3.遍历商品列表：
对于每个商品 将其利润 插入最小堆。
如果最小堆的大小超过了当前商品的过期时间 
则从堆中移除利润最小的商品。这确保了在截至 
天内，只选择利润最大的商品。
当时间（天数）有限时，我们总是优先保留利润更高的商品
计算总利润：遍历完所有商品后，最小堆中的所有利润之和即为最大总收益。
堆的大小代表商品数量 ,商品的d意味着在d天内卖出
 */
struct Node
{
    int p,d;
};
struct Cmp1
{
    bool operator()(Node a,Node b)
    {
        return a.d<b.d;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Node> v(n);
    priority_queue<int,vector<int>,greater<int>> q;
    REP(i,0,n)
    {
        cin>>v[i].p>>v[i].d;
    }
    sort(v.begin(),v.end(),Cmp1());
    for(auto &vi:v) //O(n)
    {
        q.push(vi.p);//(nlogn)
        if(q.size()>vi.d)
        {
            q.pop();
        }

    }
    int res=0;
    while(!q.empty())
    {
        res+=q.top();
        q.pop();
    }

    cout<<res<<endl;
    return 0;
}
