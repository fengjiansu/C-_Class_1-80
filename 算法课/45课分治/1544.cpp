/*
题目描述

输入样例
4
1231

(1544)奇怪的比赛

有2”只袋鼠、螃蟹和青蛙一起举办了一场石头剪刀布比赛。这是一场奇怪的比赛,因为袋鼠只会出石头,
螃蟹只会出剪刀,而青蛙只会出布。为了让比赛结果有悬念,现在他们会打乱所有人的顺序,打乱后编号
为1~2n,然后开始比赛。比赛采用淘汰赛:
1.先1号和2号比赛,3号和4号比赛,…
2.1号和2号的胜者与3号和4号的胜者比赛,5号和6号的胜者与7号和8号的胜者比赛,…
一直到冠军出现。
如果比赛的两个动物是同一种动物,那么我们规定编号大的获胜。
输入
第一行输入2”,第二行2个数,1代表是袋鼠,2代表是螃蟹,3代表是青蛙。n≤13。
输出
输出胜者的编号
输出样例
3



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
#define REP(i, a, b) for (int i = a; i < b; i++)

int match(vi &v, int a, int b)
{
    // 石头胜剪刀、剪刀胜布、布胜石头
    if ((v[a] == 1 && v[b] == 2) || // 石头胜剪刀
        (v[a] == 2 && v[b] == 3) || // 剪刀胜布
        (v[a] == 3 && v[b] == 1))
    { // 布胜石头
        return a;
    }
    else if (v[a] == v[b])
    {
        // 同类动物比赛，编号大的获胜
        return max(a, b);
    }
    else
    {
        return b;
    }
}

// 找出获胜者
int win(vi &v, int l, int r)
{
    if (l == r)
    {
        return l; // 当只有一个参赛者时，直接返回其编号
    }
    int mid = l + (r - l) / 2;
    int winnerLeft = win(v, l, mid);            // 左半区胜者
    int winnerRight = win(v, mid + 1, r);       // 右半区胜者
    return match(v, winnerLeft, winnerRight); // 两个胜者对决，返回最终胜者
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v(n + 1);
    REP(i, 1, n + 1) // 使用1到2n的编号
    {
        cin >> v[i];
    }
    cout << win(v, 1, n);
    return 0;
}
