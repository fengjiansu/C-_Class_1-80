/* 
(1638)删除数字

输入n个数的序列,然后再输入一个1~n的排列,按照这个排列的顺序删掉原序列中的每一
个数字。每次删数字的时候,我们要加上这个数字的左右两边的数字的代价(注意如果某个
数字被删掉后,它左边和它右边的数字就相连了,如果某一边没有数字就不加),求最后的
代价和为多少?
输入
先输入n,再输入n个非负整数a,第三行输入一个排列,n≤10^6,a≤1000。
输出
输出最后的代价和。
样例输入
4
7413
2314

题目描述

样例输出
21
 */
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

struct Node
{
    int pre;
    int value;
    int next;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<Node> node(n+2); //预留位置
    vector<int> p(n+1);
    vector<int> a(n+1);
    for(int i = 1; i < n+1; i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i < n+1; i++)
    {
        cin>>p[i];
    }
    for(int i = 1; i < n+1; i++)
    {
        node[i].value = a[i];
        node[i].pre = i - 1;
        node[i].next = i + 1;
    }
    ll cost = 0;
    for(int i = 1; i < n+1; i++)
    {
        int pos = p[i];
        if(node[pos].pre >=1)
        {
            cost += node[node[pos].pre].value;
        }
        if(node[pos].next <= n)
        {
            cost += node[node[pos].next].value;
        }
        if(node[pos].pre >=1)
        {
            node[node[pos].pre].next = node[pos].next;
        }
        if(node[pos].next <= n)
        {
            node[node[pos].next].pre = node[pos].pre;
        }
        // 标记节点已删除（可选）
        node[pos].pre = node[pos].next = 0;
    } 
    cout<<cost;  
    return 0;
}
