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
const int MAXN = 1e5 + 10;
int pre[MAXN],nxt[MAXN],val[MAXN];
int b[MAXN],c[MAXN];

/* 
链表存放的节点为结构体类型,
排序 之后要找当i取n时, j只能取1到n-1,
邻值差的计算时 j要小于i
正向思考很麻烦,还要判断j是否满足
逆向思考,当i取n时 , 和它邻接的一定小于n
当这种情况满足后,把该节点删除
当i为n-1时 ,邻接的节点一定小于n-1,
又链表有序则此时只需要判断 该节点前后两个节点的差值即可

 */
struct Node
{
    int id;
    int val;
};

bool cmp1(Node a, Node b)
{
    return a.val < b.val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<Node> a(n+1);
    for (int i = 1; i <=n; i++)
    {
        cin>>a[i].val;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), cmp1);
    // 根据排序后的数组 建立链表,id为链表中节点的编号,val为节点的值
    for (int i = 1; i <= n; i++)
    {
        pre[a[i].id] = i==1?-1:a[i-1].id;
        nxt[a[i].id] = i==n? -1:a[i+1].id;
        val[a[i].id] = a[i].val;
    }
    // 求邻值差时 i从n开始求
    for(int i=n;i>=2;i--)
    {
        int L = pre[i], R = nxt[i]; 
		//cout<<"L: "<<L<<"R: "<<R<<endl;
        int lmin=1e9,rmin = 1e9; // 用于记录最小的邻值差
        if (L != -1) lmin = min(lmin, abs(val[i] - val[L])); // 计算左邻居的邻值差
        if(R!=-1) rmin = min(rmin, abs(val[i] - val[R])); // 计算右邻居的邻值差
        //cout<<"lmin: "<<lmin<<"rmin: "<<rmin<<endl;
        if(lmin<=rmin) // 等于的情况,考虑val小的节点 即左边的节点
        {
            b[i] = lmin;
            c[i] = L;
        }
        else
        {
            b[i] = rmin;
            c[i] = R;
        }
        // 删除节点i
    if (L != -1) nxt[L] = R;
    if (R != -1) pre[R] = L;
    // 将i从链表中移除
    pre[i] = -1;
    nxt[i] = -1;

    }
    for(int i=2;i<=n;i++) cout<<b[i]<<" "<<c[i]<<endl;
    return 0;
}
