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
const int MAXN = 1e5 + 10; // 根据实际问题调整最大节点数, m , bn
string val[MAXN];
    int nxt[MAXN];
/*

在单循环链表中，最后一个节点的 nxt 不再是 -1，而是指向头节点 head。
插入和删除节点时，需要特殊处理最后一个节点的 nxt 指针，确保链表形成一个环。
 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

     int n,m;
    cin>>n>>m;//输入n、m
    for(int i=1;i<=n;i++)//输入n个人的名字   
    {
    	cin>>val[i];
    }
    for(int i=0;i<n;i++)//初始化
    	nxt[i]=i+1;
	nxt[n]=1;
	int p=0;//从0开始  因为如果k==1的话 p如果从1开始  会把第一个节点跳过,所以第一个节点之前保留一个空位
	for(int i=1;i<=n;i++){//开始模拟出圈过程
		for(int j=0;j<m-1;j++)
			p=nxt[p];//p位置右移
		cout<<val[nxt[p]]<<" ";//输出出圈人的位置
		nxt[p]=nxt[nxt[p]];//删掉出圈人
	}
	return 0;//功德圆满

}
